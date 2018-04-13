//
// Created by noreasonexception on 4/4/18.
//
#include "InformationSupplierFactory.h"
#include "../MainWindow/Supplier/LogSupplier/LogSupplier.h"
/****
 * Represents a class that can provide a Supplier Object (To send @see Log objects)
 */
class LogSupplierFactory:public InformationSupplierFactory{
public:
    virtual LogSupplier*createSupplier(QString supplierName)override=0;


};