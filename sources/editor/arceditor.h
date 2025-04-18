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
#ifndef ARC_EDITOR_H
#define ARC_EDITOR_H

#include "elementitemeditor.h"

class PartArc;
class StyleEditor;
class QDoubleSpinBox;
class QSpinBox;

/**
	This class provides a widget to edit elliptical arcs within the element editor.
*/
class ArcEditor : public ElementItemEditor
{
	Q_OBJECT

		// constructors, destructor
	public:
		ArcEditor(QETElementEditor *, PartArc * = nullptr, QWidget * = nullptr);
		~ArcEditor() override;
	private:
		ArcEditor(const ArcEditor &);
	
		// attributes
	private:
		PartArc *m_part;
		StyleEditor *m_style;
		QDoubleSpinBox *x, *y, *h, *v;
		QSpinBox *angle, *start_angle;
		bool m_locked;

		QList <QMetaObject::Connection> m_change_connections;
	
		// methods
	public:
		bool setPart(CustomElementPart *) override;
		bool setParts(QList <CustomElementPart *> parts) override;
		CustomElementPart *currentPart() const override;
		QList<CustomElementPart*> currentParts() const override;
	
	public slots:
		void updateArcS();
		void updateArcA();
		void updateForm() override;
		void updateRect();
	
	private:
		void activeConnections(bool);
		/**
			@brief setUpChangeConnections
			Setup the connection from the arc(s) to the widget,
			to update it when the arc(s) are changed (moved ...)
		*/
		void setUpChangeConnections();
		void disconnectChangeConnections();
};
#endif
