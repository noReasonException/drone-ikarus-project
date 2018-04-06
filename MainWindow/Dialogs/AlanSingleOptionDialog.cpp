//
// Created by noreasonexception on 4/5/18.
//

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QIcon>
#include <QWindow>
#include <QWindow>
#include "AlanSingleOptionDialog.h"
#include "../../misc/img/generic_paths.h"

AlanSingleOptionDialog::AlanSingleOptionDialog(QString) {

}
bool AlanSingleOptionDialog::generic_initializer() {
    return layoutInitializer();
}

bool AlanSingleOptionDialog::layoutInitializer()try {
    setLayout(mainLay=onGenerateLayout());
    mainLay->addWidget(onGenerateLeftmostArea());
    mainLay->addWidget(onGenerateRightMostArea());
    return true;
}catch(std::exception&e){return false;}

QLayout *AlanSingleOptionDialog::onGenerateLayout() {
    return new QHBoxLayout();
}

QLayout *AlanSingleOptionDialog::getMainLay() const {
    return mainLay;
}

void AlanSingleOptionDialog::setMainLay(QLayout *mainLay) {
    AlanSingleOptionDialog::mainLay = mainLay;
}

QString *AlanSingleOptionDialog::getTitleArea() const {
    return titleArea;
}

void AlanSingleOptionDialog::setTitleArea(QString *titleArea) {
    AlanSingleOptionDialog::titleArea = titleArea;
}

QWidget *AlanSingleOptionDialog::onGenerateLeftmostArea() {
    return onGenerateIconArea();
}

QWidget *AlanSingleOptionDialog::onGenerateRightMostArea() {
    QDialog*dia=new QDialog;
    QLayout*lay;
    dia->setLayout(lay=new QVBoxLayout);
    lay->addWidget(onGenerateTitleArea());
    lay->addWidget(onGenerateConfigArea());
    lay->addWidget(onGenerateButtonsArea());
    return dia;
}
