
//
// Created by noreasonexception on 4/4/18.
//
#ifndef IKARUS_PROJECT_LOGSUPPLIERFACTORY_H
#define IKARUS_PROJECT_LOGSUPPLIERFACTORY_H

#include "InformationSupplierFactory.h"
#include "../Supplier/LogSupplier/LogSupplier.h"
/***
 * class LogSupplierFactory
 * This interface will implemented by every subsystem wants to accept data of type Log* from other subsystems
 * @see Consumer/InformationObjectConsumer.h
 * For example , the LogPanel ^^
 */
class LogSupplierFactory:public InformationSupplierFactory{
public:
    virtual LogSupplier*createSupplier(QString supplierName)override=0;


};

#endif