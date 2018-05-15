/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */
#include <QtWidgets/QMessageBox>
#include <iostream>
#include "DataPanel.h"
#include "../../../../InformationObject/Data/Data.h"
#include "../../../../res/Suppliers/LogSuppliers.h"
#include "../../../../InformationObject/Log/Log.h"
#include "../LogPanel/LogPanel.h"
#include "../../../../res/errors/AlanPanelErrors.h"
#include "../../../../res/generic_text/generic_dialogs.h"
#include "DataWidget/DataWidget.h"
#include "../../../../InformationExporter/ChildClasses/DataExporter.h"
#include "../../../../res/generic_text/Panels/StreamPanel/DataPanel/DataPanelText.h"

DataPanel::DataPanel() : StreamPanel(DATA_PANEL_TITLE),
                         dataPanelLogSupplier(LogPanel::getInstance()->createSupplier("DataPanelSupplier")),
                         dataExporterSupplier(DataExporter::getInstance()->createSupplier("DataPanelSuppllier")){

}
DataPanel* DataPanel::instance= nullptr;
void DataPanel::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    Data*data= dynamic_cast<Data*>(info);
    if(!data){
        dataPanelLogSupplier->send(new Log(
                INVALID_ARGS_IN_ACCEPT_LOG,
                time(NULL),
                INVALID_ARGS_IN_ACCEPT_DESC_LOG,dataPanelLogSupplier));
        return;
    }
    getListView()->addItem(QString::number(data->getID()));
    getListView()->scrollToBottom();
    _prevent_SIGFAULT();
    dataExporterSupplier->send(data);
    delete data;
}


DataSupplier *DataPanel::createSupplier(QString supplierName) {
    return new DataSupplier(supplierName,this);
}

void DataPanel::onDataClicked(QListWidgetItem *item) {

}

DataPanel *DataPanel::getInstance() {
    if(DataPanel::instance)return DataPanel::instance;
    auto pnl=new DataPanel();
    if(!pnl->generic_initializer()){
        QMessageBox::warning(nullptr,GENERIC_INITIALIZATION_ERROR_DIALOG,ERR02_DETAILS);
        return nullptr;
    }
    DataPanel::instance=pnl;
    return pnl;
}

void DataPanel::_prevent_SIGFAULT() {
    if(getListView()->count()>MAX_DATA_ON_PANEL){
        delete getListView()->item(0);
    }

}
