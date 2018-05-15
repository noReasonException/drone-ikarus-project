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

#ifndef IKARUS_PROJECT_LATENCYOPTION_H
#define IKARUS_PROJECT_LATENCYOPTION_H


#include "../Option.h"
/****
 * class LatencyOption
 * This object is used in RTSP Subsystem . Specifically it transfers messages about the stream latency from GUI-Space
 *
 */
class LatencyOption : public Option{
public:
    LatencyOption(int latency_value,long timestamp,InformationObjectSupplier *source) :
            Option(OptionType::LatencyOption, timestamp,source),
            latency(latency_value){}
    ~LatencyOption()override {}

private:
    int latency;
public:
    int getLatency() const {
        return latency;
    }

    LatencyOption *setLatency(int latency) {
        LatencyOption::latency = latency;
        return this;
    }
};


#endif //IKARUS_PROJECT_LATENCYOPTION_H
