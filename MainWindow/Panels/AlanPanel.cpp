//
// Created by noreasonexception on 4/3/18.
//

#include <QMessageBox>
#include "AlanPanel.h"
#include "../../misc/errors/AlanPanelErrors.h"
#include "../../misc/generic_text/generic_dialogs.h"

AlanPanel::AlanPanel() : QWidget(nullptr) {
    if(!generic_initializer()){
        QMessageBox::critical(this,GENERIC_INITIALIZATION_ERROR_DIALOG ERR02_DETAILS);
    }
}

bool AlanPanel::generic_initializer() {
    return initializeTitleArea() &&
            initializePanelArea();
}

bool AlanPanel::initializeTitleArea()try {
    this->titleArea=onGenerateTitleArea();
    return true;
}catch(std::exception&e){return false;}

bool AlanPanel::initializePanelArea()try{

    this->panelArea=onGeneratePanelArea();
    return true;

}catch (std::exception&e){return false;}
