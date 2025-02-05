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
#ifndef CONDUCTORPROPERTIESWIDGET_H
#define CONDUCTORPROPERTIESWIDGET_H

#include "../conductorproperties.h"

#include <QWidget>
class QTextOrientationSpinBoxWidget;
class QComboBox;
class QPushButton;

namespace Ui {
	class ConductorPropertiesWidget;
}

class ConductorPropertiesWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit ConductorPropertiesWidget(QWidget *parent = nullptr);
		explicit ConductorPropertiesWidget(
			const ConductorProperties &properties,
			QWidget *parent = nullptr);
		~ConductorPropertiesWidget() override;

	//METHODS
		void setProperties(const ConductorProperties &properties);
		ConductorProperties properties() const;
		void setReadOnly(const bool &ro);

		void addAutonumWidget (QWidget *widget);
		void setHiddenOneTextPerFolio   (const bool &hide);
		void setDisabledShowText        (const bool &disable = true);
		void setHiddenAvailableAutonum (const bool &hide);
		QComboBox *autonumComboBox() const;
		QPushButton *editAutonumPushButton() const;

	private:
		void initWidget();
		void setConductorType(ConductorProperties::ConductorType type);

	protected:
		bool event(QEvent *event) override;

	//SLOTS
	public slots:
		void updatePreview(bool b = true);

	private slots:
		void on_m_earth_cb_toggled(bool checked);
		void on_m_neutral_cb_toggled(bool checked);
		void on_m_update_preview_pb_clicked();

	private:
		Ui::ConductorPropertiesWidget *ui;
		ConductorProperties m_properties;
		QTextOrientationSpinBoxWidget *m_verti_select, *m_horiz_select;
};

#endif // CONDUCTORPROPERTIESWIDGET_H
