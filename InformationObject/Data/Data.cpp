//
// Created by noreasonexception on 4/3/18.
//

#include "Data.h"

Data::Data(int id,long timestamp, InformationObjectSupplier *source) : InformationObject(timestamp, source),ID(id) {}

int Data::getID() const {
    return ID;
}

void Data::setID(int ID) {
    Data::ID = ID;
}
