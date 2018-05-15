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
#include "StreamPanel.h"
#include "../../../res/generic_text/generic_dialogs.h"
#include "../../../res/errors/AlanPanelErrors.h"


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
    return new QListWidget();
}
QListWidget *StreamPanel::getListView() const {
    return listView;
}


