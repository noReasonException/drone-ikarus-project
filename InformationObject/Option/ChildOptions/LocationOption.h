//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_LOCATIONOPTION_H
#define IKARUS_PROJECT_LOCATIONOPTION_H


#include "../Option.h"
/****
 * class LocationOption
 * This object is used in RTSP Subsystem . Specifically it transfers messages about the ip address of server
 *
 */
class LocationOption: public Option {
public:
    LocationOption(QString ip, long timestamp, InformationObjectSupplier *source):
            Option(OptionType::LocationOption, timestamp, source),ipLocation(ip){}
    ~LocationOption()override {}
    const QString &getIpLocation() const { return ipLocation; }

private:
    QString ipLocation;

};


#endif //IKARUS_PROJECT_LOCATIONOPTION_H
