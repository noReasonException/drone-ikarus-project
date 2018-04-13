//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_WINDOWHANDLEOPTION_H
#define IKARUS_PROJECT_WINDOWHANDLEOPTION_H


#include "../Option.h"

class WindowHandleOption: public Option {
public:
    WindowHandleOption(int windowHandleValue,long timestamp, InformationObjectSupplier *source):
            Option(OptionType::WindowHandlerOption,timestamp,source){

    }


};


#endif //IKARUS_PROJECT_WINDOWHANDLEOPTION_H