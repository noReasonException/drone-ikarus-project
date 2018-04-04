//
// Created by noreasonexception on 4/3/18.
//

#include "StreamPanel.h"
#include "../../../misc/generic_text/generic_dialogs.h"
#include "../../../misc/errors/AlanPanelErrors.h"
#include <QLayout>
#include <QMessageBox>

StreamPanel* StreamPanel::instance= nullptr;

bool StreamPanel::generic_initializer() {
    return AlanPanel::generic_initializer()&&
            initializeListView();
}

bool StreamPanel::initializeListView() try {
    AlanPanel::mainLayout->addWidget(listView=onGenerateListView());
    return true;
}catch(std::exception&e){return false;}

QListView *StreamPanel::onGenerateListView() {
    return new QListView;
}

StreamPanel::StreamPanel(const QString &str) : AlanPanel(str){}

StreamPanel *StreamPanel::getInstance(QString title) {
    if(StreamPanel::instance)return StreamPanel::instance;
    StreamPanel*pnl=new StreamPanel(title);
    if(!pnl->generic_initializer()){
        QMessageBox::warning(nullptr,GENERIC_INITIALIZATION_ERROR_DIALOG,ERR02_DETAILS);
        return nullptr;
    }
    StreamPanel::instance=pnl;
    return pnl;
}
