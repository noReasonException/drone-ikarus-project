//
// Created by noreasonexception on 4/2/18.
//

#ifndef IKARUS_PROJECT_LOGPANEL_H
#define IKARUS_PROJECT_LOGPANEL_H


#include <QObject>
#include <QWidget>

class LogPanel:public QWidget {
    Q_OBJECT
public:
    QLabel *titleLabel;

    LogPanel();

private:
    void generic_initializer();
    void title_initializer();
};


#endif //IKARUS_PROJECT_LOGPANEL_H
