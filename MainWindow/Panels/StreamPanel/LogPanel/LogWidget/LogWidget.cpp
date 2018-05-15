/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */

    #include <QGridLayout>
#include <QLabel>
#include "LogWidget.h"
#include "../../../../../res/generic_text/Panels/StreamPanel/LogPanel/LogWidget/LogWidgetText.h"

LogWidget::LogWidget(Log*l) : QDialog(nullptr),log(l) {
    ////TODO: proper exception handling
    generic_initializer();
    setWindowTitle(LOG_WIDGET_WINDOW_TITLE);
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
    main_lay->addWidget(new QLabel(LOG_WIDGET_SOURCE_QLABEL),0,0);
    main_lay->addWidget(new QLabel(LOG_WIDGET_TIME_QLABEL),0,1);
    main_lay->addWidget(new QLabel(LOG_WIDGET_TYPE_QLABEL),0,2);
    main_lay->addWidget(new QLabel(LOG_WIDGET_DESTINATION_QLABEL),0,3);
    main_lay->addWidget(new QLabel(log->getSource()->getSupplierName()),1,0);
    main_lay->addWidget(new QLabel(log->getLogType()),1,1);
    main_lay->addWidget(new QLabel(QString::number(log->getTimestamp())),1,2);
    main_lay->addWidget(new QLabel(log->getLogDesc()),1,3);
}

