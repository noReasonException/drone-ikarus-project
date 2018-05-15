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