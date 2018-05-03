//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_OPTIONSUPPLIERFACTORY_H
#define IKARUS_PROJECT_OPTIONSUPPLIERFACTORY_H


#include "InformationSupplierFactory.h"
#include "../Supplier/OptionSupplier/OptionSupplier.h"
/***
 * class DataSupplierFactory
 * This interface will implemented by every subsystem wants to accept data of type Option* from other subsystems
 * @see Consumer/InformationObjectConsumer.h
 * For example , the RTSP Subsystem ^^
 */
class OptionSupplierFactory: public InformationSupplierFactory {
public:
    OptionSupplier *createSupplier(QString supplierName) override =0;

};


#endif //IKARUS_PROJECT_OPTIONSUPPLIERFACTORY_H
