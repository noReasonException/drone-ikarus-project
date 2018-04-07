//
// Created by noreasonexception on 4/6/18.
//

#include <iostream>
#include "AlanMultipleChoiceDialog.h"
#include "../../../State/WindowStates/AlanSingleOptionDialog.h"

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

void AlanMultipleChoiceDialog::onOkButtonSlot() {

}


void AlanMultipleChoiceDialog::onCancelButtonSlot() {

}

AlanTwoButtonDialog *AlanMultipleChoiceDialog::getInstance() {
    AlanMultipleChoiceDialogState *s=(new AlanMultipleChoiceDialogState())->setListViewData({"a","b","c"});
    AlanMultipleChoiceDialog *ptr = new AlanMultipleChoiceDialog(s,"Add New...",RESOLUTION_ICON,"+");
    ptr->generic_initializer();
    return ptr;
}


bool AlanMultipleChoiceDialog::generic_initializer() {
    return AlanTwoButtonDialog::generic_initializer()&&additionalButtonInitializer()&&onRestoreState();
}

AlanMultipleChoiceDialogState *AlanMultipleChoiceDialog::onRestoreState() throw(std::exception) {
    auto*state= dynamic_cast<AlanMultipleChoiceDialogState*>(AlanTwoButtonDialog::onRestoreState());
    for(const QString &i:state->getListViewData())listWidget->addItem(i);
    return state;
}

void  AlanMultipleChoiceDialog::onAdditionalButtonSlot() {
    getState()->update();
}

bool AlanMultipleChoiceDialog::additionalButtonInitializer() {
    QObject::connect(additionalButton,SIGNAL(clicked()),this,SLOT(onAdditionalButtonSlot()));
    return true;
}
