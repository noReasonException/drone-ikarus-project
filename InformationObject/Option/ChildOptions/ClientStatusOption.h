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
#ifndef IKARUS_PROJECT_CLIENTSTATUSOPTION_H
#define IKARUS_PROJECT_CLIENTSTATUSOPTION_H


#include "../Option.h"

enum ClientStatus{
    Client_NONE=1,            //Default state before first initialization...
    Client_START=2,           //Initialization and GMainLoop* start
    Client_PLAY=3,            //Pipeline to GST_STATE_PLAYING
    Client_PAUSE=4,           //Pipeline to GST_STATE_PAUSED
    Client_STOP=5             //Release resources(GST_STATE_NULL)

};
/****
 * class ClientStatusOption
 * This object is used in RTSP Subsystem . Specifically it transfers messages about the state of this subsystem (STOP,PLAY,..)
 *
 */
class ClientStatusOption: public Option {
public:
    ClientStatusOption(ClientStatus status_value,long timestamp, InformationObjectSupplier *source) :
            Option(OptionType::ClientStatusOption,
                   timestamp,
                   source),
            status(status_value){}
    ~ClientStatusOption()override {}

    ClientStatus getStatus() const {
        return status;
    }

    ClientStatusOption *setStatus(ClientStatus status) {
        ClientStatusOption::status = status;
        return this;
    }
private:
    ClientStatus status;
};


#endif //IKARUS_PROJECT_CLIENTSTATUSOPTION_H
