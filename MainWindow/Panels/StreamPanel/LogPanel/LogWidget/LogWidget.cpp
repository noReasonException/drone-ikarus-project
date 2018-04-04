//
// Created by noreasonexception on 4/2/18.
//

#include <QHBoxLayout>
#include <QLabel>
#include "LogWidget.h"

LogWidget::LogWidget(Log*l) : QDialog(nullptr),log(l) {
    ///TODO proper exception handling
}

bool LogWidget::generic_initializer() {
    return initializeLayout()&&
            migrateLogData();
}

bool LogWidget::initializeLayout()try{
    setLayout(main_lay=onGenerateLayout());
    return true;
}catch (std::exception&e){return false;}

QLayout *LogWidget::onGenerateLayout() {
    return new QHBoxLayout;

}

bool LogWidget::migrateLogData()try{
    onMigrateLogData();
    return true;
}catch (std::exception&e){ return false;}

void LogWidget::onMigrateLogData() {
    main_lay->addWidget(new QLabel(log->getLogType()));
    main_lay->addWidget(new QLabel(QString::number(log->getTimestamp())));
    main_lay->addWidget(new QLabel(log->getLogDesc()));
}

