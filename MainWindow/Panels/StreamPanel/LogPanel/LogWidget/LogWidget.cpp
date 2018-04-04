//
// Created by noreasonexception on 4/2/18.
//

#include <QHBoxLayout>
#include "LogWidget.h"

LogWidget::LogWidget(Log*) : QDialog(nullptr) {

}

bool LogWidget::generic_initializer() {
    return initializeLayout();
}

bool LogWidget::initializeLayout()try{
    return false;
}catch (std::exception&e){return false;}

QLayout *LogWidget::onGenerateLayout() {
    QHBoxLayout*mainLay=new QHBoxLayout;

}

