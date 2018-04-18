//
// Created by noreasonexception on 4/18/18.
//

#ifndef IKARUS_PROJECT_DATACONSUMER_H
#define IKARUS_PROJECT_DATACONSUMER_H


#include "../InformationObjectConsumer.h"

class DataConsumer: public InformationObjectConsumer {
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override=0;

    DataConsumer()= default;
};


#endif //IKARUS_PROJECT_DATACONSUMER_H
