//
// Created by noreasonexception on 4/2/18.
//

#include <QVBoxLayout>
#include <QLabel>
#include "LogWidget.h"

LogWidget::LogWidget(Log*l) : QDialog(nullptr),log(l) {
    ////TODO: proper exception handling
    generic_initializer();
    setWindowTitle("Log Details");
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
    return new QVBoxLayout;

}

bool LogWidget::migrateLogData()try{
    onMigrateLogData();
    return true;
}catch (std::exception&e){ return false;}

void LogWidget::onMigrateLogData() {
    main_lay->addWidget(new QLabel("Type :"+log->getLogType()));
    main_lay->addWidget(new QLabel("Submitted on time:"+QString::number(log->getTimestamp())));
    main_lay->addWidget(new QLabel("Description:"+log->getLogDesc()));
}

