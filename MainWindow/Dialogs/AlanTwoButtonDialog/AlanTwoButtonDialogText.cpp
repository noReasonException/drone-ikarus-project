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
#include "../../State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h"
#include "../../../misc/generic_text/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialogText.h"

AlanTwoButtonDialog::AlanTwoButtonDialog(AlanTwoButtonsDialogState* state,const QString &titleArea,const QString &iconArea) : AlanSingleOptionDialog(state,titleArea,iconArea){
}

QWidget *AlanTwoButtonDialog::onGenerateButtonsArea() throw (std::exception) {
    QWidget *dia = new QWidget;
    QLayout *mainLay;
    dia->setLayout(mainLay=new QHBoxLayout);
    mainLay->addWidget(cancelBtn=new QPushButton(ALAN_TWO_BUTTON_DIALOG_BTN1));
    mainLay->addWidget(okBtn=new QPushButton(ALAN_TWO_BUTTON_DIALOG_BTN2));
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

AlanTwoButtonsDialogState *AlanTwoButtonDialog::onRestoreState()  throw(std::exception){
    return dynamic_cast<AlanTwoButtonsDialogState*>(AlanSingleOptionDialog::onRestoreState());
}
AlanTwoButtonsDialogState *AlanTwoButtonDialog::onSaveState() throw(std::exception){
    return dynamic_cast<AlanTwoButtonsDialogState*>(AlanSingleOptionDialog::onSaveState());
}
void AlanTwoButtonDialog::onOkButtonSlot() {
    onSaveState();
    close();
}

void AlanTwoButtonDialog::onCancelButtonSlot() {
    onSaveState();
    close();
}
