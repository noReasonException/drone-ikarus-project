//
// Created by noreasonexception on 5/3/18.
//

#include "InformationExporter.h"

const QSettings &InformationExporter::getSettings() const {
    return settings;
}

InformationExporter::InformationExporter() : settings(new QSettings) {}

InformationObjectSupplier *InformationExporter::createSupplier(QString supplierName) {
    return new InformationObjectSupplier(supplierName,this);
}
