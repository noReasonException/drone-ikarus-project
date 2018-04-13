//
// Created by noreasonexception on 4/4/18.
//

#include <QString>
#include "../MainWindow/Supplier/InformationObjectSupplier.h"
/****
 * Represents a class that can provide a Supplier Object (To send @see InformationObject objects)
 */
class InformationSupplierFactory{
public:
    virtual InformationObjectSupplier*createSupplier(QString supplierName)=0;
};