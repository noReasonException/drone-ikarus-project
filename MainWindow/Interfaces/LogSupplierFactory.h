//
// Created by noreasonexception on 4/4/18.
//
#include "InformationSupplierFactory.h"
#include "../Supplier/LogSupplier/LogSupplier.h"

class LogSupplierFactory:public InformationSupplierFactory{
public:
    LogSupplierFactory()=delete;

    virtual LogSupplier*createSupplier(QString supplierName)override{
        return new LogSupplier();
    }

};