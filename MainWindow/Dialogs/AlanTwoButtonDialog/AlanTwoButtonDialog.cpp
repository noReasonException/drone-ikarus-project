//
// Created by noreasonexception on 4/6/18.
//

#include <QLabel>
#include <QHBoxLayout>
#include "AlanTwoButtonDialog.h"
#include <QPushButton>
#include <QtWidgets/QMessageBox>
#include <iostream>
#include "../../../misc/img/generic_paths.h"

AlanTwoButtonDialog::AlanTwoButtonDialog(AlanTwoButtonsDialogState state,const QString &titleArea,const QString &iconArea) : AlanSingleOptionDialog(state,titleArea,iconArea){
}

QWidget *AlanTwoButtonDialog::onGenerateButtonsArea() throw (std::exception) {
    QWidget *dia = new QWidget;
    QLayout *mainLay;
    dia->setLayout(mainLay=new QHBoxLayout);
    mainLay->addWidget(cancelBtn=new QPushButton("Cancel"));
    mainLay->addWidget(okBtn=new QPushButton("OK"));
    return dia;
}


bool AlanTwoButtonDialog::connectionInitializer() try{
    QObject::connect(okBtn,SIGNAL(clicked(bool)),this,SLOT(onOkButtonSlot()));
    QObject::connect(cancelBtn,SIGNAL(clicked(bool)),this,SLOT(onCancelButtonSlot()));
    return true;
}catch (std::exception&e){return false;}


bool AlanTwoButtonDialog::generic_initializer() {
    return AlanSingleOptionDialog::generic_initializer()&&
            connectionInitializer();
}

AlanTwoButtonsDialogState& AlanTwoButtonDialog::onRestoreState() throw(std::exception) {
    AlanTwoButtonsDialogState &stat=(AlanTwoButtonsDialogState&)AlanSingleOptionDialog::onRestoreState();

    return stat;


}
