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
#ifndef IKARUS_PROJECT_ALANABOUTDIALOG_H
#define IKARUS_PROJECT_ALANABOUTDIALOG_H


#include "../AlanSingleOptionDialog.h"
#include "../../../res/img/generic_paths.h"
#include "../../../res/generic_text/Dialogs/ChildDialogs/AlanAboutDialogText.h"
#include <QPushButton>

class AlanAboutDialog : public AlanSingleOptionDialog {
private:
    QPushButton*goBackBtn;
public:
    AlanAboutDialog()
            : AlanSingleOptionDialog(new AlanSingleOptionDialogState, ABOUT_DIALOG_TITLE, DRONE_ADDR_ICON) {}

protected:
    QWidget *onGenerateConfigArea() throw(std::exception)override {
        return new QLabel(ABOUT_DIALOG);
    }

    QWidget *onGenerateButtonsArea()throw(std::exception) override {
        return goBackBtn=new QPushButton(ABOUT_DIALOG_BTN);
    }

    bool connectionInitializer(){
        QObject::connect(goBackBtn,SIGNAL(clicked(bool)),this,SLOT(close()));
        return true;
    }
    bool generic_initializer() override {
        return AlanSingleOptionDialog::generic_initializer()&&
               connectionInitializer();
    }
};


#endif //IKARUS_PROJECT_ALANABOUTDIALOG_H
