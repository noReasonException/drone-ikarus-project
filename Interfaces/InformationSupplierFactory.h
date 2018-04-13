//
// Created by noreasonexception on 4/4/18.
//

#ifndef IKARUS_PROJECT_INFORMATIONSUPPLIERFACTORY_H
#define IKARUS_PROJECT_INFORMATIONSUPPLIERFACTORY_H


#include <QString>
#include "../Supplier/InformationObjectSupplier.h"
/****
 * Represents a class that can provide a Supplier Object (To send @see InformationObject objects)
 */
class InformationSupplierFactory{
public:
    virtual InformationObjectSupplier*createSupplier(QString supplierName)=0;
};

#endif