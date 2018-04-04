//
// Created by noreasonexception on 4/3/18.
//

#include <QMessageBox>
#include <QString>
#include <QVBoxLayout>
#include "AlanPanel.h"
#include "../../misc/errors/AlanPanelErrors.h"
#include "../../misc/generic_text/generic_dialogs.h"
AlanPanel* AlanPanel::instance= nullptr;
AlanPanel::AlanPanel(QString str) : QWidget(nullptr),title(str) {

}

bool AlanPanel::generic_initializer() {
    return initializeLayout()&&
            initializeTitleArea();
}

bool AlanPanel::initializeTitleArea()try {
    mainLayout->addWidget(this->titleArea=onGenerateTitleArea());
    return true;
}catch(std::exception&e){return false;}

QWidget *AlanPanel::onGenerateTitleArea() throw(std::exception){
    return new QLabel(title);
}

AlanPanel *AlanPanel::getInstance(QString title) {
    if(instance)
        return instance;
    AlanPanel*pnl=new AlanPanel(title);

    if(!pnl->generic_initializer()){
        QMessageBox::warning(nullptr,GENERIC_INITIALIZATION_ERROR_DIALOG,ERR02_DETAILS);
        return nullptr;
    }
    instance=pnl;
    return pnl;

}

bool AlanPanel::initializeLayout() {
    setLayout(mainLayout=new QVBoxLayout());
    return true;

}
