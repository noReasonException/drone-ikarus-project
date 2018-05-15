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
#ifndef IKARUS_PROJECT_OPTION_H
#define IKARUS_PROJECT_OPTION_H


#include "../InformationObject.h"



enum OptionType{
    ClientStatusOption,
    LatencyOption,
    ResolutionOption,
    WindowHandlerOption,
    LocationOption
};
/****
 * class Option
 * This class represents an arbitary option(configuration) information
 * currently @version 0.1 it is used only on RTSP Subsystem (RTSPClientSubsystem/AbstractRTSPClientSubsystem.h)
 * As an example for this , RTSP Subsystem is an OptionConsumer class , the
 * LatencyDialog sends Option* objects filled with latency configuration through an OptionSupplier
 * @note IMPORTANT STUFF ================================================================================
 * @note    The Option* class has no responsibillity to free the InformationObjectSupplier* pointer passed in constructor
 */
class Option : public InformationObject{
protected:
    Option(OptionType optiontype,long timestamp, InformationObjectSupplier *source);
    virtual ~Option(){}

public:
    OptionType getType() const;

private:
    OptionType type;

};


#endif //IKARUS_PROJECT_OPTION_H
