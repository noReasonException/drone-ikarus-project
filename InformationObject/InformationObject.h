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
#ifndef IKARUS_PROJECT_INFORMATIONOBJECT_H
#define IKARUS_PROJECT_INFORMATIONOBJECT_H


#include "../Consumer/InformationObjectConsumer.h"
class InformationObjectSupplier;
/*****
 * class InformationObject
 * this class represents an object with abstract information about ...anything!
 * It used in Supplier-Consumers ,
 * @note i have used Fluent Interface getters-setters because ... why not!?
 *
 * */
class InformationObject {
public:
    explicit InformationObject(long timestamp,InformationObjectSupplier*source);
    virtual ~InformationObject()= default;//TODO memory leak fix

private:
    long timestamp;
    InformationObjectSupplier * source;
public:
    long getTimestamp() const;

    InformationObject* setTimestamp(long timestamp);

    InformationObjectSupplier *getSource() const;

    InformationObject* setSource(InformationObjectSupplier *source);

};


#endif //IKARUS_PROJECT_INFORMATIONOBJECT_H
