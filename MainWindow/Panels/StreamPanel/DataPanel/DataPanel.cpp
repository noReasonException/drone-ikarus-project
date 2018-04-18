//
// Created by noreasonexception on 4/18/18.
//

#include "DataPanel.h"
#include "../../../../misc/generic_text/AlanMainWindowMisc.h"

DataPanel::DataPanel() : StreamPanel(DATA_PANEL_TITLE) {}

void DataPanel::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    //DataConsumer::accept(supplier, info);
}

DataSupplier *DataPanel::createSupplier(QString supplierName) {
    return new DataSupplier(supplierName,this);
}

