//
// Created by noreasonexception on 4/18/18.
//

#ifndef IKARUS_PROJECT_DATASUPPLIER_H
#define IKARUS_PROJECT_DATASUPPLIER_H


#include "../InformationObjectSupplier.h"

class DataSupplier : public InformationObjectSupplier{
public:
    DataSupplier(const QString &supplierName, InformationObjectConsumer *target);


};


#endif //IKARUS_PROJECT_DATASUPPLIER_H
