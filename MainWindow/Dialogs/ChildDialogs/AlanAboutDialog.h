//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_ALANABOUTDIALOG_H
#define IKARUS_PROJECT_ALANABOUTDIALOG_H


#include "../AlanSingleOptionDialog.h"
#include "../../../misc/img/generic_paths.h"
#include <QPushButton>

class AlanAboutDialog : public AlanSingleOptionDialog {
public:
    AlanAboutDialog()
            : AlanSingleOptionDialog(new AlanSingleOptionDialogState, "About", DRONE_ADDR_ICON) {}

protected:
    QWidget *onGenerateConfigArea() throw(std::exception)override {
        return new QLabel("About...stuff..");
    }

    QWidget *onGenerateButtonsArea()throw(std::exception) override {
        return new QPushButton("Go Back");
    }
};


#endif //IKARUS_PROJECT_ALANABOUTDIALOG_H
