//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETRESOLUTIONDIALOG_H
#define IKARUS_PROJECT_SETRESOLUTIONDIALOG_H


#include <QtWidgets/QMessageBox>
#include "../AlanTwoButtonDialog.h"
#include "../../../../misc/img/generic_paths.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h"

class SetResolutionDialog : public AlanTwoButtonDialog {
public:
    SetResolutionDialog(AlanTwoButtonsDialogState *state):AlanTwoButtonDialog(state,RESOLUTION_DIALOG_TITLE,RESOLUTION_ICON){}

private:
    QWidget *onGenerateConfigArea() throw (std::exception)override {
        QWidget*widget=new QWidget;
        QGridLayout*lay;
        widget->setLayout(lay=new QGridLayout);
        lay->addWidget(new QLabel("Width:"),0,0);
        lay->addWidget(new QLabel("Height:"),1,0);
        lay->addWidget(new QLineEdit,0,1);
        lay->addWidget(new QLineEdit,1,1);
        return widget;


    }

};


#endif //IKARUS_PROJECT_SETRESOLUTIONDIALOG_H
