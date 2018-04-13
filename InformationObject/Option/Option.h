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
    WindowHandlerOption
};
class Option : public InformationObject{
protected:
    Option(OptionType optiontype,long timestamp, InformationObjectSupplier *source);

public:
    OptionType getType() const;

private:
    OptionType type;

};


#endif //IKARUS_PROJECT_OPTION_H
