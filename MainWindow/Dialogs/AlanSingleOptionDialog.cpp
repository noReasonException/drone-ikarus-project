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

AlanSingleOptionDialog *AlanSingleOptionDialog::getInstance(QString titleName) {
    AlanSingleOptionDialog*ptr=new AlanSingleOptionDialog(titleName);
    return ptr->generic_initializer()?ptr: nullptr;


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

QWidget *AlanSingleOptionDialog::onGenerateIconArea() {
    QLabel*lbl=new QLabel;
    lbl->setPixmap(QPixmap(RESOLUTION_ICON));
    return lbl;
}

QWidget *AlanSingleOptionDialog::onGenerateTitleArea() {
    return new QLabel("TitleArea");
}

QWidget *AlanSingleOptionDialog::onGenerateConfigArea() {
    return new QLabel("ConfigArea");
}

QWidget *AlanSingleOptionDialog::onGenerateButtonsArea() {
    return new QLabel("btnArea");
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
