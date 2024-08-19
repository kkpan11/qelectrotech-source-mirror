# Copyright 2006 The QElectroTech Team
# This file is part of QElectroTech.
#
# QElectroTech is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# QElectroTech is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with QElectroTech. If not, see <http://www.gnu.org/licenses/>.

message(" - qet_compilation_vars")

set(QET_COMPONENTS
  LinguistTools
  PrintSupport
  Xml
  Svg
  Sql
  Network
  Widgets
  Concurrent)

set(QET_PRIVATE_LIBRARIES
  Qt::PrintSupport
  Qt::Gui
  Qt::Xml
  Qt::Svg
  Qt::Sql
  Qt::Network
  Qt::Widgets
  Qt::Concurrent
  )

set(QET_RES_FILES
  ${QET_DIR}/sources/autoNum/ui/autonumberingdockwidget.ui
  ${QET_DIR}/sources/autoNum/ui/autonumberingmanagementw.ui
  ${QET_DIR}/sources/autoNum/ui/folioautonumbering.ui
  ${QET_DIR}/sources/autoNum/ui/formulaautonumberingw.ui
  ${QET_DIR}/sources/autoNum/ui/numparteditorw.ui
  ${QET_DIR}/sources/autoNum/ui/selectautonumw.ui
  ${QET_DIR}/sources/dataBase/ui/elementquerywidget.ui
  ${QET_DIR}/sources/dataBase/ui/summaryquerywidget.ui
  ${QET_DIR}/sources/editor/ui/dynamictextfieldeditor.ui
  ${QET_DIR}/sources/editor/ui/elementpropertieseditorwidget.ui
  ${QET_DIR}/sources/editor/ui/ellipseeditor.ui
  ${QET_DIR}/sources/editor/ui/lineeditor.ui
  ${QET_DIR}/sources/editor/ui/polygoneditor.ui
  ${QET_DIR}/sources/editor/ui/rectangleeditor.ui
  ${QET_DIR}/sources/editor/ui/qetelementeditor.ui
  ${QET_DIR}/sources/editor/ui/terminaleditor.ui
  ${QET_DIR}/sources/ElementsCollection/ui/renamedialog.ui
  ${QET_DIR}/sources/factory/ui/addtabledialog.ui
  ${QET_DIR}/sources/NameList/ui/namelistdialog.ui
  ${QET_DIR}/sources/NameList/ui/namelistwidget.ui
  ${QET_DIR}/sources/print/projectprintwindow.ui
  ${QET_DIR}/sources/PropertiesEditor/propertieseditordockwidget.ui
  ${QET_DIR}/sources/richtext/addlinkdialog.ui
  ${QET_DIR}/sources/SearchAndReplace/ui/replaceadvanceddialog.ui
  ${QET_DIR}/sources/SearchAndReplace/ui/replaceconductordialog.ui
  ${QET_DIR}/sources/SearchAndReplace/ui/replaceelementdialog.ui
  ${QET_DIR}/sources/SearchAndReplace/ui/replacefoliowidget.ui
  ${QET_DIR}/sources/SearchAndReplace/ui/searchandreplacewidget.ui
  ${QET_DIR}/sources/TerminalStrip/ui/addterminalstripitemdialog.ui
  ${QET_DIR}/sources/TerminalStrip/ui/freeterminaleditor.ui
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripcreatordialog.ui
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripeditor.ui
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripeditorwindow.ui
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstriplayouteditor.ui
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstriptreedockwidget.ui
  ${QET_DIR}/sources/ui/aboutqetdialog.ui
  ${QET_DIR}/sources/ui/alignmenttextdialog.ui
  ${QET_DIR}/sources/ui/bomexportdialog.ui
  ${QET_DIR}/sources/ui/borderpropertieswidget.ui
  ${QET_DIR}/sources/ui/compositetexteditdialog.ui
  ${QET_DIR}/sources/ui/conductorpropertiesdialog.ui
  ${QET_DIR}/sources/ui/conductorpropertieswidget.ui
  ${QET_DIR}/sources/ui/configsaveloaderwidget.ui
  ${QET_DIR}/sources/ui/diagramcontextwidget.ui
  ${QET_DIR}/sources/ui/diagrameditorhandlersizewidget.ui
  ${QET_DIR}/sources/ui/diagramselection.ui
  ${QET_DIR}/sources/ui/dialogwaiting.ui
  ${QET_DIR}/sources/ui/dynamicelementtextitemeditor.ui
  ${QET_DIR}/sources/ui/elementinfopartwidget.ui
  ${QET_DIR}/sources/ui/elementinfowidget.ui
  ${QET_DIR}/sources/ui/formulaassistantdialog.ui
  ${QET_DIR}/sources/ui/imagepropertieswidget.ui
  ${QET_DIR}/sources/ui/importelementdialog.ui
  ${QET_DIR}/sources/ui/importelementtextpatterndialog.ui
  ${QET_DIR}/sources/ui/linksingleelementwidget.ui
  ${QET_DIR}/sources/ui/marginseditdialog.ui
  ${QET_DIR}/sources/ui/masterpropertieswidget.ui
  ${QET_DIR}/sources/ui/multipastedialog.ui
  ${QET_DIR}/sources/ui/potentialselectordialog.ui
  ${QET_DIR}/sources/ui/reportpropertiewidget.ui
  ${QET_DIR}/sources/ui/shapegraphicsitempropertieswidget.ui
  ${QET_DIR}/sources/ui/thirdpartybinaryinstalldialog.ui
  ${QET_DIR}/sources/ui/titleblockpropertieswidget.ui
  ${QET_DIR}/sources/ui/xrefpropertieswidget.ui
  ${QET_DIR}/sources/ui/configpage/generalconfigurationpage.ui
  )
set(QET_SRC_FILES
  ${QET_DIR}/sources/borderproperties.cpp
  ${QET_DIR}/sources/borderproperties.h
  ${QET_DIR}/sources/bordertitleblock.cpp
  ${QET_DIR}/sources/bordertitleblock.h
  ${QET_DIR}/sources/conductorautonumerotation.cpp
  ${QET_DIR}/sources/conductorautonumerotation.h
  ${QET_DIR}/sources/conductornumexport.cpp
  ${QET_DIR}/sources/conductornumexport.h
  ${QET_DIR}/sources/conductorprofile.cpp
  ${QET_DIR}/sources/conductorprofile.h
  ${QET_DIR}/sources/conductorproperties.cpp
  ${QET_DIR}/sources/conductorproperties.h
  ${QET_DIR}/sources/conductorsegment.cpp
  ${QET_DIR}/sources/conductorsegment.h
  ${QET_DIR}/sources/conductorsegmentprofile.h
  ${QET_DIR}/sources/configdialog.cpp
  ${QET_DIR}/sources/configdialog.h
  ${QET_DIR}/sources/createdxf.cpp
  ${QET_DIR}/sources/createdxf.h
  ${QET_DIR}/sources/diagramcommands.cpp
  ${QET_DIR}/sources/diagramcommands.h
  ${QET_DIR}/sources/diagramcontent.cpp
  ${QET_DIR}/sources/diagramcontent.h
  ${QET_DIR}/sources/diagramcontext.cpp
  ${QET_DIR}/sources/diagramcontext.h
  ${QET_DIR}/sources/diagram.cpp
  ${QET_DIR}/sources/diagram.h
  ${QET_DIR}/sources/diagramposition.cpp
  ${QET_DIR}/sources/diagramposition.h
  ${QET_DIR}/sources/diagramview.cpp
  ${QET_DIR}/sources/diagramview.h
  ${QET_DIR}/sources/elementdialog.cpp
  ${QET_DIR}/sources/elementdialog.h
  ${QET_DIR}/sources/elementprovider.cpp
  ${QET_DIR}/sources/elementprovider.h
  ${QET_DIR}/sources/elementscategoryeditor.cpp
  ${QET_DIR}/sources/elementscategoryeditor.h
  ${QET_DIR}/sources/elementscollectioncache.cpp
  ${QET_DIR}/sources/elementscollectioncache.h
  ${QET_DIR}/sources/elementsmover.cpp
  ${QET_DIR}/sources/elementsmover.h
  ${QET_DIR}/sources/elementspanel.cpp
  ${QET_DIR}/sources/elementspanel.h
  ${QET_DIR}/sources/elementspanelwidget.cpp
  ${QET_DIR}/sources/elementspanelwidget.h
  ${QET_DIR}/sources/elementtextpattern.cpp
  ${QET_DIR}/sources/elementtextpattern.h
  ${QET_DIR}/sources/elementtextsmover.cpp
  ${QET_DIR}/sources/elementtextsmover.h
  ${QET_DIR}/sources/exportdialog.cpp
  ${QET_DIR}/sources/exportdialog.h
  ${QET_DIR}/sources/exportproperties.cpp
  ${QET_DIR}/sources/exportproperties.h
  ${QET_DIR}/sources/exportpropertieswidget.cpp
  ${QET_DIR}/sources/exportpropertieswidget.h
  ${QET_DIR}/sources/genericpanel.cpp
  ${QET_DIR}/sources/genericpanel.h
  ${QET_DIR}/sources/machine_info.cpp
  ${QET_DIR}/sources/machine_info.h
  ${QET_DIR}/sources/main.cpp
  ${QET_DIR}/sources/newelementwizard.cpp
  ${QET_DIR}/sources/newelementwizard.h
  ${QET_DIR}/sources/projectview.cpp
  ${QET_DIR}/sources/projectview.h
  ${QET_DIR}/sources/qetapp.cpp
  ${QET_DIR}/sources/qetapp.h
  ${QET_DIR}/sources/qetarguments.cpp
  ${QET_DIR}/sources/qetarguments.h
  ${QET_DIR}/sources/qet.cpp
  ${QET_DIR}/sources/qetdiagrameditor.cpp
  ${QET_DIR}/sources/qetdiagrameditor.h
  ${QET_DIR}/sources/qet.h
  ${QET_DIR}/sources/qeticons.cpp
  ${QET_DIR}/sources/qeticons.h
  ${QET_DIR}/sources/qetinformation.cpp
  ${QET_DIR}/sources/qetinformation.h
  ${QET_DIR}/sources/qetmainwindow.cpp
  ${QET_DIR}/sources/qetmainwindow.h
  ${QET_DIR}/sources/qetmessagebox.cpp
  ${QET_DIR}/sources/qetmessagebox.h
  ${QET_DIR}/sources/qetproject.cpp
  ${QET_DIR}/sources/qetproject.h
  ${QET_DIR}/sources/qetregexpvalidator.cpp
  ${QET_DIR}/sources/qetregexpvalidator.h
  ${QET_DIR}/sources/qetresult.cpp
  ${QET_DIR}/sources/qetresult.h
  ${QET_DIR}/sources/qetxml.cpp
  ${QET_DIR}/sources/qetxml.h
  ${QET_DIR}/sources/qetversion.cpp
  ${QET_DIR}/sources/qetversion.h
  ${QET_DIR}/sources/qfilenameedit.cpp
  ${QET_DIR}/sources/qfilenameedit.h
  ${QET_DIR}/sources/qgimanager.cpp
  ${QET_DIR}/sources/qgimanager.h
  ${QET_DIR}/sources/qtextorientationspinboxwidget.cpp
  ${QET_DIR}/sources/qtextorientationspinboxwidget.h
  ${QET_DIR}/sources/qtextorientationwidget.cpp
  ${QET_DIR}/sources/qtextorientationwidget.h
  ${QET_DIR}/sources/recentfiles.cpp
  ${QET_DIR}/sources/recentfiles.h
  ${QET_DIR}/sources/titleblockcell.cpp
  ${QET_DIR}/sources/titleblockcell.h
  ${QET_DIR}/sources/titleblockproperties.cpp
  ${QET_DIR}/sources/titleblockproperties.h
  ${QET_DIR}/sources/titleblocktemplate.cpp
  ${QET_DIR}/sources/titleblocktemplate.h
  ${QET_DIR}/sources/titleblocktemplaterenderer.cpp
  ${QET_DIR}/sources/titleblocktemplaterenderer.h

  ${QET_DIR}/sources/autoNum/assignvariables.cpp
  ${QET_DIR}/sources/autoNum/assignvariables.h
  ${QET_DIR}/sources/autoNum/numerotationcontextcommands.cpp
  ${QET_DIR}/sources/autoNum/numerotationcontextcommands.h
  ${QET_DIR}/sources/autoNum/numerotationcontext.cpp
  ${QET_DIR}/sources/autoNum/numerotationcontext.h
  ${QET_DIR}/sources/autoNum/ui/autonumberingdockwidget.cpp
  ${QET_DIR}/sources/autoNum/ui/autonumberingdockwidget.h
  ${QET_DIR}/sources/autoNum/ui/autonumberingmanagementw.cpp
  ${QET_DIR}/sources/autoNum/ui/autonumberingmanagementw.h
  ${QET_DIR}/sources/autoNum/ui/folioautonumbering.cpp
  ${QET_DIR}/sources/autoNum/ui/folioautonumbering.h
  ${QET_DIR}/sources/autoNum/ui/formulaautonumberingw.cpp
  ${QET_DIR}/sources/autoNum/ui/formulaautonumberingw.h
  ${QET_DIR}/sources/autoNum/ui/numparteditorw.cpp
  ${QET_DIR}/sources/autoNum/ui/numparteditorw.h
  ${QET_DIR}/sources/autoNum/ui/selectautonumw.cpp
  ${QET_DIR}/sources/autoNum/ui/selectautonumw.h

  ${QET_DIR}/sources/dataBase/projectdatabase.cpp
  ${QET_DIR}/sources/dataBase/projectdatabase.h

  ${QET_DIR}/sources/dataBase/ui/elementquerywidget.cpp
  ${QET_DIR}/sources/dataBase/ui/elementquerywidget.h
  ${QET_DIR}/sources/dataBase/ui/summaryquerywidget.cpp
  ${QET_DIR}/sources/dataBase/ui/summaryquerywidget.h

  ${QET_DIR}/sources/diagramevent/diagrameventaddelement.cpp
  ${QET_DIR}/sources/diagramevent/diagrameventaddelement.h
  ${QET_DIR}/sources/diagramevent/diagrameventaddimage.cpp
  ${QET_DIR}/sources/diagramevent/diagrameventaddimage.h
  ${QET_DIR}/sources/diagramevent/diagrameventaddshape.cpp
  ${QET_DIR}/sources/diagramevent/diagrameventaddshape.h
  ${QET_DIR}/sources/diagramevent/diagrameventaddtext.cpp
  ${QET_DIR}/sources/diagramevent/diagrameventaddtext.h
  ${QET_DIR}/sources/diagramevent/diagrameventinterface.cpp
  ${QET_DIR}/sources/diagramevent/diagrameventinterface.h

  ${QET_DIR}/sources/dvevent/dveventinterface.cpp
  ${QET_DIR}/sources/dvevent/dveventinterface.h

  ${QET_DIR}/sources/dxf/dxftoelmt.cpp
  ${QET_DIR}/sources/dxf/dxftoelmt.h

  ${QET_DIR}/sources/qet_elementscaler/qet_elementscaler.cpp
  ${QET_DIR}/sources/qet_elementscaler/qet_elementscaler.h

  ${QET_DIR}/sources/editor/arceditor.cpp
  ${QET_DIR}/sources/editor/arceditor.h
  ${QET_DIR}/sources/editor/editorcommands.cpp
  ${QET_DIR}/sources/editor/editorcommands.h
  ${QET_DIR}/sources/editor/elementcontent.h
  ${QET_DIR}/sources/editor/elementitemeditor.cpp
  ${QET_DIR}/sources/editor/elementitemeditor.h
  ${QET_DIR}/sources/editor/elementprimitivedecorator.cpp
  ${QET_DIR}/sources/editor/elementprimitivedecorator.h
  ${QET_DIR}/sources/editor/elementscene.cpp
  ${QET_DIR}/sources/editor/elementscene.h
  ${QET_DIR}/sources/editor/elementview.cpp
  ${QET_DIR}/sources/editor/elementview.h
  ${QET_DIR}/sources/editor/styleeditor.cpp
  ${QET_DIR}/sources/editor/styleeditor.h

  ${QET_DIR}/sources/editor/esevent/eseventaddarc.cpp
  ${QET_DIR}/sources/editor/esevent/eseventaddarc.h
  ${QET_DIR}/sources/editor/esevent/eseventadddynamictextfield.cpp
  ${QET_DIR}/sources/editor/esevent/eseventadddynamictextfield.h
  ${QET_DIR}/sources/editor/esevent/eseventaddellipse.cpp
  ${QET_DIR}/sources/editor/esevent/eseventaddellipse.h
  ${QET_DIR}/sources/editor/esevent/eseventaddline.cpp
  ${QET_DIR}/sources/editor/esevent/eseventaddline.h
  ${QET_DIR}/sources/editor/esevent/eseventaddpolygon.cpp
  ${QET_DIR}/sources/editor/esevent/eseventaddpolygon.h
  ${QET_DIR}/sources/editor/esevent/eseventaddrect.cpp
  ${QET_DIR}/sources/editor/esevent/eseventaddrect.h
  ${QET_DIR}/sources/editor/esevent/eseventaddterminal.cpp
  ${QET_DIR}/sources/editor/esevent/eseventaddterminal.h
  ${QET_DIR}/sources/editor/esevent/eseventaddtext.cpp
  ${QET_DIR}/sources/editor/esevent/eseventaddtext.h
  ${QET_DIR}/sources/editor/esevent/eseventinterface.cpp
  ${QET_DIR}/sources/editor/esevent/eseventinterface.h

  ${QET_DIR}/sources/editor/graphicspart/abstractpartellipse.cpp
  ${QET_DIR}/sources/editor/graphicspart/abstractpartellipse.h
  ${QET_DIR}/sources/editor/graphicspart/customelementgraphicpart.cpp
  ${QET_DIR}/sources/editor/graphicspart/customelementgraphicpart.h
  ${QET_DIR}/sources/editor/graphicspart/customelementpart.cpp
  ${QET_DIR}/sources/editor/graphicspart/customelementpart.h
  ${QET_DIR}/sources/editor/graphicspart/partarc.cpp
  ${QET_DIR}/sources/editor/graphicspart/partarc.h
  ${QET_DIR}/sources/editor/graphicspart/partdynamictextfield.cpp
  ${QET_DIR}/sources/editor/graphicspart/partdynamictextfield.h
  ${QET_DIR}/sources/editor/graphicspart/partellipse.cpp
  ${QET_DIR}/sources/editor/graphicspart/partellipse.h
  ${QET_DIR}/sources/editor/graphicspart/partline.cpp
  ${QET_DIR}/sources/editor/graphicspart/partline.h
  ${QET_DIR}/sources/editor/graphicspart/partpolygon.cpp
  ${QET_DIR}/sources/editor/graphicspart/partpolygon.h
  ${QET_DIR}/sources/editor/graphicspart/partrectangle.cpp
  ${QET_DIR}/sources/editor/graphicspart/partrectangle.h
  ${QET_DIR}/sources/editor/graphicspart/partterminal.cpp
  ${QET_DIR}/sources/editor/graphicspart/partterminal.h
  ${QET_DIR}/sources/editor/graphicspart/parttext.cpp
  ${QET_DIR}/sources/editor/graphicspart/parttext.h
  ${QET_DIR}/sources/editor/ui/dynamictextfieldeditor.cpp
  ${QET_DIR}/sources/editor/ui/dynamictextfieldeditor.h
  ${QET_DIR}/sources/editor/ui/elementpropertieseditorwidget.cpp
  ${QET_DIR}/sources/editor/ui/elementpropertieseditorwidget.h
  ${QET_DIR}/sources/editor/ui/ellipseeditor.cpp
  ${QET_DIR}/sources/editor/ui/ellipseeditor.h
  ${QET_DIR}/sources/editor/ui/lineeditor.cpp
  ${QET_DIR}/sources/editor/ui/lineeditor.h
  ${QET_DIR}/sources/editor/ui/polygoneditor.cpp
  ${QET_DIR}/sources/editor/ui/polygoneditor.h
  ${QET_DIR}/sources/editor/ui/rectangleeditor.cpp
  ${QET_DIR}/sources/editor/ui/rectangleeditor.h
  ${QET_DIR}/sources/editor/ui/terminaleditor.cpp
  ${QET_DIR}/sources/editor/ui/terminaleditor.h
  ${QET_DIR}/sources/editor/ui/texteditor.cpp
  ${QET_DIR}/sources/editor/ui/texteditor.h
  ${QET_DIR}/sources/editor/ui/qetelementeditor.h
  ${QET_DIR}/sources/editor/ui/qetelementeditor.cpp

  ${QET_DIR}/sources/editor/UndoCommand/pastepartscommand.cpp
  ${QET_DIR}/sources/editor/UndoCommand/pastepartscommand.h
  ${QET_DIR}/sources/editor/UndoCommand/openelmtcommand.cpp
  ${QET_DIR}/sources/editor/UndoCommand/openelmtcommand.h
  ${QET_DIR}/sources/editor/UndoCommand/deletepartscommand.cpp
  ${QET_DIR}/sources/editor/UndoCommand/deletepartscommand.h
  ${QET_DIR}/sources/editor/UndoCommand/addpartcommand.cpp
  ${QET_DIR}/sources/editor/UndoCommand/addpartcommand.h

  ${QET_DIR}/sources/ElementsCollection/elementcollectionhandler.cpp
  ${QET_DIR}/sources/ElementsCollection/elementcollectionhandler.h
  ${QET_DIR}/sources/ElementsCollection/elementcollectionitem.cpp
  ${QET_DIR}/sources/ElementsCollection/elementcollectionitem.h
  ${QET_DIR}/sources/ElementsCollection/elementscollectionmodel.cpp
  ${QET_DIR}/sources/ElementsCollection/elementscollectionmodel.h
  ${QET_DIR}/sources/ElementsCollection/elementscollectionwidget.cpp
  ${QET_DIR}/sources/ElementsCollection/elementscollectionwidget.h
  ${QET_DIR}/sources/ElementsCollection/elementslocation.cpp
  ${QET_DIR}/sources/ElementsCollection/elementslocation.h
  ${QET_DIR}/sources/ElementsCollection/elementstreeview.cpp
  ${QET_DIR}/sources/ElementsCollection/elementstreeview.h
  ${QET_DIR}/sources/ElementsCollection/fileelementcollectionitem.cpp
  ${QET_DIR}/sources/ElementsCollection/fileelementcollectionitem.h
  ${QET_DIR}/sources/ElementsCollection/xmlelementcollection.cpp
  ${QET_DIR}/sources/ElementsCollection/xmlelementcollection.h
  ${QET_DIR}/sources/ElementsCollection/xmlprojectelementcollectionitem.cpp
  ${QET_DIR}/sources/ElementsCollection/xmlprojectelementcollectionitem.h

  ${QET_DIR}/sources/ElementsCollection/ui/renamedialog.cpp
  ${QET_DIR}/sources/ElementsCollection/ui/renamedialog.h

  ${QET_DIR}/sources/factory/elementfactory.cpp
  ${QET_DIR}/sources/factory/elementfactory.h
  ${QET_DIR}/sources/factory/elementpicturefactory.cpp
  ${QET_DIR}/sources/factory/elementpicturefactory.h
  ${QET_DIR}/sources/factory/propertieseditorfactory.cpp
  ${QET_DIR}/sources/factory/propertieseditorfactory.h
  ${QET_DIR}/sources/factory/qetgraphicstablefactory.cpp
  ${QET_DIR}/sources/factory/qetgraphicstablefactory.h

  ${QET_DIR}/sources/factory/ui/addtabledialog.cpp
  ${QET_DIR}/sources/factory/ui/addtabledialog.h

  ${QET_DIR}/sources/NameList/nameslist.cpp
  ${QET_DIR}/sources/NameList/nameslist.h

  ${QET_DIR}/sources/NameList/ui/namelistdialog.cpp
  ${QET_DIR}/sources/NameList/ui/namelistdialog.h
  ${QET_DIR}/sources/NameList/ui/namelistwidget.cpp
  ${QET_DIR}/sources/NameList/ui/namelistwidget.h

  ${QET_DIR}/sources/print/projectprintwindow.cpp
  ${QET_DIR}/sources/print/projectprintwindow.h

  ${QET_DIR}/sources/project/projectpropertieshandler.cpp
  ${QET_DIR}/sources/project/projectpropertieshandler.h

  ${QET_DIR}/sources/properties/elementdata.cpp
  ${QET_DIR}/sources/properties/elementdata.h
  ${QET_DIR}/sources/properties/propertiesinterface.cpp
  ${QET_DIR}/sources/properties/propertiesinterface.h
  ${QET_DIR}/sources/properties/reportproperties.cpp
  ${QET_DIR}/sources/properties/reportproperties.h
  ${QET_DIR}/sources/properties/terminaldata.cpp
  ${QET_DIR}/sources/properties/terminaldata.h
  ${QET_DIR}/sources/properties/xrefproperties.cpp
  ${QET_DIR}/sources/properties/xrefproperties.h
  ${QET_DIR}/sources/properties/userproperties.cpp
  ${QET_DIR}/sources/properties/userproperties.h

  ${QET_DIR}/sources/PropertiesEditor/propertieseditordialog.h
  ${QET_DIR}/sources/PropertiesEditor/propertieseditordockwidget.cpp
  ${QET_DIR}/sources/PropertiesEditor/propertieseditordockwidget.h
  ${QET_DIR}/sources/PropertiesEditor/propertieseditorwidget.cpp
  ${QET_DIR}/sources/PropertiesEditor/propertieseditorwidget.h

  ${QET_DIR}/pugixml/src/pugiconfig.hpp
  ${QET_DIR}/pugixml/src/pugixml.cpp
  ${QET_DIR}/pugixml/src/pugixml.hpp

  ${QET_DIR}/sources/qetgraphicsitem/conductor.cpp
  ${QET_DIR}/sources/qetgraphicsitem/conductor.h
  ${QET_DIR}/sources/qetgraphicsitem/conductortextitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/conductortextitem.h
  ${QET_DIR}/sources/qetgraphicsitem/crossrefitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/crossrefitem.h
  ${QET_DIR}/sources/qetgraphicsitem/diagramimageitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/diagramimageitem.h
  ${QET_DIR}/sources/qetgraphicsitem/diagramtextitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/diagramtextitem.h
  ${QET_DIR}/sources/qetgraphicsitem/dynamicelementtextitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/dynamicelementtextitem.h
  ${QET_DIR}/sources/qetgraphicsitem/element.cpp
  ${QET_DIR}/sources/qetgraphicsitem/element.h
  ${QET_DIR}/sources/qetgraphicsitem/elementtextitemgroup.cpp
  ${QET_DIR}/sources/qetgraphicsitem/elementtextitemgroup.h
  ${QET_DIR}/sources/qetgraphicsitem/independenttextitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/independenttextitem.h
  ${QET_DIR}/sources/qetgraphicsitem/masterelement.cpp
  ${QET_DIR}/sources/qetgraphicsitem/masterelement.h
  ${QET_DIR}/sources/qetgraphicsitem/qetgraphicsitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/qetgraphicsitem.h
  ${QET_DIR}/sources/qetgraphicsitem/qetshapeitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/qetshapeitem.h
  ${QET_DIR}/sources/qetgraphicsitem/qgraphicsitemutility.cpp
  ${QET_DIR}/sources/qetgraphicsitem/qgraphicsitemutility.h
  ${QET_DIR}/sources/qetgraphicsitem/reportelement.cpp
  ${QET_DIR}/sources/qetgraphicsitem/reportelement.h
  ${QET_DIR}/sources/qetgraphicsitem/simpleelement.cpp
  ${QET_DIR}/sources/qetgraphicsitem/simpleelement.h
  ${QET_DIR}/sources/qetgraphicsitem/slaveelement.cpp
  ${QET_DIR}/sources/qetgraphicsitem/slaveelement.h
  ${QET_DIR}/sources/qetgraphicsitem/terminal.cpp
  ${QET_DIR}/sources/qetgraphicsitem/terminalelement.cpp
  ${QET_DIR}/sources/qetgraphicsitem/terminalelement.h
  ${QET_DIR}/sources/qetgraphicsitem/terminal.h

  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/projectdbmodel.cpp
  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/projectdbmodel.h
  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/qetgraphicsheaderitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/qetgraphicsheaderitem.h
  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/qetgraphicstableitem.cpp
  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/qetgraphicstableitem.h

  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/ui/graphicstablepropertieseditor.cpp
  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/ui/graphicstablepropertieseditor.h
  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/ui/projectdbmodelpropertieswidget.cpp
  ${QET_DIR}/sources/qetgraphicsitem/ViewItem/ui/projectdbmodelpropertieswidget.h

  ${QET_DIR}/sources/QetGraphicsItemModeler/qetgraphicshandleritem.cpp
  ${QET_DIR}/sources/QetGraphicsItemModeler/qetgraphicshandleritem.h
  ${QET_DIR}/sources/QetGraphicsItemModeler/qetgraphicshandlerutility.cpp
  ${QET_DIR}/sources/QetGraphicsItemModeler/qetgraphicshandlerutility.h

  ${QET_DIR}/sources/QPropertyUndoCommand/qpropertyundocommand.cpp
  ${QET_DIR}/sources/QPropertyUndoCommand/qpropertyundocommand.h

  ${QET_DIR}/sources/QWidgetAnimation/qwidgetanimation.cpp
  ${QET_DIR}/sources/QWidgetAnimation/qwidgetanimation.h

  ${QET_DIR}/sources/richtext/richtexteditor.cpp
  ${QET_DIR}/sources/richtext/richtexteditor_p.h
  ${QET_DIR}/sources/richtext/ui_addlinkdialog.h

  ${QET_DIR}/sources/SearchAndReplace/searchandreplaceworker.cpp
  ${QET_DIR}/sources/SearchAndReplace/searchandreplaceworker.h

  ${QET_DIR}/sources/SearchAndReplace/ui/replaceadvanceddialog.cpp
  ${QET_DIR}/sources/SearchAndReplace/ui/replaceadvanceddialog.h
  ${QET_DIR}/sources/SearchAndReplace/ui/replaceconductordialog.cpp
  ${QET_DIR}/sources/SearchAndReplace/ui/replaceconductordialog.h
  ${QET_DIR}/sources/SearchAndReplace/ui/replaceelementdialog.cpp
  ${QET_DIR}/sources/SearchAndReplace/ui/replaceelementdialog.h
  ${QET_DIR}/sources/SearchAndReplace/ui/replacefoliowidget.cpp
  ${QET_DIR}/sources/SearchAndReplace/ui/replacefoliowidget.h
  ${QET_DIR}/sources/SearchAndReplace/ui/searchandreplacewidget.cpp
  ${QET_DIR}/sources/SearchAndReplace/ui/searchandreplacewidget.h

  ${QET_DIR}/sources/titleblock/dimension.cpp
  ${QET_DIR}/sources/titleblock/dimension.h
  ${QET_DIR}/sources/titleblock/dimensionwidget.cpp
  ${QET_DIR}/sources/titleblock/dimensionwidget.h
  ${QET_DIR}/sources/titleblock/gridlayoutanimation.cpp
  ${QET_DIR}/sources/titleblock/gridlayoutanimation.h
  ${QET_DIR}/sources/titleblock/helpercell.cpp
  ${QET_DIR}/sources/titleblock/helpercell.h
  ${QET_DIR}/sources/titleblock/integrationmovetemplateshandler.cpp
  ${QET_DIR}/sources/titleblock/integrationmovetemplateshandler.h
  ${QET_DIR}/sources/titleblock/movetemplateshandler.h
  ${QET_DIR}/sources/titleblock/qettemplateeditor.cpp
  ${QET_DIR}/sources/titleblock/qettemplateeditor.h
  ${QET_DIR}/sources/titleblock/splittedhelpercell.cpp
  ${QET_DIR}/sources/titleblock/splittedhelpercell.h
  ${QET_DIR}/sources/titleblock/templatecellsset.cpp
  ${QET_DIR}/sources/titleblock/templatecellsset.h
  ${QET_DIR}/sources/titleblock/templatecellwidget.cpp
  ${QET_DIR}/sources/titleblock/templatecellwidget.h
  ${QET_DIR}/sources/titleblock/templatecommands.cpp
  ${QET_DIR}/sources/titleblock/templatecommands.h
  ${QET_DIR}/sources/titleblock/templatedeleter.cpp
  ${QET_DIR}/sources/titleblock/templatedeleter.h
  ${QET_DIR}/sources/titleblock/templatelocationchooser.cpp
  ${QET_DIR}/sources/titleblock/templatelocationchooser.h
  ${QET_DIR}/sources/titleblock/templatelocation.cpp
  ${QET_DIR}/sources/titleblock/templatelocation.h
  ${QET_DIR}/sources/titleblock/templatelocationsaver.cpp
  ${QET_DIR}/sources/titleblock/templatelocationsaver.h
  ${QET_DIR}/sources/titleblock/templatelogomanager.cpp
  ${QET_DIR}/sources/titleblock/templatelogomanager.h
  ${QET_DIR}/sources/titleblock/templatescollection.cpp
  ${QET_DIR}/sources/titleblock/templatescollection.h
  ${QET_DIR}/sources/titleblock/templateview.cpp
  ${QET_DIR}/sources/titleblock/templateview.h
  ${QET_DIR}/sources/titleblock/templatevisualcell.cpp
  ${QET_DIR}/sources/titleblock/templatevisualcell.h

  ${QET_DIR}/sources/TerminalStrip/physicalterminal.cpp
  ${QET_DIR}/sources/TerminalStrip/physicalterminal.h
  ${QET_DIR}/sources/TerminalStrip/realterminal.cpp
  ${QET_DIR}/sources/TerminalStrip/realterminal.h
  ${QET_DIR}/sources/TerminalStrip/terminalstripbridge.cpp
  ${QET_DIR}/sources/TerminalStrip/terminalstripbridge.h
  ${QET_DIR}/sources/TerminalStrip/terminalstrip.cpp
  ${QET_DIR}/sources/TerminalStrip/terminalstrip.h
  ${QET_DIR}/sources/TerminalStrip/terminalstripdata.cpp
  ${QET_DIR}/sources/TerminalStrip/terminalstripdata.h
  ${QET_DIR}/sources/TerminalStrip/ui/addterminalstripitemdialog.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/addterminalstripitemdialog.h
  ${QET_DIR}/sources/TerminalStrip/ui/freeterminaleditor.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/freeterminaleditor.h
  ${QET_DIR}/sources/TerminalStrip/ui/freeterminalmodel.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/freeterminalmodel.h
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripcreatordialog.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripcreatordialog.h
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripeditor.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripeditor.h
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripeditorwindow.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripeditorwindow.h
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstriplayouteditor.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstriplayouteditor.h
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripmodel.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstripmodel.h
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstriptreedockwidget.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/terminalstriptreedockwidget.h
  ${QET_DIR}/sources/TerminalStrip/ui/ConfigPage/terminalstripprojectconfigpage.cpp
  ${QET_DIR}/sources/TerminalStrip/ui/ConfigPage/terminalstripprojectconfigpage.h
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/addterminalstripcommand.cpp
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/addterminalstripcommand.h
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/addterminaltostripcommand.cpp
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/addterminaltostripcommand.h
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/bridgeterminalscommand.cpp
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/bridgeterminalscommand.h
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/changeterminallevel.cpp
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/changeterminallevel.h
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/changeterminalstripcolor.cpp
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/changeterminalstripcolor.h
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/changeterminalstripdata.cpp
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/changeterminalstripdata.h
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/groupterminalscommand.cpp
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/groupterminalscommand.h
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/sortterminalstripcommand.cpp
  ${QET_DIR}/sources/TerminalStrip/UndoCommand/sortterminalstripcommand.h
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/demoterminalstrip.cpp
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/demoterminalstrip.h
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/terminalstripitem.cpp
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/terminalstripitem.h
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/trueterminalstrip.cpp
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/trueterminalstrip.h
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/terminalstripdrawer.cpp
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/terminalstripdrawer.h
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/properties/terminalstriplayoutpattern.cpp
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/properties/terminalstriplayoutpattern.h
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/properties/terminalstriplayoutshandler.cpp
  ${QET_DIR}/sources/TerminalStrip/GraphicsItem/properties/terminalstriplayoutshandler.h

  ${QET_DIR}/sources/ui/aboutqetdialog.cpp
  ${QET_DIR}/sources/ui/aboutqetdialog.h
  ${QET_DIR}/sources/ui/abstractelementpropertieseditorwidget.cpp
  ${QET_DIR}/sources/ui/abstractelementpropertieseditorwidget.h
  ${QET_DIR}/sources/ui/alignmenttextdialog.cpp
  ${QET_DIR}/sources/ui/alignmenttextdialog.h
  ${QET_DIR}/sources/ui/bomexportdialog.cpp
  ${QET_DIR}/sources/ui/bomexportdialog.h
  ${QET_DIR}/sources/ui/borderpropertieswidget.cpp
  ${QET_DIR}/sources/ui/borderpropertieswidget.h
  ${QET_DIR}/sources/ui/compositetexteditdialog.cpp
  ${QET_DIR}/sources/ui/compositetexteditdialog.h
  ${QET_DIR}/sources/ui/conductorpropertiesdialog.cpp
  ${QET_DIR}/sources/ui/conductorpropertiesdialog.h
  ${QET_DIR}/sources/ui/conductorpropertieswidget.cpp
  ${QET_DIR}/sources/ui/conductorpropertieswidget.h
  ${QET_DIR}/sources/ui/configsaveloaderwidget.cpp
  ${QET_DIR}/sources/ui/configsaveloaderwidget.h
  ${QET_DIR}/sources/ui/diagramcontextwidget.cpp
  ${QET_DIR}/sources/ui/diagramcontextwidget.h
  ${QET_DIR}/sources/ui/diagrameditorhandlersizewidget.cpp
  ${QET_DIR}/sources/ui/diagrameditorhandlersizewidget.h
  ${QET_DIR}/sources/ui/diagrampropertiesdialog.cpp
  ${QET_DIR}/sources/ui/diagrampropertiesdialog.h
  ${QET_DIR}/sources/ui/diagrampropertieseditordockwidget.cpp
  ${QET_DIR}/sources/ui/diagrampropertieseditordockwidget.h
  ${QET_DIR}/sources/ui/diagramselection.cpp
  ${QET_DIR}/sources/ui/diagramselection.h
  ${QET_DIR}/sources/ui/dialogwaiting.cpp
  ${QET_DIR}/sources/ui/dialogwaiting.h
  ${QET_DIR}/sources/ui/dynamicelementtextitemeditor.cpp
  ${QET_DIR}/sources/ui/dynamicelementtextitemeditor.h
  ${QET_DIR}/sources/ui/dynamicelementtextmodel.cpp
  ${QET_DIR}/sources/ui/dynamicelementtextmodel.h
  ${QET_DIR}/sources/ui/elementinfopartwidget.cpp
  ${QET_DIR}/sources/ui/elementinfopartwidget.h
  ${QET_DIR}/sources/ui/elementinfowidget.cpp
  ${QET_DIR}/sources/ui/elementinfowidget.h
  ${QET_DIR}/sources/ui/elementpropertieswidget.cpp
  ${QET_DIR}/sources/ui/elementpropertieswidget.h
  ${QET_DIR}/sources/ui/formulaassistantdialog.cpp
  ${QET_DIR}/sources/ui/formulaassistantdialog.h
  ${QET_DIR}/sources/ui/imagepropertieswidget.cpp
  ${QET_DIR}/sources/ui/imagepropertieswidget.h
  ${QET_DIR}/sources/ui/importelementdialog.cpp
  ${QET_DIR}/sources/ui/importelementdialog.h
  ${QET_DIR}/sources/ui/importelementtextpatterndialog.cpp
  ${QET_DIR}/sources/ui/importelementtextpatterndialog.h
  ${QET_DIR}/sources/ui/inditextpropertieswidget.cpp
  ${QET_DIR}/sources/ui/inditextpropertieswidget.h
  ${QET_DIR}/sources/ui/linksingleelementwidget.cpp
  ${QET_DIR}/sources/ui/linksingleelementwidget.h
  ${QET_DIR}/sources/ui/marginseditdialog.cpp
  ${QET_DIR}/sources/ui/marginseditdialog.h
  ${QET_DIR}/sources/ui/masterpropertieswidget.cpp
  ${QET_DIR}/sources/ui/masterpropertieswidget.h
  ${QET_DIR}/sources/ui/multipastedialog.cpp
  ${QET_DIR}/sources/ui/multipastedialog.h
  ${QET_DIR}/sources/ui/potentialselectordialog.cpp
  ${QET_DIR}/sources/ui/potentialselectordialog.h
  ${QET_DIR}/sources/ui/projectpropertiesdialog.cpp
  ${QET_DIR}/sources/ui/projectpropertiesdialog.h
  ${QET_DIR}/sources/ui/reportpropertiewidget.cpp
  ${QET_DIR}/sources/ui/reportpropertiewidget.h
  ${QET_DIR}/sources/ui/shapegraphicsitempropertieswidget.cpp
  ${QET_DIR}/sources/ui/shapegraphicsitempropertieswidget.h
  ${QET_DIR}/sources/ui/thirdpartybinaryinstalldialog.cpp
  ${QET_DIR}/sources/ui/thirdpartybinaryinstalldialog.h
  ${QET_DIR}/sources/ui/titleblockpropertieswidget.cpp
  ${QET_DIR}/sources/ui/titleblockpropertieswidget.h
  ${QET_DIR}/sources/ui/xrefpropertieswidget.cpp
  ${QET_DIR}/sources/ui/xrefpropertieswidget.h
  ${QET_DIR}/sources/ui/configpage/configpage.h
  ${QET_DIR}/sources/ui/configpage/configpages.cpp
  ${QET_DIR}/sources/ui/configpage/configpages.h
  ${QET_DIR}/sources/ui/configpage/generalconfigurationpage.cpp
  ${QET_DIR}/sources/ui/configpage/generalconfigurationpage.h
  ${QET_DIR}/sources/ui/configpage/projectconfigpages.cpp
  ${QET_DIR}/sources/ui/configpage/projectconfigpages.h

  ${QET_DIR}/sources/undocommand/addelementtextcommand.cpp
  ${QET_DIR}/sources/undocommand/addelementtextcommand.h
  ${QET_DIR}/sources/undocommand/addgraphicsobjectcommand.cpp
  ${QET_DIR}/sources/undocommand/addgraphicsobjectcommand.h
  ${QET_DIR}/sources/undocommand/changeelementdatacommand.cpp
  ${QET_DIR}/sources/undocommand/changeelementdatacommand.h
  ${QET_DIR}/sources/undocommand/changeelementinformationcommand.cpp
  ${QET_DIR}/sources/undocommand/changeelementinformationcommand.h
  ${QET_DIR}/sources/undocommand/changetitleblockcommand.cpp
  ${QET_DIR}/sources/undocommand/changetitleblockcommand.h
  ${QET_DIR}/sources/undocommand/deleteqgraphicsitemcommand.cpp
  ${QET_DIR}/sources/undocommand/deleteqgraphicsitemcommand.h
  ${QET_DIR}/sources/undocommand/itemmodelcommand.cpp
  ${QET_DIR}/sources/undocommand/itemmodelcommand.h
  ${QET_DIR}/sources/undocommand/linkelementcommand.cpp
  ${QET_DIR}/sources/undocommand/linkelementcommand.h
  ${QET_DIR}/sources/undocommand/rotateselectioncommand.cpp
  ${QET_DIR}/sources/undocommand/rotateselectioncommand.h
  ${QET_DIR}/sources/undocommand/rotatetextscommand.cpp
  ${QET_DIR}/sources/undocommand/rotatetextscommand.h
  ${QET_DIR}/sources/undocommand/movegraphicsitemcommand.cpp
  ${QET_DIR}/sources/undocommand/movegraphicsitemcommand.h

  ${QET_DIR}/sources/utils/conductorcreator.cpp
  ${QET_DIR}/sources/utils/conductorcreator.h
  ${QET_DIR}/sources/utils/macosxopenevent.cpp
  ${QET_DIR}/sources/utils/macosxopenevent.h
  ${QET_DIR}/sources/utils/qetsettings.cpp
  ${QET_DIR}/sources/utils/qetsettings.h
  ${QET_DIR}/sources/utils/qetutils.cpp
  ${QET_DIR}/sources/utils/qetutils.h

  ${QET_DIR}/sources/xml/terminalstripitemxml.cpp
  ${QET_DIR}/sources/xml/terminalstripitemxml.h
  )

set(TS_FILES
  ${QET_DIR}/lang/qet_ar.ts
  ${QET_DIR}/lang/qet_be.ts
  ${QET_DIR}/lang/qet_ca.ts
  ${QET_DIR}/lang/qet_cs.ts
  ${QET_DIR}/lang/qet_da.ts
  ${QET_DIR}/lang/qet_de.ts
  ${QET_DIR}/lang/qet_el.ts
  ${QET_DIR}/lang/qet_en.ts
  ${QET_DIR}/lang/qet_es.ts
  ${QET_DIR}/lang/qet_fi.ts
  ${QET_DIR}/lang/qet_fr.ts
  ${QET_DIR}/lang/qet_hr.ts
  ${QET_DIR}/lang/qet_hu.ts
  ${QET_DIR}/lang/qet_it.ts
  ${QET_DIR}/lang/qet_ja.ts
  ${QET_DIR}/lang/qet_mn.ts
  ${QET_DIR}/lang/qet_nb.ts
  ${QET_DIR}/lang/qet_nl.ts
  ${QET_DIR}/lang/qet_no.ts
  ${QET_DIR}/lang/qet_pl.ts
  ${QET_DIR}/lang/qet_pt.ts
  ${QET_DIR}/lang/qet_pt_BR.ts
  ${QET_DIR}/lang/qet_ro.ts
  ${QET_DIR}/lang/qet_ru.ts
  ${QET_DIR}/lang/qet_sk.ts
  ${QET_DIR}/lang/qet_sl.ts
  ${QET_DIR}/lang/qet_sr.ts
  ${QET_DIR}/lang/qet_tr.ts
  ${QET_DIR}/lang/qet_zh.ts
  )
