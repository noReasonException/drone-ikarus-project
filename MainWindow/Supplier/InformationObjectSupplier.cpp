//
// Created by noreasonexception on 4/3/18.
//

#include "InformationObjectSupplier.h"

const QString &InformationObjectSupplier::getSupplierName() const {
    return supplierName;
}

InformationObjectSupplier* InformationObjectSupplier::setSupplierName(const QString &supplierName) {
    InformationObjectSupplier::supplierName = supplierName;
    return this;
}

InformationObjectConsumer *InformationObjectSupplier::getTargetConsumer() const {
    return targetConsumer;
}

InformationObjectSupplier* InformationObjectSupplier::setTargetConsumer(InformationObjectConsumer *targetConsumer) {
    InformationObjectSupplier::targetConsumer = targetConsumer;
    return this;
}
