//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_CLIENTSTATUSOPTION_H
#define IKARUS_PROJECT_CLIENTSTATUSOPTION_H


#include "../Option.h"

enum ClientStatus{
    Client_NONE,            //Default state before first initialization...
    Client_START,           //Initialization and GMainLoop* start
    Client_PLAY,            //Pipeline to GST_STATE_PLAYING
    Client_PAUSE,           //Pipeline to GST_STATE_PAUSED
    Client_STOP             //Release resources(GST_STATE_NULL)

};
class ClientStatusOption: public Option {
public:
    ClientStatusOption(ClientStatus status_value,long timestamp, InformationObjectSupplier *source) :
            Option(OptionType::ClientStatusOption,
                   timestamp,
                   source),
            status(status_value){}
    ~ClientStatusOption()override {}

private:
    ClientStatus status;
public:
    ClientStatus getStatus() const {
        return status;
    }

    ClientStatusOption *setStatus(ClientStatus status) {
        ClientStatusOption::status = status;
        return this;
    }
};


#endif //IKARUS_PROJECT_CLIENTSTATUSOPTION_H
