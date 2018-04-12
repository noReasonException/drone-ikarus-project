//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_STATE_H
#define IKARUS_PROJECT_STATE_H

#include <QSettings>
#include <QString>
#include <QtWidgets/QDialog>
#include <iostream>
#include "../Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../../misc/generic_text/AlanMainWindowMisc.h"
#include "../../misc/Suppliers/LogSuppliers.h"

class State {
public:
    State();
    virtual QString createPath()=0;
    virtual void update()=0;
    virtual void load()=0;

    QSettings *settings;


};


#endif //IKARUS_PROJECT_STATE_H
