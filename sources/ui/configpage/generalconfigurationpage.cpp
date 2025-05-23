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
#include "generalconfigurationpage.h"

#include "../../qetapp.h"
#include "../../qeticons.h"
#include "ui_generalconfigurationpage.h"
#include "../../utils/qetsettings.h"

#include <QFileDialog>
#include <QFontDialog>
#include <QSettings>

/**
	@brief GeneralConfigurationPage::GeneralConfigurationPage
	@param parent
*/
GeneralConfigurationPage::GeneralConfigurationPage(QWidget *parent) :
	ConfigPage(parent),
	ui(new Ui::GeneralConfigurationPage)
{
	ui->setupUi(this);
	
	QSettings settings;
	
		//Appearance tab
#if QT_VERSION < QT_VERSION_CHECK(5, 14, 0) // ###Qt 6:remove
	ui->m_hdpi_round_policy_widget->setDisabled(true);
#else
	ui->m_hdpi_round_policy_cb->addItem(tr("Arrondi supérieur pour 0.5 et plus"), QLatin1String("Round"));
	ui->m_hdpi_round_policy_cb->addItem(tr("Toujours arrondi supérieur"), QLatin1String("Ceil"));
	ui->m_hdpi_round_policy_cb->addItem(tr("Toujours arrondi inférieur"), QLatin1String("Floor"));
	ui->m_hdpi_round_policy_cb->addItem(tr("Arrondi supérieur pour 0.75 et plus"), QLatin1String("RoundPreferFloor"));
	ui->m_hdpi_round_policy_cb->addItem(tr("Pas d'arrondi"), QLatin1String("PassThrough"));
	switch (QetSettings::hdpiScaleFactorRoundingPolicy()) {
		case Qt::HighDpiScaleFactorRoundingPolicy::Round:
			ui->m_hdpi_round_policy_cb->setCurrentIndex(0);
			break;
		case Qt::HighDpiScaleFactorRoundingPolicy::Ceil:
			ui->m_hdpi_round_policy_cb->setCurrentIndex(1);
			break;
		case Qt::HighDpiScaleFactorRoundingPolicy::Floor:
			ui->m_hdpi_round_policy_cb->setCurrentIndex(2);
			break;
		case Qt::HighDpiScaleFactorRoundingPolicy::RoundPreferFloor:
			ui->m_hdpi_round_policy_cb->setCurrentIndex(3);
			break;
		default:
			ui->m_hdpi_round_policy_cb->setCurrentIndex(4);
			break;
	}
#endif
	ui->DiagramEditor_xGrid_sb->setValue(settings.value("diagrameditor/Xgrid", 10).toInt());
	ui->DiagramEditor_yGrid_sb->setValue(settings.value("diagrameditor/Ygrid", 10).toInt());
	ui->DiagramEditor_xKeyGrid_sb->setValue(settings.value("diagrameditor/key_Xgrid", 10).toInt());
	ui->DiagramEditor_yKeyGrid_sb->setValue(settings.value("diagrameditor/key_Ygrid", 10).toInt());
	ui->DiagramEditor_xKeyGridFine_sb->setValue(settings.value("diagrameditor/key_fine_Xgrid", 1).toInt());
	ui->DiagramEditor_yKeyGridFine_sb->setValue(settings.value("diagrameditor/key_fine_Ygrid", 1).toInt());
	ui->DiagramEditor_Grid_PointSize_min_sb->setValue(settings.value("diagrameditor/grid_pointsize_min", 1).toInt());
	ui->DiagramEditor_Grid_PointSize_max_sb->setValue(settings.value("diagrameditor/grid_pointsize_max", 1).toInt());
	ui->m_use_system_color_cb->setChecked(settings.value("usesystemcolors", "true").toBool());
	bool tabbed = settings.value("diagrameditor/viewmode", "tabbed") == "tabbed";
	if(tabbed)
		ui->m_use_tab_mode_rb->setChecked(true);
	else
		ui->m_use_windows_mode_rb->setChecked(true);
	ui->m_zoom_out_beyond_folio->setChecked(settings.value("diagrameditor/zoom-out-beyond-of-folio", false).toBool());
	ui->m_use_gesture_trackpad->setChecked(settings.value("diagramview/gestures", false).toBool());
	ui->m_save_label_paste->setChecked(settings.value("diagramcommands/erase-label-on-copy", true).toBool());
	ui->m_use_folio_label->setChecked(settings.value("genericpanel/folio", true).toBool());
	ui->m_export_terminal->setChecked(settings.value("nomenclature-exportlist", true).toBool());
	ui->m_border_0->setChecked(settings.value("border-columns_0", false).toBool());
	ui->m_autosave_sb->setValue(settings.value("diagrameditor/autosave-interval", 0).toInt());
	
	QString fontInfos = settings.value("diagramitemfont", "Liberation Sans").toString() + " " +
			settings.value("diagramitemsize", "9").toString() + " (" +
			settings.value("diagramitemstyle", "Regular").toString() + ")";
	ui->m_font_pb->setText(fontInfos);


		//Dynamic element text item
	ui->m_dyn_text_rotation_sb->setValue(settings.value("diagrameditor/dynamic_text_rotation", 0).toInt());
	ui->m_dyn_text_width_sb->setValue(settings.value("diagrameditor/dynamic_text_width", -1).toInt());
	if (settings.contains("diagrameditor/dynamic_text_font"))
	{
		QFont font;
		font.fromString(settings.value("diagrameditor/dynamic_text_font").toString());

		QString fontInfos = font.family() + " " +
				QString::number(font.pointSize()) + " (" +
				font.styleName() + ")";
		ui->m_dyn_text_font_pb->setText(fontInfos);
	} else { ui->m_dyn_text_font_pb->setText("Liberation Sans 9 (Regular)"); }

		//Independent text item
	ui->m_indi_text_rotation_sb->setValue(settings.value("diagrameditor/independent_text_rotation",0).toInt());
	if (settings.contains("diagrameditor/independent_text_font"))
	{
		QFont font;
		font.fromString(settings.value("diagrameditor/independent_text_font").toString());

		QString fontInfos = font.family() + " " +
							QString::number(font.pointSize()) + " (" +
							font.styleName() + ")";
		ui->m_indi_text_font_pb->setText(fontInfos);
	} else { ui->m_indi_text_font_pb->setText("Liberation Sans 9 (Regular)"); }
	
	ui->m_highlight_integrated_elements->setChecked(settings.value("diagrameditor/highlight-integrated-elements", true).toBool());
	ui->m_default_elements_info->setPlainText(settings.value("elementeditor/default-informations", "").toString());
	/*
	  Nombre maximum de primitives affichees par la "liste des parties"
	  Au-dela, un petit message est affiche, indiquant que ce nombre a ete depasse
	  et que la liste ne sera donc pas mise a jour.
	*/
	ui->MaxPartsElementEditorList_sb->setValue(settings.value("elementeditor/max-parts-element-editor-list", 200).toInt());
	ui->ElementEditor_Grid_PointSize_min_sb->setValue(settings.value("elementeditor/grid_pointsize_min", 1).toInt());
	ui->ElementEditor_Grid_PointSize_max_sb->setValue(settings.value("elementeditor/grid_pointsize_max", 1).toInt());

	QString path = settings.value("elements-collections/common-collection-path", "default").toString();
	if (path != "default")
	{
		ui->m_common_elmt_path_cb->blockSignals(true);
		ui->m_common_elmt_path_cb->setCurrentIndex(1);
		ui->m_common_elmt_path_cb->setItemData(1, path, Qt::DisplayRole);
		ui->m_common_elmt_path_cb->blockSignals(false);
	}

	path = settings.value("elements-collections/company-collection-path", "default").toString();
	if (path != "default")
	{
		ui->m_company_elmt_path_cb->blockSignals(true);
		ui->m_company_elmt_path_cb->setCurrentIndex(1);
		ui->m_company_elmt_path_cb->setItemData(1, path, Qt::DisplayRole);
		ui->m_company_elmt_path_cb->blockSignals(false);
	}

	path = settings.value("elements-collections/company-tbt-path", "default").toString();
	if (path != "default")
	{
		ui->m_company_tbt_path_cb->blockSignals(true);
		ui->m_company_tbt_path_cb->setCurrentIndex(1);
		ui->m_company_tbt_path_cb->setItemData(1, path, Qt::DisplayRole);
		ui->m_company_tbt_path_cb->blockSignals(false);
	}

	path = settings.value("elements-collections/custom-collection-path", "default").toString();
	if (path != "default")
	{
		ui->m_custom_elmt_path_cb->blockSignals(true);
		ui->m_custom_elmt_path_cb->setCurrentIndex(1);
		ui->m_custom_elmt_path_cb->setItemData(1, path, Qt::DisplayRole);
		ui->m_custom_elmt_path_cb->blockSignals(false);
	}
	

	path = settings.value("elements-collections/custom-tbt-path", "default").toString();
	if (path != "default")
	{
		ui->m_custom_tbt_path_cb->blockSignals(true);
		ui->m_custom_tbt_path_cb->setCurrentIndex(1);
		ui->m_custom_tbt_path_cb->setItemData(1, path, Qt::DisplayRole);
		ui->m_custom_tbt_path_cb->blockSignals(false);
	}
	
	fillLang();	
}

GeneralConfigurationPage::~GeneralConfigurationPage()
{
	delete ui;
}

/**
	@brief GeneralConfigurationPage::applyConf
	Write all configuration in settings file
*/
void GeneralConfigurationPage::applyConf()
{
	QSettings settings;
	
		//GLOBAL
	bool was_using_system_colors = settings.value("usesystemcolors", "true").toBool();
	bool must_use_system_colors  = ui->m_use_system_color_cb->isChecked();
	settings.setValue("usesystemcolors", must_use_system_colors);
	if (was_using_system_colors != must_use_system_colors) {
		QETApp::instance()->useSystemPalette(must_use_system_colors);
	}
	settings.setValue("border-columns_0",ui->m_border_0->isChecked());
	settings.setValue("lang", ui->m_lang_cb->itemData(ui->m_lang_cb->currentIndex()).toString());

		//hdpi
#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
	QetSettings::setHdpiScaleFactorRoundingPolicy(ui->m_hdpi_round_policy_cb->currentData().toString());
	QGuiApplication::setHighDpiScaleFactorRoundingPolicy(QetSettings::hdpiScaleFactorRoundingPolicy());
#endif

		//ELEMENT EDITOR
	settings.setValue("elementeditor/default-informations", ui->m_default_elements_info->toPlainText());
	settings.setValue("elementeditor/max-parts-element-editor-list", ui->MaxPartsElementEditorList_sb->value());
	settings.setValue("elementeditor/grid_pointsize_min", ui->ElementEditor_Grid_PointSize_min_sb->value());
	settings.setValue("elementeditor/grid_pointsize_max", ui->ElementEditor_Grid_PointSize_max_sb->value());

		//DIAGRAM VIEW
	settings.setValue("diagramview/gestures", ui->m_use_gesture_trackpad->isChecked());

		//DIAGRAM COMMAND
	settings.setValue("diagramcommands/erase-label-on-copy", ui->m_save_label_paste->isChecked());

		//GENERIC PANEL
	settings.setValue("genericpanel/folio",ui->m_use_folio_label->isChecked());

		//NOMENCLATURE
	settings.setValue("nomenclature/terminal-exportlist",ui->m_export_terminal->isChecked());


		//DIAGRAM EDITOR
	QString view_mode = ui->m_use_tab_mode_rb->isChecked() ? "tabbed" : "windowed";
	settings.setValue("diagrameditor/viewmode", view_mode) ;
	settings.setValue("diagrameditor/highlight-integrated-elements", ui->m_highlight_integrated_elements->isChecked());
	settings.setValue("diagrameditor/zoom-out-beyond-of-folio", ui->m_zoom_out_beyond_folio->isChecked());
	settings.setValue("diagrameditor/autosave-interval", ui->m_autosave_sb->value());
		//Grid step and key navigation
	settings.setValue("diagrameditor/Xgrid", ui->DiagramEditor_xGrid_sb->value());
	settings.setValue("diagrameditor/Ygrid", ui->DiagramEditor_yGrid_sb->value());
	settings.setValue("diagrameditor/key_Xgrid", ui->DiagramEditor_xKeyGrid_sb->value());
	settings.setValue("diagrameditor/key_Ygrid", ui->DiagramEditor_yKeyGrid_sb->value());
	settings.setValue("diagrameditor/key_fine_Xgrid", ui->DiagramEditor_xKeyGridFine_sb->value());
	settings.setValue("diagrameditor/key_fine_Ygrid", ui->DiagramEditor_yKeyGridFine_sb->value());
	settings.setValue("diagrameditor/grid_pointsize_min", ui->DiagramEditor_Grid_PointSize_min_sb->value());
	settings.setValue("diagrameditor/grid_pointsize_max", ui->DiagramEditor_Grid_PointSize_max_sb->value());
		//Dynamic text item
	settings.setValue("diagrameditor/dynamic_text_rotation", ui->m_dyn_text_rotation_sb->value());
	settings.setValue("diagrameditor/dynamic_text_width", ui->m_dyn_text_width_sb->value());
		//Independent text item
	settings.setValue("diagrameditor/independent_text_rotation", ui->m_indi_text_rotation_sb->value());

		//ELEMENTS COLLECTION
	QString path = settings.value("elements-collections/common-collection-path").toString();
	if (ui->m_common_elmt_path_cb->currentIndex() == 1)
	{
		QString path = ui->m_common_elmt_path_cb->currentText();
		QDir dir(path);
		settings.setValue("elements-collections/common-collection-path",
						  dir.exists() ? path : "default");
	}
	else {
		settings.setValue("elements-collections/common-collection-path", "default");
	}
	if (path != settings.value("elements-collections/common-collection-path").toString()) {
		QETApp::resetCollectionsPath();
	}

	path = settings.value("elements-collections/company-collection-path").toString();
	if (ui->m_company_elmt_path_cb->currentIndex() == 1)
	{
		QString path = ui->m_company_elmt_path_cb->currentText();
		QDir dir(path);
		settings.setValue("elements-collections/company-collection-path",
						  dir.exists() ? path : "default");
	}
	else {
		settings.setValue("elements-collections/company-collection-path", "default");
	}
	if (path != settings.value("elements-collections/company-collection-path").toString()) {
		QETApp::resetCollectionsPath();
	}

	path = settings.value("elements-collections/custom-collection-path").toString();
	if (ui->m_custom_elmt_path_cb->currentIndex() == 1)
	{
		QString path = ui->m_custom_elmt_path_cb->currentText();
		QDir dir(path);
		settings.setValue("elements-collections/custom-collection-path",
						  dir.exists() ? path : "default");
	}
	else {
		settings.setValue("elements-collections/custom-collection-path", "default");
	}
	if (path != settings.value("elements-collections/custom-collection-path").toString()) {
		QETApp::resetCollectionsPath();
	}
	
	path = settings.value("elements-collections/company-tbt-path").toString();
	if (ui->m_company_tbt_path_cb->currentIndex() == 1)
	{
		QString path = ui->m_company_tbt_path_cb->currentText();
		QDir dir(path);
		settings.setValue("elements-collections/company-tbt-path",
						  dir.exists() ? path : "default");
	}
	else {
		settings.setValue("elements-collections/company-tbt-path", "default");
	}
	if (path != settings.value("elements-collections/company-tbt-path").toString()) {
		QETApp::resetCollectionsPath();
	}

	path = settings.value("elements-collections/custom-tbt-path").toString();
	if (ui->m_custom_tbt_path_cb->currentIndex() == 1)
	{
		QString path = ui->m_custom_tbt_path_cb->currentText();
		QDir dir(path);
		settings.setValue("elements-collections/custom-tbt-path",
						  dir.exists() ? path : "default");
	}
	else {
		settings.setValue("elements-collections/custom-tbt-path", "default");
	}
	if (path != settings.value("elements-collections/custom-tbt-path").toString()) {
		QETApp::resetCollectionsPath();
	}
}

/**
	@brief GeneralConfigurationPage::title
	@return The title of this page
*/
QString GeneralConfigurationPage::title() const
{
	return(tr("Général", "configuration page title"));
}

/**
	@brief GeneralConfigurationPage::icon
	@return The icon of this page
*/
QIcon GeneralConfigurationPage::icon() const
{
	return(QET::Icons::Settings);
}

/**
	@brief GeneralConfigurationPage::fillLang
	fill all available lang
*/
void GeneralConfigurationPage::fillLang()
{
	ui->m_lang_cb->addItem(QET::Icons::translation,	tr("Système"), "system");
	ui->m_lang_cb->insertSeparator(1);

		// all lang available on lang directory
	ui->m_lang_cb->addItem(QET::Icons::sa,		tr("Arabe"), "ar");
	ui->m_lang_cb->addItem(QET::Icons::br,		tr("Brézilien"), "pt_BR");
	ui->m_lang_cb->addItem(QET::Icons::catalonia,	tr("Catalan"), "ca");
	ui->m_lang_cb->addItem(QET::Icons::cs,		tr("Tchèque"), "cs");
	ui->m_lang_cb->addItem(QET::Icons::de,		tr("Allemand"), "de");
	ui->m_lang_cb->addItem(QET::Icons::da,		tr("Danois"), "da");
	ui->m_lang_cb->addItem(QET::Icons::gr,		tr("Grec"), "el");
	ui->m_lang_cb->addItem(QET::Icons::en,		tr("Anglais"), "en");
	ui->m_lang_cb->addItem(QET::Icons::es,		tr("Espagnol"), "es");
	ui->m_lang_cb->addItem(QET::Icons::fr,		tr("Français"), "fr");
	ui->m_lang_cb->addItem(QET::Icons::hr,		tr("Croate"), "hr");
	ui->m_lang_cb->addItem(QET::Icons::it,		tr("Italien"), "it");
	ui->m_lang_cb->addItem(QET::Icons::jp,		tr("Japonais"), "ja");
	ui->m_lang_cb->addItem(QET::Icons::pl,		tr("Polonais"), "pl");
	ui->m_lang_cb->addItem(QET::Icons::pt,		tr("Portugais"), "pt");
	ui->m_lang_cb->addItem(QET::Icons::ro,		tr("Roumains"), "ro");
	ui->m_lang_cb->addItem(QET::Icons::ru,		tr("Russe"), "ru");
	ui->m_lang_cb->addItem(QET::Icons::sl,		tr("Slovène"), "sl");
	ui->m_lang_cb->addItem(QET::Icons::nl,		tr("Pays-Bas"), "nl");
	ui->m_lang_cb->addItem(QET::Icons::no,		tr("Norvege"), "nb");
	ui->m_lang_cb->addItem(QET::Icons::nl_BE,	tr("Belgique-Flemish"), "nl_BE");
	ui->m_lang_cb->addItem(QET::Icons::tr,		tr("Turc"), "tr");
	ui->m_lang_cb->addItem(QET::Icons::hu,		tr("Hongrois"), "hu");
	ui->m_lang_cb->addItem(QET::Icons::mn,		tr("Mongol"), "mn");
	ui->m_lang_cb->addItem(QET::Icons::uk,      tr("Ukrainien"), "uk");
	ui->m_lang_cb->addItem(QET::Icons::zh,      tr("Chinois"), "zh");
	ui->m_lang_cb->addItem(QET::Icons::se,      tr("Suédois"), "sv");
		//set current index to the lang found in setting file
		//if lang doesn't exist set to system
	QSettings settings;
	for (int i=0; i<ui->m_lang_cb->count(); i++)
	{
		if (ui->m_lang_cb->itemData(i).toString() == settings.value("lang").toString())
		{
			ui->m_lang_cb->setCurrentIndex(i);
			return;
		}
	}
	ui->m_lang_cb->setCurrentIndex(0);
}

/**
	@brief GeneralConfigurationPage::on_m_font_pb_clicked
	Apply font to config
*/
void GeneralConfigurationPage::on_m_font_pb_clicked()
{
	bool ok;
	QSettings settings;
	QFont curFont = QFont(settings.value("diagramitemfont", "Liberation Sans").toString());
	curFont.setPointSizeF(settings.value("diagramitemsize", "9").toInt());
	curFont.setStyleName (settings.value("diagramitemstyle", "Regular").toString());
	QFont font = QFontDialog::getFont(&ok, curFont, this);
	if (ok)
	{
		settings.setValue("diagramitemfont", font.family());
		settings.setValue("diagramitemsize", font.pointSize());
		settings.setValue("diagramitemweight", font.weight());
		settings.setValue("diagramitemstyle", font.styleName());
		QString fontInfos = settings.value("diagramitemfont").toString() + " " +
				settings.value("diagramitemsize").toString() + " (" +
				settings.value("diagramitemstyle").toString() + ")";
		ui->m_font_pb->setText(fontInfos);
	}
}

/**
	@brief GeneralConfigurationPage::m_dyn_text_font_pb_clicked
	 Apply font to config
*/
void GeneralConfigurationPage::on_m_dyn_text_font_pb_clicked()
{
	bool ok;
	QSettings settings;
	QFont curFont;
	curFont.fromString(settings.value("diagrameditor/dynamic_text_font", "Liberation Sans,9,-1,5,50,0,0,0,0,0,Regular").toString());
	QFont font = QFontDialog::getFont(&ok, curFont, this);
	if (ok)
	{
		settings.setValue("diagrameditor/dynamic_text_font", font.toString());
		QString fontInfos = font.family() + " " +
							QString::number(font.pointSize()) + " (" +
							font.styleName() + ")";
		ui->m_dyn_text_font_pb->setText(fontInfos);
	}
}




void GeneralConfigurationPage::on_m_common_elmt_path_cb_currentIndexChanged(int index)
{
	if (index == 1)
	{
		QString path = QFileDialog::getExistingDirectory(this, tr("Chemin de la collection commune"), QETApp::documentDir());
		if (!path.isEmpty()) {
			ui->m_common_elmt_path_cb->setItemData(1, path, Qt::DisplayRole);
		}
		else {
			ui->m_common_elmt_path_cb->setCurrentIndex(0);
		}
	}
}

void GeneralConfigurationPage::on_m_company_elmt_path_cb_currentIndexChanged(int index)
{
	if (index == 1)
	{
		QString path = QFileDialog::getExistingDirectory(this, tr("Chemin de la collection company"), QETApp::documentDir());
		if (!path.isEmpty()) {
			ui->m_company_elmt_path_cb->setItemData(1, path, Qt::DisplayRole);
		}
		else {
			ui->m_company_elmt_path_cb->setCurrentIndex(0);
		}
	}
}

void GeneralConfigurationPage::on_m_custom_elmt_path_cb_currentIndexChanged(int index)
{
	if (index == 1)
	{
		QString path = QFileDialog::getExistingDirectory(this, tr("Chemin de la collection utilisateur"), QETApp::documentDir());
		if (!path.isEmpty()) {
			ui->m_custom_elmt_path_cb->setItemData(1, path, Qt::DisplayRole);
		}
		else {
			ui->m_custom_elmt_path_cb->setCurrentIndex(0);
		}
	}
}

void GeneralConfigurationPage::on_m_company_tbt_path_cb_currentIndexChanged(int index)
{
	if (index == 1)
	{
		QString path = QFileDialog::getExistingDirectory(this, tr("Chemin des cartouches company"), QETApp::documentDir());
		if (!path.isEmpty()) {
			ui->m_company_tbt_path_cb->setItemData(1, path, Qt::DisplayRole);
		}
		else {
			ui->m_company_tbt_path_cb->setCurrentIndex(0);
		}
	}
}

void GeneralConfigurationPage::on_m_custom_tbt_path_cb_currentIndexChanged(int index)
{
	if (index == 1)
	{
		QString path = QFileDialog::getExistingDirectory(this, tr("Chemin des cartouches utilisateur"), QETApp::documentDir());
		if (!path.isEmpty()) {
			ui->m_custom_tbt_path_cb->setItemData(1, path, Qt::DisplayRole);
		}
		else {
			ui->m_custom_tbt_path_cb->setCurrentIndex(0);
		}
	}
}


void GeneralConfigurationPage::on_m_indi_text_font_pb_clicked()
{
	bool ok;
	QSettings settings;
	QFont curFont;
	curFont.fromString(settings.value("diagrameditor/independent_text_font", "Liberation Sans,9,-1,5,50,0,0,0,0,0,Regular").toString());
	QFont font = QFontDialog::getFont(&ok, curFont, this);
	if (ok)
	{
		settings.setValue("diagrameditor/independent_text_font", font.toString());
		QString fontInfos = font.family() + " " +
							QString::number(font.pointSize()) + " (" +
							font.styleName() + ")";
		ui->m_indi_text_font_pb->setText(fontInfos);
	}
}

void GeneralConfigurationPage::on_MaxPartsElementEditorList_sb_valueChanged(int value)
{
	if (value > 500) {
		ui->MaxPartsElementEditorList_sb->setToolTip(tr("To high values might lead to crashes of the application."));
		ui->MaxPartsElementEditorList_sb->setStyleSheet("background-color: orange");
	} else {
		ui->MaxPartsElementEditorList_sb->setToolTip("");
		ui->MaxPartsElementEditorList_sb->setStyleSheet("");
	}
}

/**
	@brief GeneralConfigurationPage::on_DiagramEditor_Grid_PointSize_min_sb_valueChanged
	the min-value of the max-SpinBox has to be limited:
	may not be smaller than current value of min-SpinBox
	@param value - the new value of the min-SpinBox
 */
void GeneralConfigurationPage::on_DiagramEditor_Grid_PointSize_min_sb_valueChanged(int value)
{
	ui->DiagramEditor_Grid_PointSize_max_sb->setMinimum(std::max(1, value));
}

/**
	@brief GeneralConfigurationPage::on_ElementEditor_Grid_PointSize_min_sb_valueChanged
	the min-value of the max-SpinBox has to be limited:
	may not be smaller than current value of min-SpinBox
	@param value - the new value of the min-SpinBox
 */
void GeneralConfigurationPage::on_ElementEditor_Grid_PointSize_min_sb_valueChanged(int value)
{
	ui->ElementEditor_Grid_PointSize_max_sb->setMinimum(std::max(1, value));
}
