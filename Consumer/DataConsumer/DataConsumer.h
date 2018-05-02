//
// Created by noreasonexception on 4/18/18.
//

#ifndef IKARUS_PROJECT_DATACONSUMER_H
#define IKARUS_PROJECT_DATACONSUMER_H


#include "../InformationObjectConsumer.h"
/****
 * DataConsumer class
 * this interface (wannabe , but...c++ :P ) is derived by every class that want to consume
 * Data* objects . As an example for this , DataPanel is an DataConsumer class , the
 * RTSP Subsystem sends Data* objects filled with metadata for every frame that server sends through
 * an DataSupplier class :) .
 */
class DataConsumer: public InformationObjectConsumer {
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override=0;

    DataConsumer()= default;
};


#endif //IKARUS_PROJECT_DATACONSUMER_H
