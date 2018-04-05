//
// Created by noreasonexception on 4/5/18.
//

#include <QVBoxLayout>
#include <QLabel>
#include "AlanSingleOptionDialog.h"

AlanSingleOptionDialog::AlanSingleOptionDialog(QString str) {
    titleAreaText=str;
}

AlanSingleOptionDialog *AlanSingleOptionDialog::getInstance(QString str){
    auto*retval=new AlanSingleOptionDialog(str);
    return retval->generic_initializer()?retval: nullptr;
}

bool AlanSingleOptionDialog::generic_initializer() {
    return layoutInitializer()&&titleAreaInitializer();
}

bool AlanSingleOptionDialog::layoutInitializer()try {
    setLayout(onGenerateLayout());
    return true;
}catch (std::exception&e){return false;}

QLayout *AlanSingleOptionDialog::onGenerateLayout() {
    return new QVBoxLayout();
}

QWidget *AlanSingleOptionDialog::onGenerateTitleArea() {
    return new QLabel(titleAreaText);
}

bool AlanSingleOptionDialog::titleAreaInitializer()try{
    layout()->addWidget(onGenerateTitleArea());
    return true;
}catch (std::exception&e){ return false;}

const QString &AlanSingleOptionDialog::getTitleAreaText() const {
    return titleAreaText;
}

void AlanSingleOptionDialog::setTitleAreaText(const QString &titleAreaText) {
    AlanSingleOptionDialog::titleAreaText = titleAreaText;
}
