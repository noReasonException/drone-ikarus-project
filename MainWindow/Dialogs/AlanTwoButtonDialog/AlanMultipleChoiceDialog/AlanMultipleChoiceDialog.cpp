//
// Created by noreasonexception on 4/6/18.
//

#include <iostream>
#include "AlanMultipleChoiceDialog.h"
#include "../../../State/WindowStates/AlanSingleOptionDialogState.h"
#include "ChildDialogs/SetDroneAddrDialog.h"
#include "ChildDialogs/SetServersAddrDialog.h"

bool AlanMultipleChoiceDialog::generic_initializer() {
    return AlanTwoButtonDialog::generic_initializer()&& additionalButtonsInitializer()&&onRestoreState();
}



QWidget *AlanMultipleChoiceDialog::onGenerateConfigArea()  throw (std::exception){

    QWidget *widget = new QWidget();                       //Main Config Widget
    QWidget *newData = new QWidget();                      //Add new data subwidget
    QLayout *lay = new QVBoxLayout();                      //Setup Layout;
    QLayout *newData_Layout = new QHBoxLayout;


    widget->setLayout(lay);                             //Pass Layouts
    newData->setLayout(newData_Layout);

    lay->addWidget(listWidget=new QListWidget);                    //Add QListWidget in Config Area
    newData_Layout->addWidget(new QLineEdit);
    newData_Layout->addWidget(additionalButton=new QPushButton(pushButtonText));
    lay->addWidget(newData);                            //Add new configuration in bottom of config area
    return widget;

}

AlanMultipleChoiceDialogState *AlanMultipleChoiceDialog::onRestoreState() throw(std::exception) {
    auto*state= dynamic_cast<AlanMultipleChoiceDialogState*>(AlanTwoButtonDialog::onRestoreState());

    return state;
}




bool AlanMultipleChoiceDialog::additionalButtonsInitializer() {
    QObject::connect(additionalButton,SIGNAL(clicked()),this,SLOT(onAdditionalButtonSlot()));
    QObject::connect(listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onClickedChoiceSlot(QListWidgetItem *)));

    return true;
}

