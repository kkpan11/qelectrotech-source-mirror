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
#ifndef QETSHAPEITEM_H
#define QETSHAPEITEM_H

#include "../QetGraphicsItemModeler/qetgraphicshandleritem.h"
#include "qetgraphicsitem.h"

#include <QPen>

class QDomElement;
class QDomDocument;
class QetGraphicsHandlerItem;
class QAction;

/**
	@brief The QetShapeItem class
	this class is used to draw a basic shape (line, rectangle, ellipse)
	into a diagram, that can be saved to .qet file.
*/
class QetShapeItem : public QetGraphicsItem
{
	Q_OBJECT

	Q_PROPERTY(QPen pen READ pen WRITE setPen NOTIFY penChanged)
	Q_PROPERTY(QBrush brush READ brush WRITE setBrush NOTIFY brushChanged)
	Q_PROPERTY(QRectF rect READ rect WRITE setRect)
	Q_PROPERTY(QLineF line READ line WRITE setLine)
	Q_PROPERTY(QPolygonF polygon READ polygon WRITE setPolygon)
	Q_PROPERTY(bool close READ isClosed WRITE setClosed NOTIFY closeChanged)
	Q_PROPERTY(qreal xRadius READ XRadius WRITE setXRadius NOTIFY XRadiusChanged)
	Q_PROPERTY(qreal yRadius READ YRadius WRITE setYRadius NOTIFY YRadiusChanged)

	signals:
		void penChanged();
		void brushChanged();
		void closeChanged();
		void XRadiusChanged();
		void YRadiusChanged();
		
		
	public:
		enum ShapeType {Line	  =1,
						Rectangle =2,
						Ellipse	  =4,
						Polygon   =8 };
		Q_ENUM (ShapeType)

		enum { Type = UserType + 1008 };

		QetShapeItem(
				QPointF,
				QPointF = QPointF(0,0),
				ShapeType = Line,
				QGraphicsItem *parent = nullptr);
		~QetShapeItem() override;

		//Enable the use of qgraphicsitem_cast to safely cast a
		//QGraphicsItem into a QetShapeItem return the QGraphicsItem type
		int type() const override { return Type; }

			///METHODS
		QPen pen() const {return m_pen;}
		void setPen(const QPen &pen);
		QBrush brush() const {return m_brush;}
		void setBrush(const QBrush &brush);
		ShapeType shapeType() const {return m_shapeType;}

		virtual bool	    fromXml (const QDomElement &);
		virtual QDomElement toXml (QDomDocument &document) const;
		virtual bool toDXF (const QString &filepath,const QPen &pen);

		void editProperty() override;
		QString name() const override;

		void setP2      (const QPointF &P2);
		QLineF line() const{return QLineF(m_P1, m_P2);}
		bool setLine    (const QLineF &line);
		QRectF rect() const{return QRectF(m_P1, m_P2);}
		bool setRect    (const QRectF &rect);
		QPolygonF polygon() const {return m_polygon;}
		bool setPolygon (const QPolygonF &polygon);
		bool isClosed() const {return m_closed;}
		void setClosed (bool close);
		qreal XRadius() const {return m_xRadius;}
		void setXRadius(qreal X);
		qreal YRadius() const {return m_yRadius;}
		void setYRadius(qreal Y);

			//Methods available for polygon shape
		int  pointsCount  () const;
		void setNextPoint (QPointF P);
		void removePoints (int number = 1);

		QRectF boundingRect() const override;
		QPainterPath shape()  const override;

	protected:
		void paint(
				QPainter *painter,
				const QStyleOptionGraphicsItem *option,
				QWidget *widget) override;
		void hoverEnterEvent (QGraphicsSceneHoverEvent *event) override;
		void hoverLeaveEvent (QGraphicsSceneHoverEvent *event) override;
		void mousePressEvent (QGraphicsSceneMouseEvent *event) override;
		QVariant itemChange(
				GraphicsItemChange change,
				const QVariant &value) override;
		bool sceneEventFilter(
				QGraphicsItem *watched,
				QEvent *event) override;
		void contextMenuEvent(
				QGraphicsSceneContextMenuEvent *event) override;

	private:
		void switchResizeMode();
		void addHandler();
		void adjustHandlerPos();
		void insertPoint();
		void removePoint();
		
		void handlerMousePressEvent();
		void handlerMouseMoveEvent(QGraphicsSceneMouseEvent *event);
		void handlerMouseReleaseEvent();

		///ATTRIBUTES
	private:
		ShapeType	 m_shapeType;
		QPen		 m_pen;
		QBrush		 m_brush;
		QPointF		 m_P1,
				 m_P2,
				 m_old_P1,
				 m_old_P2,
				 m_context_menu_pos;
		QPolygonF	 m_polygon, m_old_polygon;
		bool		 m_hovered;
		int		 m_vector_index;
		bool		 m_closed = false,
				 m_modifie_radius_equaly = false;
		int		 m_resize_mode = 1;
		QVector<QetGraphicsHandlerItem *> m_handler_vector;
		QAction		 *m_insert_point,
				 *m_remove_point;
		qreal		 m_xRadius = 0,
				 m_yRadius = 0,
				 m_old_xRadius,
				 m_old_yRadius;
};
#endif // QETSHAPEITEM_H
