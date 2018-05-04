//
// Created by noreasonexception on 4/14/18.
//

#include "OptionSupplier.h"

OptionSupplier::OptionSupplier(const QString _supplierName, InformationObjectConsumer *target)
        : InformationObjectSupplier(_supplierName, target) {}
