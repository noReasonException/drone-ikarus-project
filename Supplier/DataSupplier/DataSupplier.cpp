//
// Created by noreasonexception on 4/18/18.
//

#include "DataSupplier.h"

DataSupplier::DataSupplier(const QString &supplierName, InformationObjectConsumer *target) : InformationObjectSupplier(
        supplierName, target) {}
