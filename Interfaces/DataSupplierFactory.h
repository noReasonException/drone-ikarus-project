//
// Created by noreasonexception on 4/18/18.
//

#ifndef IKARUS_PROJECT_DATASUPPLIERFACTORY_H
#define IKARUS_PROJECT_DATASUPPLIERFACTORY_H


#include "../Consumer/InformationObjectConsumer.h"
#include "InformationSupplierFactory.h"
#include "../Supplier/DataSupplier/DataSupplier.h"
/***
 * class DataSupplierFactory
 * This interface will implemented by every subsystem wants to accept data of type Data* from other subsystems
 * @see Consumer/InformationObjectConsumer.h
 * For example , the DataPanel ^^
 */
class DataSupplierFactory : public InformationSupplierFactory {
public:
    DataSupplier *createSupplier(QString supplierName) override =0;
};


#endif //IKARUS_PROJECT_DATASUPPLIERFACTORY_H
