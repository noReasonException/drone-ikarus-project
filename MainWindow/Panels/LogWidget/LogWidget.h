//
// Created by noreasonexception on 4/2/18.
//

#ifndef IKARUS_PROJECT_LOGWIDGET_H
#define IKARUS_PROJECT_LOGWIDGET_H


#include <QString>
#include <QObject>
class LogWidget {
private:
    long timestamp;
    QString type;
    QString desc;
    LogWidget()= default;
    /***
     * Why the Builder class if friend and not inner? the QT's MOC system(Meta Object Systems) not supports inner classes , when
     * we invoke the .sendToLogPanel() , the Builder is send a signal to LogPanel , with the brand new LogWidget! . the signals&slots
     * mechanism is based on MOC subsystem , so this condition enforses me to violate the rules of good c++ programmer and declare the
     * Builder 'friend class'
     */
    friend class Builder;

private:

public:

};

class Builder:public QObject{
Q_OBJECT;
public:
    LogWidget*object;
    Builder();

    Builder  *setTimestamp(long timestamp);

    Builder  *setType(const QString &type);

    Builder  *setDesc(const QString &desc);

    LogWidget*create();
    bool sendToLogPanel();

};
#endif //IKARUS_PROJECT_LOGWIDGET_H
