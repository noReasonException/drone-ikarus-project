//
// Created by noreasonexception on 4/18/18.
//

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
