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
#ifndef IKARUS_PROJECT_STATES_H
#define IKARUS_PROJECT_STATES_H
#define SINGLE_OPTION_DIALOG_STATE_PATH                 "/SINGLEOPTION"
    #define TWO_BUTTONS_DIALOG_STATE_PATH               "/TWOBUTTONS"
        #define SET_LATENCY_DIALOG_STATE_PATH           "/SETLATENCY"
            #define LATENCY_INPUT_QLINEEDIT_STATE       "/LATENCYQLINEEDIT"
        #define SET_RESOLUTION_DIALOG_STATE_PATH        "/SETRESOLUTION"
            #define RESOLUTION_WIDTH_QLINEEDIT_STATE    "/RESOLUTIONWIDTH"
            #define RESOLUTION_HEIGHT_QLINEEDIT_STATE   "/RESOLUTIONHEIGHT"
    #define MULTIPLE_CHOICE_DIALOG_STATE_PATH           "/MULTIPLECHOICE"
            #define MULTIPLE_CHOICES_STATE              "/MULTIPLECHOICESSTATE"
            #define MULTIPLE_STATE_AT_INDEX             "/STATEATINDEX"
        #define SET_DRONE_ADDR_DIALOG_STATE_PATH        "/SETDRONEADDR"
        #define SET_SERVERS_ADDR_DIALOG_STATE_PATH      "/SETSERVERSADDR"

#endif //IKARUS_PROJECT_STATES_H
