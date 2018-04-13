//
// Created by noreasonexception on 4/14/18.
//

#include "OptionSupplier.h"

OptionSupplier::OptionSupplier(const QString &supplierName, InformationObjectConsumer *target)
        : InformationObjectSupplier(supplierName, target) {}
