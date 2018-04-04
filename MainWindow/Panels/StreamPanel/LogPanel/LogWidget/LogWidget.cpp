//
// Created by noreasonexception on 4/2/18.
//

#include "LogWidget.h"

Builder* Builder::setTimestamp(long timestamp) {
    object->timestamp = timestamp;
    return this;
}

Builder* Builder::setType(const QString &type) {
    object->type = type;
    return this;
}

Builder* Builder::setDesc(const QString &desc) {
    object->desc = desc;
    return this;
}

Builder::Builder() {
    object=new LogWidget();

}

LogWidget *Builder::create() {
    return object;
}

bool Builder::sendToLogPanel() {
    return false;
}
