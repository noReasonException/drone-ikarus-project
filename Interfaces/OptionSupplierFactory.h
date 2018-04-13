//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_OPTIONSUPPLIERFACTORY_H
#define IKARUS_PROJECT_OPTIONSUPPLIERFACTORY_H


#include "InformationSupplierFactory.h"
#include "../Supplier/OptionSupplier/OptionSupplier.h"

class OptionSupplierFactory: InformationSupplierFactory {
    OptionSupplier *createSupplier(QString supplierName) override =0;

};


#endif //IKARUS_PROJECT_OPTIONSUPPLIERFACTORY_H
