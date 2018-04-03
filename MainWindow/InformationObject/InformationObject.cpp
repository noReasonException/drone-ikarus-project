//
// Created by noreasonexception on 4/3/18.
//

#include "InformationObject.h"

InformationObject::InformationObject(long timestamp) : timestamp(timestamp) {}

long InformationObject::getTimestamp() const {
    return timestamp;
}

InformationObject* InformationObject::setTimestamp(long timestamp) {
    InformationObject::timestamp = timestamp;
    return this;
}
