//
// Created by noreasonexception on 4/6/18.
//

#include <QLabel>
#include <QHBoxLayout>
#include "AlanTwoButtonDialog.h"
#include <QPushButton>
#include <QtWidgets/QMessageBox>
#include "../../../misc/img/generic_paths.h"

AlanTwoButtonDialog::AlanTwoButtonDialog(const QString &titleArea,const QString &iconArea) : AlanSingleOptionDialog(titleArea,iconArea){
}




QWidget *AlanTwoButtonDialog::onGenerateConfigArea() throw (std::exception) {
    return new QLabel("ConfigArea");
}

QWidget *AlanTwoButtonDialog::onGenerateButtonsArea() throw (std::exception) {
    QWidget *dia = new QWidget;
    QLayout *mainLay;
    dia->setLayout(mainLay=new QHBoxLayout);
    mainLay->addWidget(cancelBtn=new QPushButton("Cancel"));
    mainLay->addWidget(okBtn=new QPushButton("OK"));
    return dia;
}
AlanTwoButtonDialog *AlanTwoButtonDialog::getInstance(const QString &titleName,const QString&icon) {
    AlanTwoButtonDialog*ptr=new AlanTwoButtonDialog(titleName,icon);
    return ptr->generic_initializer()?ptr: nullptr;


}

bool AlanTwoButtonDialog::connectionInitializer() try{
    QObject::connect(okBtn,SIGNAL(clicked(bool)),this,SLOT(onOkButtonSlot()));
    QObject::connect(cancelBtn,SIGNAL(clicked(bool)),this,SLOT(onCancelButtonSlot()));
    return true;
}catch (std::exception&e){return false;}

void AlanTwoButtonDialog::onOkButtonSlot() {

}

void AlanTwoButtonDialog::onCancelButtonSlot() {

}

bool AlanTwoButtonDialog::generic_initializer() {
    return AlanSingleOptionDialog::generic_initializer()&&
            connectionInitializer();
}
