//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_STATE_H
#define IKARUS_PROJECT_STATE_H

#include <QSettings>
#include <QString>
#include <QtWidgets/QDialog>

class State {
public:
    State()= default;
    virtual void update()=0;
    virtual QString createPath()=0;

    State*setWrapperWidget(QWidget*ptr){wrapperWidget=ptr;return this;}
    QWidget*getwrapperWidget(){ return wrapperWidget;}
protected:
    static QSettings settings;
    QWidget*wrapperWidget;

};


#endif //IKARUS_PROJECT_STATE_H
