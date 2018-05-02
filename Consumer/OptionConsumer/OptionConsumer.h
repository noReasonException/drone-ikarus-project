//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_OPTIONCONSUMER_H
#define IKARUS_PROJECT_OPTIONCONSUMER_H


#include "../InformationObjectConsumer.h"
/****
 * OptionConsumer class
 * this interface (wannabe , but...c++ :P ) is derived by every class that want to consume
 * Option* objects . As an example for this , RTSP Subsystem is an OptionConsumer class , the
 * LatencyDialog sends Option* objects filled with latency configuration through an OptionSupplier
 */
class OptionConsumer: public InformationObjectConsumer {
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override=0;
};


#endif //IKARUS_PROJECT_OPTIONCONSUMER_H
