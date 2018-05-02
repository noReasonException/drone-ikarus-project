//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_WINDOWHANDLEOPTION_H
#define IKARUS_PROJECT_WINDOWHANDLEOPTION_H


#include "../Option.h"
/****
 * class WindowHandleOption
 * This object is used in RTSP Subsystem . Specifically it transfers messages about the X window handle to display video
 */
class WindowHandleOption: public Option {
public:
    WindowHandleOption(int windowHandleValue,long timestamp, InformationObjectSupplier *source):
            Option(OptionType::WindowHandlerOption,timestamp,source),
            windowHanle(windowHandleValue){}
    ~WindowHandleOption()override {}

private:
    int windowHanle;
public:
    int getWindowHanle() const {
        return windowHanle;
    }


};


#endif //IKARUS_PROJECT_WINDOWHANDLEOPTION_H