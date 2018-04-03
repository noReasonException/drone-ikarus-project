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

class LogPanel:public StreamPanel {
    Q_OBJECT
public:

    LogPanel();

protected:

};


#endif //IKARUS_PROJECT_LOGPANEL_H
