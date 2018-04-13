//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_CLIENTSTATUSOPTION_H
#define IKARUS_PROJECT_CLIENTSTATUSOPTION_H


#include "../Option.h"

enum ClientStatus{
    Client_START,
    Client_PLAY,
    Client_PAUSE,
    Client_STOP

};
class ClientStatusOption: public Option {
public:
    ClientStatusOption(ClientStatus status_value,long timestamp, InformationObjectSupplier *source) :
            Option(OptionType::ClientStatusOption,
                   timestamp,
                   source),
            status(status_value){}

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
