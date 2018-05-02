//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_RESOLUTIONOPTION_H
#define IKARUS_PROJECT_RESOLUTIONOPTION_H


#include "../Option.h"
/****
 * class ResolutionOption
 * This object is used in RTSP Subsystem . Specifically it transfers messages about the video resolution
 *
 */
class ResolutionOption: public Option {
public:
    ResolutionOption(int width_value,int height_value,long timestamp, InformationObjectSupplier *source) :
            Option(OptionType::ResolutionOption,
                   timestamp,
                   source),
            width(width_value),
            height(height_value){}
    ~ResolutionOption() override {}

private:
    int width,height;
public:
    int getWidth() const {
        return width;
    }

    ResolutionOption* setWidth(int width) {
        ResolutionOption::width = width;
        return this;
    }

    int getHeight() const {
        return height;
    }

    ResolutionOption* setHeight(int height) {
        ResolutionOption::height = height;
        return this;
    }
};


#endif //IKARUS_PROJECT_RESOLUTIONOPTION_H
