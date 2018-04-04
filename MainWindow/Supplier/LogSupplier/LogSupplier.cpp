//
// Created by noreasonexception on 4/3/18.
//

#include "LogSupplier.h"

LogSupplier::LogSupplier(const QString &supplierName,InformationObjectConsumer*target) :
        InformationObjectSupplier(supplierName,target) {}
