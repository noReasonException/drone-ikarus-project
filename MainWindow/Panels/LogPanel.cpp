//
// Created by noreasonexception on 4/2/18.
//

#include <QHBoxLayout>
#include <QLabel>
#include "LogPanel.h"

LogPanel::LogPanel() {
    generic_initializer();

}

bool LogPanel::generic_initializer() {
    return initializeLayout()&&
           initializeTitleWidget();

}

bool LogPanel::initializeLayout() {
    try{
        setLayout(main_lay=new QVBoxLayout());
        return true;
    }catch (std::exception&e){return false;}
}

bool LogPanel::initializeTitleWidget()  {
    try{
        main_lay->addWidget(onGenerateTitleWidget(),0,Qt::AlignTop);

        return true;
    }catch (std::exception&e){return false;}
}

QWidget *LogPanel::onGenerateTitleWidget() {
    return new QLabel("Logs");

}

bool LogPanel::initializeLogWidgets() {
    return false;
}


