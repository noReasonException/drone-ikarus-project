//
// Created by noreasonexception on 4/4/18.
//

#include <QString>
#include "../Supplier/InformationObjectSupplier.h"

class InformationSupplierFactory{
public:


    virtual InformationObjectSupplier*createSupplier(QString supplierName)=0;
};