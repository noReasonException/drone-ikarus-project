//
// Created by noreasonexception on 4/14/18.
//

#include "Option.h"

Option::Option(OptionType optiontype,long timestamp, InformationObjectSupplier *source) :
        InformationObject(timestamp, source),
        type(optiontype) {}

OptionType Option::getType() const {
    return type;
}
