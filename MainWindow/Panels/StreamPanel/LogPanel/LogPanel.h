//
// Created by noreasonexception on 4/2/18.
//

#ifndef IKARUS_PROJECT_LOGPANEL_H
#define IKARUS_PROJECT_LOGPANEL_H


#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "../StreamPanel.h"
#include "../../../Consumer/LogConsumer/LogConsumer.h"
#include "../../../Interfaces/LogSupplierFactory.h"

class LogPanel:public StreamPanel, public LogConsumer,public LogSupplierFactory {


};


#endif //IKARUS_PROJECT_LOGPANEL_H
