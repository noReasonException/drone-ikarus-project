//
// Created by noreasonexception on 4/4/18.
//

#ifndef IKARUS_PROJECT_INFORMATIONSUPPLIERFACTORY_H
#define IKARUS_PROJECT_INFORMATIONSUPPLIERFACTORY_H


#include <QString>
#include "../Supplier/InformationObjectSupplier.h"
/****
 * What is a supplier?
 * A supplier is an object witch can supply some object with data
 * For example . SetLatencyDialog class has a OptionSupplier(Derives from this class), And supplies
 * with information of type LatencyOption* the AbstractRTSPClient subsystem .
 */
class InformationSupplierFactory{
public:
    virtual InformationObjectSupplier*createSupplier(QString supplierName)=0;
};

#endif