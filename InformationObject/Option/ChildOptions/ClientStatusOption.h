//
// Created by noreasonexception on 4/14/18.
//

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
