//
// Created by noreasonexception on 4/14/18.
//

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
