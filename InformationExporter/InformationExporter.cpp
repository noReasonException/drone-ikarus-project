//
// Created by noreasonexception on 5/3/18.
//

#include "InformationExporter.h"
#include "../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../misc/Suppliers/LogSuppliers.h"

QSettings &InformationExporter::getSettings() {
    return settings;
}

InformationExporter::InformationExporter(LogSupplier*_supl) : settings(new QSettings),supplier(_supl){}

InformationObjectSupplier *InformationExporter::createSupplier(QString supplierName) {
    return new InformationObjectSupplier(supplierName,this);
}

LogSupplier *InformationExporter::getLogSupplier() const {
    return supplier;
}

InformationExporter::~InformationExporter() {
    delete supplier;
}
