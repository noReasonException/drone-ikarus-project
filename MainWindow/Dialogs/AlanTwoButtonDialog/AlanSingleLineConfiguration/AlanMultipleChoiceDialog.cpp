//
// Created by noreasonexception on 4/6/18.
//

#include <iostream>
#include "AlanMultipleChoiceDialog.h"

QWidget *AlanMultipleChoiceDialog::onGenerateConfigArea()  throw (std::exception){

    QWidget *widget = new QWidget();                       //Main Config Widget
    QWidget *newData = new QWidget();                      //Add new data subwidget
    QLayout *lay = new QVBoxLayout();                      //Setup Layout;
    QLayout *newData_Layout = new QHBoxLayout;


    widget->setLayout(lay);                             //Pass Layouts
    newData->setLayout(newData_Layout);

    lay->addWidget(listWidget=new QListWidget);                    //Add QListWidget in Config Area
    newData_Layout->addWidget(new QLineEdit);
    newData_Layout->addWidget(new QPushButton(pushButtonText));
    lay->addWidget(newData);                            //Add new configuration in bottom of config area
    return widget;

}

void AlanMultipleChoiceDialog::onOkButtonSlot() {
    QMessageBox::warning(nullptr, "he", "he");
}


void AlanMultipleChoiceDialog::onCancelButtonSlot() {

}

AlanTwoButtonDialog *AlanMultipleChoiceDialog::getInstance() {
    AlanMultipleChoiceDialogState stat;
    AlanMultipleChoiceDialog *ptr = new AlanMultipleChoiceDialog(stat,"Add New...",RESOLUTION_ICON,"+");
    ptr->generic_initializer();
    return ptr;
}

AlanMultipleChoiceDialogState& AlanMultipleChoiceDialog::onRestoreState() throw(std::exception) {
    AlanMultipleChoiceDialogState &retval=(AlanMultipleChoiceDialogState&)AlanTwoButtonDialog::onRestoreState();
    for(QString &i:retval.MultipleChoices)//listWidget->addItem(i);
    return retval;
}
