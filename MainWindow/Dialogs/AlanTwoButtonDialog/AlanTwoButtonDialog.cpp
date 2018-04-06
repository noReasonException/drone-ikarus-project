//
// Created by noreasonexception on 4/6/18.
//

#include <QtWidgets/QLabel>
#include "AlanTwoButtonDialog.h"
#include "../../../misc/img/generic_paths.h"

AlanTwoButtonDialog::AlanTwoButtonDialog(const QString titleArea) : AlanSingleOptionDialog(titleArea){
}

QWidget *AlanTwoButtonDialog::onGenerateIconArea() {
    QLabel*lbl=new QLabel;
    lbl->setPixmap(QPixmap(RESOLUTION_ICON));
    return lbl;
}

QWidget *AlanTwoButtonDialog::onGenerateTitleArea() {
    return new QLabel("TitleArea");
}

QWidget *AlanTwoButtonDialog::onGenerateConfigArea() {
    return new QLabel("ConfigArea");
}

QWidget *AlanTwoButtonDialog::onGenerateButtonsArea() {
    return new QLabel("btnArea");
}
AlanTwoButtonDialog *AlanTwoButtonDialog::getInstance(const QString &titleName) {
    AlanTwoButtonDialog*ptr=new AlanTwoButtonDialog(titleName);
    return ptr->generic_initializer()?ptr: nullptr;


}