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
#ifndef IKARUS_PROJECT_INFORMATIONOBJECTCONSUMER_H
#define IKARUS_PROJECT_INFORMATIONOBJECTCONSUMER_H


#include <QObject>
#include "../Supplier/InformationObjectSupplier.h"
#include "../InformationObject/InformationObject.h"
class InformationObjectSupplier;
class InformationObject;
/****
 * InformationObjectConsumer
 * What is dat?
 * ============================How this stuff work?!?===========================================
 * The informationObjectConsumer is a abstract class (an interface , for java-fans)
 * In AlanStreamer . many different subsystems work by passing Information each other using
 * InformationObject* 's
 * This class represents any subsystem that wants to accept information from other subsystem using the
 * Consumer-Supplier Pattern .
 *
 * Every derived class , has the responsibility to check using dynamic_cast<>() the parameters given .
 * For an example , you can @see the LogPanel (LogConsumer*) or the RTSPSubsystem (OptionConsumer*)
 * =========================I like the practical examples==========================================
 * For example . any subsystem want to log something to screen . the only think that must do , is to
 * send a Log* object through their LogSupplier* object . thats all! so easy! The LogPanel* will take care the
 * rest !
 * =========================Why so much complexity?=================================================
 * Flexibillity always comes with some complexity cost . in future maybe someone want to implement a queue system
 * so the subsystems to work with minimum amount of delays , if we use setters-getters , this would be impossible
 * (we assume that everyone loves elegant code without dirty fixes..)
 */
class InformationObjectConsumer {
public:
    virtual void accept(InformationObjectSupplier*supplier,InformationObject*info)=0;
};


#endif //IKARUS_PROJECT_INFORMATIONOBJECTCONSUMER_H
