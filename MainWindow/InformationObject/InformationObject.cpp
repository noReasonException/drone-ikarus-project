//
// Created by noreasonexception on 4/3/18.
//

#include "InformationObject.h"

InformationObject::InformationObject(long timestamp,InformationObjectSupplier*s) :
        timestamp(timestamp),
        source(s){}

long InformationObject::getTimestamp() const {
    return timestamp;
}

InformationObject* InformationObject::setTimestamp(long timestamp) {
    InformationObject::timestamp = timestamp;
    return this;
}

InformationObjectSupplier *InformationObject::getSource() const {
    return source;
}

InformationObject* InformationObject::setSource(InformationObjectSupplier *source) {
    InformationObject::source = source;
    return this;
}

