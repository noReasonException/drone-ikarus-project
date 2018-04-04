//
// Created by noreasonexception on 4/3/18.
//

#include "StreamPanel.h"
#include "../../../misc/generic_text/generic_dialogs.h"
#include "../../../misc/errors/AlanPanelErrors.h"
#include <QLayout>
#include <QMessageBox>
#include <QListWidget>

StreamPanel* StreamPanel::instance= nullptr;
StreamPanel::StreamPanel(const QString &title) : AlanPanel(title){

}

bool StreamPanel::initializeSlots() {
    QObject::connect(listView,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onDataClicked(QListWidgetItem *)));
    return true;
}

/***
 * @see the AlanPanel::generic_initializer comment section for details...
 */
bool StreamPanel::generic_initializer() {
    return AlanPanel::generic_initializer()&&
            initializeListView()&&
            initializeSlots();
}
/***
 * A simple wrapper over onGenerateListView ,it checks if this function is called successfully ,
 * and informs the upper error-protection layer (the generic_initializer() in case of error
 *
 * @note why we dont initialize directly from here?
 * @see the comment section of AlanMainWindow::initializeMenu
 * @return true if everything is okay , false otherwise
 *
***/
bool StreamPanel::initializeListView() try {
    AlanPanel::mainLayout->addWidget(listView=onGenerateListView());
    return true;
}catch(std::exception&e){return false;}
/***
 * onGenerateListView() does the real job of initializing and returning a QListView
 * destined to be in the main layout of StreamPanel.
 * @return a new QListView
 *  * @note this function HAS NOT responsibility of assigning the QListView in AlanPanel layout.
 * this means that commands like...
 *                      this->mainLayout->addWidget(...)
 * ...is strictly forbidden (To maintain a elegant code)
 */
QListWidget *StreamPanel::onGenerateListView() {
    return new QListWidget;
}


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

QListWidget *StreamPanel::getListView() const {
    return listView;
}

void StreamPanel::onDataClicked(QListWidgetItem *ptr) {
    int log_position=ptr->listWidget()->row(ptr);
}
