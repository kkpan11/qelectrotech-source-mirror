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
#ifndef QETGRAPHICSHANDLERITEM_H
#define QETGRAPHICSHANDLERITEM_H

#include <QGraphicsObject>
#include <QPen>

/**
	@brief The QetGraphicsHandlerItem class
	This graphics item represents a point,
	destined to be used as an handler,
	for modifie the geometrie of a another graphics item (like shapes).
	The graphics item to be modified,
	must call "installSceneEventFilter"
	of this item with itself for argument,.
	The ghraphics item to be modified,
	need to reimplement "sceneEventFilter"
	for create the modification behavior.
*/
class QetGraphicsHandlerItem : public QGraphicsObject
{
		Q_OBJECT

		Q_PROPERTY(qreal currentSize READ currentSize WRITE setCurrentSize)

	public:
		QetGraphicsHandlerItem(qreal size = 10);
		void setSize(qreal size);
		QRectF boundingRect() const override;
		
		enum { Type = UserType + 1200};
		int type() const override {return Type;}
		
		void setColor(QColor color);


	protected:
		void paint(QPainter *painter,
			   const QStyleOptionGraphicsItem *option,
			   QWidget *widget) override;
		void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
		void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

		qreal currentSize() const {return m_current_size;}
		void setCurrentSize(qreal size);



	private:
		QRectF m_handler_rect,
			   m_br;
		qreal m_current_size;
		qreal m_original_size;
		QColor m_color;
		QPen m_pen;
		
	public:
		static QVector<QetGraphicsHandlerItem *> handlerForPoint(
				const QVector<QPointF> &points, int size = 10);
};

#endif // QETGRAPHICSHANDLERITEM_H
