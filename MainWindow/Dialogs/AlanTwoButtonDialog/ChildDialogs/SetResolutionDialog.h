//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETRESOLUTIONDIALOG_H
#define IKARUS_PROJECT_SETRESOLUTIONDIALOG_H


#include <QtWidgets/QMessageBox>
#include "../AlanTwoButtonDialog.h"
#include "../../../../misc/img/generic_paths.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetResolutionDialogState.h"

class SetResolutionDialog : public AlanTwoButtonDialog {
public:
    SetResolutionDialog(AlanTwoButtonsDialogState *state):AlanTwoButtonDialog(state,RESOLUTION_DIALOG_TITLE,RESOLUTION_ICON){}

private:
    QLineEdit *width;
    QLineEdit *height;

    QWidget *onGenerateConfigArea() throw (std::exception)override {
        QWidget*widget=new QWidget;
        QGridLayout*lay;
        widget->setLayout(lay=new QGridLayout);
        lay->addWidget(new QLabel("Width:"),0,0);
        lay->addWidget(new QLabel("Height:"),1,0);
        lay->addWidget(width=new QLineEdit,0,1);
        lay->addWidget(height=new QLineEdit,1,1);
        return widget;


    }

protected:
    SetResolutionDialogState *onRestoreState() throw(std::exception)override {
            SetResolutionDialogState*thisState= dynamic_cast<SetResolutionDialogState*>
                                (AlanTwoButtonDialog::onRestoreState());
            width->setText(thisState->width);
            height->setText(thisState->height);
            return thisState;
    }
    SetResolutionDialogState *onSaveState() throw(std::exception)override {
            SetResolutionDialogState*thisState= dynamic_cast<SetResolutionDialogState*>
                                (AlanTwoButtonDialog::onSaveState());
            thisState->width=width->text();
            thisState->height=height->text();
            thisState->update();
            return thisState;
    }

    bool generic_initializer() override {
            return AlanTwoButtonDialog::generic_initializer()&&
                   onRestoreState();
    }

};


#endif //IKARUS_PROJECT_SETRESOLUTIONDIALOG_H
