//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_ALANABOUTDIALOG_H
#define IKARUS_PROJECT_ALANABOUTDIALOG_H


#include "../AlanSingleOptionDialog.h"
#include "../../../misc/img/generic_paths.h"
#include <QPushButton>

class AlanAboutDialog : public AlanSingleOptionDialog {
private:
    QPushButton*goBackBtn;
public:
    AlanAboutDialog()
            : AlanSingleOptionDialog(new AlanSingleOptionDialogState, "About", DRONE_ADDR_ICON) {}

protected:
    QWidget *onGenerateConfigArea() throw(std::exception)override {
        return new QLabel("Alan is a RTSP Client...<br> It is specialized in real-time streaming for drones, this is a test version(0.0.1)<br>By noReasonException(Stefanos Stefanou) :) ");
    }

    QWidget *onGenerateButtonsArea()throw(std::exception) override {
        return goBackBtn=new QPushButton("Go Back");
    }

    bool connectionInitializer(){
        QObject::connect(goBackBtn,SIGNAL(clicked(bool)),this,SLOT(close()));
    }
    bool generic_initializer() override {
        return AlanSingleOptionDialog::generic_initializer();/*&&
               connectionInitializer();*/
    }
};


#endif //IKARUS_PROJECT_ALANABOUTDIALOG_H
