//
// Created by noreasonexception on 4/14/18.
//

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
