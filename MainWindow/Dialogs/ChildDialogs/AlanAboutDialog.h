//
// Created by noreasonexception on 4/8/18.
//

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
