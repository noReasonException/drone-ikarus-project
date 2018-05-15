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
#ifndef IKARUS_PROJECT_LOGCONSUMER_H
#define IKARUS_PROJECT_LOGCONSUMER_H


#include <QArgument>
#include "../../Supplier/InformationObjectSupplier.h"
#include "../../InformationObject/InformationObject.h"
#include "../InformationObjectConsumer.h"
/****
 * LogConsumer class
 * this interface (wannabe , but...c++ :P ) is derived by every class that want to consume
 * Log* objects . As an example for this , LogPanel is an LogConsumer class , the
 * RTSP Subsystem sends Log* objects filled with information about initialization procces through an LogSupplier
 */
class LogConsumer: public InformationObjectConsumer {
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override=0;
};


#endif //IKARUS_PROJECT_LOGCONSUMER_H
