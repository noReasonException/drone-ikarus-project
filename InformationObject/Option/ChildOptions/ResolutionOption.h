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
