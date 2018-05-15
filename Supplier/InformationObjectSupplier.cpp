/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */
#include <iostream>
#include "InformationObjectSupplier.h"

const QString InformationObjectSupplier::getSupplierName() const {
    return supplierName;
}

InformationObjectSupplier* InformationObjectSupplier::setSupplierName(const QString &supplierName) {
    InformationObjectSupplier::supplierName = supplierName;
    return this;
}

InformationObjectConsumer *InformationObjectSupplier::getTargetConsumer() const {
    return targetConsumer;
}

InformationObjectSupplier* InformationObjectSupplier::setTargetConsumer(InformationObjectConsumer *targetConsumer) {
    InformationObjectSupplier::targetConsumer = targetConsumer;
    return this;
}

void InformationObjectSupplier::send(InformationObject *info) {
    targetConsumer->accept(this,info);

}
