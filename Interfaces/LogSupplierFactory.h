
//
// Created by noreasonexception on 4/4/18.
//
#ifndef IKARUS_PROJECT_LOGSUPPLIERFACTORY_H
#define IKARUS_PROJECT_LOGSUPPLIERFACTORY_H

#include "InformationSupplierFactory.h"
#include "../Supplier/LogSupplier/LogSupplier.h"
/****
 * Represents a class that can provide a Supplier Object (To send @see Log objects)
 */
class LogSupplierFactory:public InformationSupplierFactory{
public:
    virtual LogSupplier*createSupplier(QString supplierName)override=0;


};

#endif