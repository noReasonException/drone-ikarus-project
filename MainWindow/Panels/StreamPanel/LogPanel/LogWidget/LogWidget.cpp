//
// Created by noreasonexception on 4/2/18.
//

    #include <QGridLayout>
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

QGridLayout *LogWidget::onGenerateLayout() {
        return new QGridLayout;

}

bool LogWidget::migrateLogData()try{
    onMigrateLogData();
    return true;
}catch (std::exception&e){ return false;}

void LogWidget::onMigrateLogData() {
    main_lay->addWidget(new QLabel("Source"),0,0);
    main_lay->addWidget(new QLabel("Type"),0,1);
    main_lay->addWidget(new QLabel("Time"),0,2);
    main_lay->addWidget(new QLabel("Description"),0,3);
    main_lay->addWidget(new QLabel(log->getSource()->getSupplierName()),1,0);
    main_lay->addWidget(new QLabel(log->getLogType()),1,1);
    main_lay->addWidget(new QLabel(QString::number(log->getTimestamp())),1,2);
    main_lay->addWidget(new QLabel(log->getLogDesc()),1,3);
}

