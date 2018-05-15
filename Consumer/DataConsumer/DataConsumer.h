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
