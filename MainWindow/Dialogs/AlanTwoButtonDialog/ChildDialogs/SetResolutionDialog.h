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
#ifndef IKARUS_PROJECT_SETRESOLUTIONDIALOG_H
#define IKARUS_PROJECT_SETRESOLUTIONDIALOG_H


#include <QtWidgets/QMessageBox>
#include "../AlanTwoButtonDialog.h"
#include "../../../../res/img/generic_paths.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetResolutionDialogState.h"
#include "../../../../res/generic_text/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialogText.h"

class SetResolutionDialog : public AlanTwoButtonDialog {
public:
    SetResolutionDialog(AlanTwoButtonsDialogState *state,OptionSupplier*supplier):
            AlanTwoButtonDialog(state,RESOLUTION_DIALOG_TITLE,RESOLUTION_ICON),
            rtspClientOptionSupplier(supplier){}
    virtual ~SetResolutionDialog(){delete rtspClientOptionSupplier;}


private:
    QLineEdit *width;
    QLineEdit *height;
    OptionSupplier*rtspClientOptionSupplier;

    QWidget *onGenerateConfigArea() throw (std::exception)override {
        QWidget*widget=new QWidget;
        QGridLayout*lay;
        widget->setLayout(lay=new QGridLayout);
        lay->addWidget(new QLabel(SET_RESOLUTION_DIALOG_WIDTH_QLABEL),0,0);
        lay->addWidget(new QLabel(SET_RESOLUTION_DIALOG_HEIGHT_QLABEL),1,0);
        lay->addWidget(width=new QLineEdit,0,1);
        lay->addWidget(height=new QLineEdit,1,1);
        return widget;


    }

protected:
    SetResolutionDialogState *onRestoreState() throw(std::exception)override {
            SetResolutionDialogState*thisState= dynamic_cast<SetResolutionDialogState*>
                                (AlanTwoButtonDialog::onRestoreState());
            thisState->load();
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
            getRtspClientOptionSupplier()->send(new class ResolutionOption(
                width->text().toInt(),
                height->text().toInt(),
                time(NULL),
                getRtspClientOptionSupplier()));
            return thisState;
    }

    bool generic_initializer() override {
            return AlanTwoButtonDialog::generic_initializer()&&
                   onRestoreState();
    }
    OptionSupplier *getRtspClientOptionSupplier() const {
        return rtspClientOptionSupplier;
    }


};


#endif //IKARUS_PROJECT_SETRESOLUTIONDIALOG_H
