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
#include <iostream>
#include "AlanSingleOptionDialog.h"
#include "../../misc/img/generic_paths.h"

AlanSingleOptionDialog::AlanSingleOptionDialog(AlanSingleOptionDialogState* Currstate,const QString &title,const QString&icon):
        titleArea(title),
        iconArea(icon),
        state(Currstate){

}
/***
 * @note . if you create a final class derived from AlanSingleOptionDialog , you need to call in the final generic_initializer the restoreState()!
 * @return
 */
bool AlanSingleOptionDialog::generic_initializer() {
    return layoutInitializer();
}
QWidget *AlanSingleOptionDialog::onGenerateTitleArea() throw(std::exception) {
    QWidget*widget=new QWidget;
    QHBoxLayout*lay=new QHBoxLayout();
    widget->setLayout(lay);
    lay->addWidget(new QLabel(titleArea),0,Qt::AlignCenter);
    return widget;
}
QWidget *AlanSingleOptionDialog::onGenerateIconArea() throw (std::exception){
    QLabel*lbl=new QLabel;
    lbl->setPixmap(QPixmap(RESOLUTION_ICON));
    return lbl;
}
bool AlanSingleOptionDialog::layoutInitializer()try {
    setLayout(mainLay=onGenerateLayout());
    mainLay->addWidget(onGenerateLeftmostArea());
    mainLay->addWidget(onGenerateRightMostArea());
    return true;
}catch(std::exception&e){return false;}

QLayout *AlanSingleOptionDialog::onGenerateLayout() throw(std::exception) {
    return new QHBoxLayout();
}

QWidget *AlanSingleOptionDialog::onGenerateLeftmostArea() throw(std::exception) {
    return onGenerateIconArea();
}

QWidget *AlanSingleOptionDialog::onGenerateRightMostArea() throw(std::exception) {
    QWidget*dia=new QWidget;
    QLayout*lay;
    dia->setLayout(lay=new QVBoxLayout);
    lay->addWidget(onGenerateTitleArea());
    lay->addWidget(onGenerateConfigArea());
    lay->addWidget(onGenerateButtonsArea());
    return dia;
}

AlanSingleOptionDialogState * AlanSingleOptionDialog::onRestoreState() throw(std::exception) {
    return state;
}

AlanSingleOptionDialogState *AlanSingleOptionDialog::getState() const {
    return state;
}
/***
 * If you override , always call parent - version
 * @return
 */
