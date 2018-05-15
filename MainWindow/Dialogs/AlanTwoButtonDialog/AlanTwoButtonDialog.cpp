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
#include <QLabel>
#include <QHBoxLayout>
#include "AlanTwoButtonDialog.h"
#include <QPushButton>
#include <QtWidgets/QMessageBox>
#include "../../../res/generic_text/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialogText.h"

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
