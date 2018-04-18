//
// Created by noreasonexception on 4/18/18.
//

#ifndef IKARUS_PROJECT_DATASUPPLIERFACTORY_H
#define IKARUS_PROJECT_DATASUPPLIERFACTORY_H


#include "../Consumer/InformationObjectConsumer.h"
#include "InformationSupplierFactory.h"
#include "../Supplier/DataSupplier/DataSupplier.h"

class DataSupplierFactory : public InformationSupplierFactory {
public:
    DataSupplier *createSupplier(QString supplierName) override =0;
};


#endif //IKARUS_PROJECT_DATASUPPLIERFACTORY_H
