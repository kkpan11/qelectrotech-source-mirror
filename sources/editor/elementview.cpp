/*
	Copyright 2006-2025 The QElectroTech Team
	This file is part of QElectroTech.

	QElectroTech is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.

	QElectroTech is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with QElectroTech.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "elementview.h"

#include "../qetapp.h"
#include "UndoCommand/pastepartscommand.h"
#include "ui/qetelementeditor.h"
/**
	Constructeur
	@param scene ElementScene visualisee par cette ElementView
	@param parent QWidget parent de cette ElementView
*/
ElementView::ElementView(ElementScene *scene, QWidget *parent) :
	QGraphicsView(scene, parent),
	m_scene(scene),
	offset_paste_count_(0)
{
	grabGesture(Qt::PinchGesture);
	setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	setInteractive(true);
	setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setResizeAnchor(QGraphicsView::AnchorUnderMouse);
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	zoomReset();
	connect(m_scene, SIGNAL(pasteAreaDefined(const QRectF &)), this, SLOT(pasteAreaDefined(const QRectF &)));
	connect(m_scene, SIGNAL(needZoomFit()), this, SLOT(zoomFit()));
}

/// Destructeur
ElementView::~ElementView()
{
}

/// @return l'ElementScene visualisee par cette ElementView
ElementScene *ElementView::scene() const
{
	return(m_scene);
}

/**
	@return le rectangle de l'element visualise par cet ElementView
*/
QRectF ElementView::viewedSceneRect() const
{
	// recupere la taille du widget viewport
	QSize viewport_size = viewport() -> size();

	// recupere la transformation viewport -> scene
	QTransform view_to_scene   = viewportTransform().inverted();

	// mappe le coin superieur gauche et le coin inferieur droit de la viewport sur la scene
	QPointF scene_left_top     = view_to_scene.map(QPointF(0.0, 0.0));
	QPointF scene_right_bottom = view_to_scene.map(QPointF(viewport_size.width(), viewport_size.height()));

	// en deduit le rectangle visualise par la scene
	return(QRectF(scene_left_top, scene_right_bottom));
}

/**
	Definit l'ElementScene visualisee par cette ElementView
	@param s l'ElementScene visualisee par cette ElementView
*/
void ElementView::setScene(ElementScene *s) {
	QGraphicsView::setScene(s);
	m_scene = s;
}

/**
	Set the Diagram in visualisation mode
*/
void ElementView::setVisualisationMode()
{
	setDragMode(ScrollHandDrag);
	setInteractive(false);
	emit(modeChanged());
}

/**
	Set the Diagram in Selection mode
*/
void ElementView::setSelectionMode()
{
	setDragMode(RubberBandDrag);
	setInteractive(true);
	emit(modeChanged());
}

/**
	Agrandit le schema (+33% = inverse des -25 % de zoomMoins())
*/
void ElementView::zoomIn()
{
	adjustSceneRect();
	scale(4.0/3.0, 4.0/3.0);
}

/**
	Retrecit le schema (-25% = inverse des +33 % de zoomPlus())
*/
void ElementView::zoomOut()
{
	adjustSceneRect();
	scale(0.75, 0.75);
}

/**
	Agrandit le schema avec le trackpad
*/
void ElementView::zoomInSlowly()
{
	scale(1.02, 1.02);
}

/**
	Retrecit le schema avec le trackpad
*/
void ElementView::zoomOutSlowly()
{
	scale(0.98, 0.98);
}

/**
	Agrandit ou rectrecit le schema de facon a ce que tous les elements du
	schema soient visibles a l'ecran. S'il n'y a aucun element sur le schema,
	le zoom est reinitialise
*/
void ElementView::zoomFit()
{
	resetSceneRect();
	fitInView(sceneRect(), Qt::KeepAspectRatio);
}

/**
	Reinitialise le zoom
*/
void ElementView::zoomReset()
{
	resetSceneRect();
	resetTransform();
	scale(4.0, 4.0);
}

/**
	@brief ElementView::adjustSceneRect
	Adjust the scenRect, so that he include all primitives of element
	plus the viewport of the scene with a margin of 1/3 of herself
*/
void ElementView::adjustSceneRect()
{
	QRectF esgr = m_scene -> elementSceneGeometricRect();
	QRectF vpbr = mapToScene(this -> viewport()->rect()).boundingRect();
	QRectF new_scene_rect = vpbr.adjusted(-vpbr.width()/3, -vpbr.height()/3, vpbr.width()/3, vpbr.height()/3);
	setSceneRect(new_scene_rect.united(esgr));
}

/**
	@brief ElementView::resetSceneRect
	reset le sceneRect (zone du schéma visualisée par l'ElementView) afin que
	celui-ci inclut uniquement les primitives de l'élément dessiné.
*/
void ElementView::resetSceneRect()
{
	setSceneRect(m_scene -> elementSceneGeometricRect());
}

/**
	Gere le fait de couper la selection = l'exporter en XML dans le
	presse-papier puis la supprimer.
*/
void ElementView::cut()
{
	// delegue cette action a la scene
	m_scene -> cut();
	offset_paste_count_ = -1;
}

/**
	Gere le fait de copier la selection = l'exporter en XML dans le
	presse-papier.
*/
void ElementView::copy()
{
	// delegue cette action a la scene
	m_scene -> copy();
	offset_paste_count_ = 0;
}

/**
	Gere le fait de coller le contenu du presse-papier = l'importer dans
	l'element. Cette methode examine le contenu du presse-papier. Si celui-ci
	semble avoir ete copie depuis cet element, il est colle a cote de sa zone
	d'origine ; s'il est recolle, il sera colle un cran a cote de la zone deja
	recollee, etc.
	Sinon, cette methode demande a l'utilisateur de definir la zone ou le
	collage devra s'effectuer.
	@see pasteAreaDefined(const QRectF &)
*/
void ElementView::paste()
{
	QString clipboard_text = QApplication::clipboard() -> text();
	if (clipboard_text.isEmpty()) return;

	QDomDocument document_xml;
	if (!document_xml.setContent(clipboard_text)) return;

	if (m_scene -> wasCopiedFromThisElement(clipboard_text)) {
		// copier/coller avec decalage
		pasteWithOffset(document_xml);
	} else {
		// copier/coller par choix de la zone de collage
		QRectF pasted_content_bounding_rect = m_scene -> boundingRectFromXml(document_xml);
		if (pasted_content_bounding_rect.isEmpty()) return;

		to_paste_in_area_ = clipboard_text;
		getPasteArea(pasted_content_bounding_rect);
	}
}

/**
	Colle le contenu du presse-papier en demandant systematiquement a
	l'utilisateur de choisir une zone de collage
*/
void ElementView::pasteInArea()
{
	QString clipboard_text = QApplication::clipboard() -> text();
	if (clipboard_text.isEmpty()) return;

	QDomDocument document_xml;
	if (!document_xml.setContent(clipboard_text)) return;

	QRectF pasted_content_bounding_rect = m_scene -> boundingRectFromXml(document_xml);
	if (pasted_content_bounding_rect.isEmpty()) return;

	// copier/coller par choix de la zone de collage
	to_paste_in_area_ = clipboard_text;
	getPasteArea(pasted_content_bounding_rect);
}

/**
	Gere le fait de coller le contenu du presse-papier = l'importer dans
	l'element. Cette methode examine le contenu du presse-papier. Si celui-ci
	est exploitable, elle le colle a la position passee en parametre.
	@see pasteAreaDefined(const QRectF &)
	@param position Point de collage
*/
ElementContent ElementView::paste(const QPointF &position) {
	QString clipboard_text = QApplication::clipboard() -> text();
	if (clipboard_text.isEmpty()) return(ElementContent());

	QDomDocument document_xml;
	if (!document_xml.setContent(clipboard_text)) return(ElementContent());

	// objet pour recuperer le contenu ajoute au schema par le coller
	return(paste(document_xml, position));
}

/**
	@param to_paste Rectangle englobant les parties a coller
*/
void ElementView::getPasteArea(const QRectF &to_paste) {
	// on copie le rectangle fourni - on s'interesse a ses dimensions, pas a sa position
	QRectF used_rect(to_paste);

	// on lui attribue pour centre l'origine du repere
	if (underMouse()) {
		used_rect.moveCenter(mapToScene(mapFromGlobal(QCursor::pos())));
	} else {
		used_rect.moveCenter(QPointF(0.0, 0.0));
	}
	m_scene -> getPasteArea(used_rect);
}

/**
	Slot appele lorsque la scene annonce avoir defini une zone de collage
	@param target_rect Rectangle cible pour le collage
*/
ElementContent ElementView::pasteAreaDefined(const QRectF &target_rect) {
	if (to_paste_in_area_.isEmpty()) return(ElementContent());

	QDomDocument xml_document;
	if (!xml_document.setContent(to_paste_in_area_)) {
		to_paste_in_area_.clear();
		return(ElementContent());
	} else {
		return(paste(xml_document, target_rect.topLeft()));
	}
}

/**
	Colle le document XML xml_document a la position pos
	@param xml_document Document XML a coller
	@param pos Coin superieur gauche du rectangle cible
*/
ElementContent ElementView::paste(const QDomDocument &xml_document, const QPointF &pos) {
	// object to retrieve content added to the scheme by pasting
	// objet pour recuperer le contenu ajoute au schema par le coller
	ElementContent content_pasted;
	m_scene -> fromXml(xml_document, pos, false, &content_pasted);

	// if something has actually been added to the scheme, an undo object is created
	// si quelque chose a effectivement ete ajoute au schema, on cree un objet d'annulation
	if (content_pasted.count()) {
		m_scene -> clearSelection();
		PastePartsCommand *undo_object = new PastePartsCommand(this, content_pasted);
		m_scene -> undoStack().push(undo_object);
	}
	return(content_pasted);
}

/**
	Paste the XML document "xml_document" at position pos
	Colle le document XML xml_document a la position pos
	@param xml_document Document XML a coller
*/
ElementContent ElementView::pasteWithOffset(const QDomDocument &xml_document) {
	// object to retrieve content added to the scheme by pasting
	// objet pour recuperer le contenu ajoute au schema par le coller
	ElementContent content_pasted;

	// rectangle source
	QRectF pasted_content_bounding_rect = m_scene -> boundingRectFromXml(xml_document);
	if (pasted_content_bounding_rect.isEmpty()) return(content_pasted);

	// ok ... there is something to do for us!
	int initialOffsetX = 10 + (qRound((pasted_content_bounding_rect.width())/10) * 10);

	// paste copied parts with offset
	// copier/coller avec decalage
	QRectF  final_pasted_content_bounding_rect;
	QPointF offset(initialOffsetX, 0);
	++ offset_paste_count_;  // == 0 when selection was cut to clipboard
	// place pasted parts right from copied selection or already pasted parts
	offset.setX(initialOffsetX * offset_paste_count_);
	offset.setY(0);
	final_pasted_content_bounding_rect = pasted_content_bounding_rect.translated(offset);

	start_top_left_corner_ = pasted_content_bounding_rect.topLeft();
	QPointF old_start_top_left_corner = start_top_left_corner_;
	start_top_left_corner_ = final_pasted_content_bounding_rect.topLeft();
	m_scene -> fromXml(xml_document, start_top_left_corner_, false, &content_pasted);

	// if something has actually been added to the scheme, a cancel object is created
	// si quelque chose a effectivement ete ajoute au schema, on cree un objet d'annulation
	if (content_pasted.count()) {
		m_scene -> clearSelection();
		PastePartsCommand *undo_object = new PastePartsCommand(this, content_pasted);
		undo_object -> setOffset(offset_paste_count_ - 1, old_start_top_left_corner, offset_paste_count_, start_top_left_corner_);
		m_scene -> undoStack().push(undo_object);
	}
	return(content_pasted);
}

/**
	Gere les clics sur la vue - permet de coller lorsaue l'on enfonce le bouton
	du milieu de la souris.
	@param e QMouseEvent decrivant l'evenement souris
*/
void ElementView::mousePressEvent(QMouseEvent* e)
{
#if QT_VERSION < QT_VERSION_CHECK(5, 15, 1) // ### Qt 6: remove
	if (e->button() == Qt::MidButton)
#else
#if TODO_LIST
#pragma message("@TODO remove code for QT 6 or later")
#endif
	if (e->button() == Qt::MiddleButton)
#endif
	{
		setCursor( (Qt::ClosedHandCursor));
		reference_view_ = e->pos();
	}
	else
		QGraphicsView::mousePressEvent(e);
}

/**
	@brief ElementView::mouseMoveEvent
	Manage the event move mouse
*/
void ElementView::mouseMoveEvent(QMouseEvent* e)
{
#if QT_VERSION < QT_VERSION_CHECK(5, 15, 1) // ### Qt 6: remove
	if (e->buttons() == Qt::MidButton)
#else
#if TODO_LIST
#pragma message("@TODO remove code for QT 6 or later")
#endif
	if (e->buttons() == Qt::MiddleButton)
#endif
	{
		QScrollBar *h = horizontalScrollBar();
		QScrollBar *v = verticalScrollBar();
		QPointF pos = reference_view_ - e -> pos();
		reference_view_ = e -> pos();
		h -> setValue(h -> value() + pos.x());
		v -> setValue(v -> value() + pos.y());
	}
	else
		QGraphicsView::mouseMoveEvent(e);
}

/**
	@brief ElementView::mouseReleaseEvent
	Manage event release click mouse
*/
void ElementView::mouseReleaseEvent(QMouseEvent* e)
{
#if QT_VERSION < QT_VERSION_CHECK(5, 15, 1) // ### Qt 6: remove
	if (e->button() == Qt::MidButton)
#else
#if TODO_LIST
#pragma message("@TODO remove code for QT 6 or later")
#endif
	if (e->button() == Qt::MiddleButton)
#endif
	{
		setCursor(Qt::ArrowCursor);
		adjustSceneRect();
		return;
	}
	QGraphicsView::mouseReleaseEvent(e);
}

/**
	@brief ElementView::gestures
	@return
*/
bool ElementView::gestures() const
{
	QSettings settings;
	return(settings.value("diagramview/gestures", false).toBool());
}


/**
	@brief ElementView::wheelEvent
	@param e
*/
void ElementView::wheelEvent(QWheelEvent *e) {
	//Zoom and scrolling
	if ( gestures() ) {
		if (e -> modifiers() & Qt::ControlModifier)
			e -> angleDelta().y() > 0 ? zoomInSlowly() : zoomOutSlowly();
		else
			QGraphicsView::wheelEvent(e);
	} else {
		e -> angleDelta().y() > 0 ? zoomIn(): zoomOut();
	}
}

/**
	Gere les evenements de la ElementView
	@param e Evenement
*/
bool ElementView::event(QEvent *e) {
	// By default touch events are converted to mouse events. So
	// after this event we will get a mouse event also but we want
	// to handle touch events as gestures only. So we need this safeguard
	// to block mouse events that are actually generated from touch.
	if (e->type() == QEvent::Gesture)
		return gestureEvent(static_cast<QGestureEvent *>(e));

	return(QGraphicsView::event(e));
}

/**
	Utilise le pincement du trackpad pour zoomer
	Use trackpad pinch to zoom
	@brief ElementView::gestureEvent
	@param event
	@return
*/
bool ElementView::gestureEvent(QGestureEvent *event){
	if (QGesture *gesture = event->gesture(Qt::PinchGesture)) {
		QPinchGesture *pinch = static_cast<QPinchGesture *>(gesture);
		if (pinch->changeFlags() & QPinchGesture::ScaleFactorChanged){
			qreal value = gesture->property("scaleFactor").toReal();
			if (value > 1){
				zoomInSlowly();
			}else{
				zoomOutSlowly();
			}
		}
	}
	return true;
}


/**
	Dessine l'arriere-plan de l'editeur, cad la grille.
	Draws the editor background, i.e. the grid.
	@param p Le QPainter a utiliser pour dessiner
	@param r Le rectangle de la zone a dessiner
*/
void ElementView::drawBackground(QPainter *p, const QRectF &r) {
	p -> save();

	// desactive tout antialiasing, sauf pour le texte
	p -> setRenderHint(QPainter::Antialiasing, false);
	p -> setRenderHint(QPainter::TextAntialiasing, true);
	p -> setRenderHint(QPainter::SmoothPixmapTransform, false);

	// dessine un fond blanc
	// draw a white background
	p -> setPen(Qt::NoPen);
	p -> setBrush(Qt::white);
	p -> drawRect(r);

	// determine le zoom en cours
	// determine the zoom-level
	qreal zoom_factor = transform().m11();

	// choisit la granularite de la grille en fonction du zoom en cours
	// selects the grid granularity according to the current zoom level
	int drawn_x_grid = 1;//scene_ -> xGrid();
	int drawn_y_grid = 1;//scene_ -> yGrid();
	bool draw_grid = true;
	bool draw_cross = false;

	if (zoom_factor < 1.0) { //< no grid
		draw_grid = false;
	} else if (zoom_factor < 4.0) { //< grid 10*10
		drawn_x_grid *= 10;
		drawn_y_grid *= 10;
	}else if (zoom_factor < 8.0) { //< grid 5*5
		drawn_x_grid *= 5;
		drawn_y_grid *= 5;
		draw_cross = true;
	} else if (zoom_factor < 10.0) { //< grid 2*2
		drawn_x_grid *= 2;
		drawn_y_grid *= 2;
		draw_cross = true;
	} else { //< grid 1*1
		draw_cross = true;
	}

	m_scene->setGrid(drawn_x_grid, drawn_y_grid);

	if (draw_grid) {
		// draw the dots of the grid
		QPen pen(Qt::black);
		pen.setCosmetic(true);
		QSettings settings;
		int minWidthPen = settings.value(QStringLiteral("elementeditor/grid_pointsize_min"), 1).toInt();
		int maxWidthPen = settings.value(QStringLiteral("elementeditor/grid_pointsize_max"), 1).toInt();
		pen.setWidth(minWidthPen);
		if (minWidthPen != maxWidthPen) {
			qreal stepPen  = (maxWidthPen - minWidthPen) / (qreal)maxWidthPen;
			qreal stepZoom = (25.0 - 1.0) / maxWidthPen;
			for (int n=0; n<maxWidthPen; n++) {
				if ((zoom_factor > (1.0 + n * stepZoom)) && (zoom_factor <= (1.0 + (n+1) * stepZoom))) {
					int widthPen = minWidthPen + qRound(n * stepPen);
					pen.setWidth(widthPen);
				}
			}
			if		(zoom_factor <= 1.0)
						pen.setWidth(minWidthPen);
			else if (zoom_factor > (1.0 + stepZoom * maxWidthPen))
						pen.setWidth(maxWidthPen);
		}
		p -> setPen(pen);
		p -> setBrush(Qt::NoBrush);
		qreal limit_x = r.x() + r.width();
		qreal limit_y = r.y() + r.height();

		int g_x = (int)ceil(r.x());
		while (g_x % drawn_x_grid) ++ g_x;
		int g_y = (int)ceil(r.y());
		while (g_y % drawn_y_grid) ++ g_y;

		for (int gx = g_x ; gx < limit_x ; gx += drawn_x_grid) {
			for (int gy = g_y ; gy < limit_y ; gy += drawn_y_grid) {
				if (draw_cross) {
					if (!(gx % 10) && !(gy % 10)) {
						p -> drawLine(QLineF(gx - (pen.width()/4.0), gy, gx + (pen.width()/4.0), gy));
						p -> drawLine(QLineF(gx, gy - (pen.width()/4.0), gx, gy + (pen.width()/4.0)));
					} else {
						p -> drawPoint(gx, gy);
					}
				} else {
					p -> drawPoint(gx, gy);
				}
			}
		}
	}
	p -> restore();
}

/**
	@brief ElementView::applyMovement
	Applique le decalage offset dans le sens movement au rectangle start
	@param start :
	rectangle a decaler
	@param offset :
	Decalage a appliquer
	@return
*/
QRectF ElementView::applyMovement(const QRectF &start, const QPointF &offset) {
	// calculates the offset to be applied from the offset
	// calcule le decalage a appliquer a partir de l'offset
	QPointF final_offset;
	final_offset.rx() =  start.width() + offset.x();

	// applies the calculated offset
	// applique le decalage ainsi calcule
	return(start.translated(final_offset));
}
