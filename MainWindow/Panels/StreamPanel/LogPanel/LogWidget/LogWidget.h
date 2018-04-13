//
// Created by noreasonexception on 4/2/18.
//

#ifndef IKARUS_PROJECT_LOGWIDGET_H
#define IKARUS_PROJECT_LOGWIDGET_H


#include <QString>
#include <QObject>
#include <QDialog>

#include "../../../../../InformationObject/Log/Log.h"

class LogWidget :public QDialog {
public:
    explicit LogWidget(Log*);
    QGridLayout*main_lay;
    Log*log;
private:
    bool generic_initializer();
    bool initializeLayout();
    bool migrateLogData();

protected:
    QGridLayout*onGenerateLayout();
    void onMigrateLogData();

};
#endif //IKARUS_PROJECT_LOGWIDGET_H
