//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_OPTIONSUPPLIER_H
#define IKARUS_PROJECT_OPTIONSUPPLIER_H


#include "../InformationObjectSupplier.h"

class OptionSupplier: public InformationObjectSupplier {
public:
    OptionSupplier(const QString _supplierName, InformationObjectConsumer *target);

};


#endif //IKARUS_PROJECT_OPTIONSUPPLIER_H
