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
#ifndef IKARUS_PROJECT_STREAMPANEL_H
#define IKARUS_PROJECT_STREAMPANEL_H


#include "../AlanPanel.h"
#include <QObject>
#include <QListView>
#include <QListWidget>
class StreamPanel : public AlanPanel{
    Q_OBJECT
protected:
    StreamPanel(const QString &title);

    ///Initializers/...
    virtual bool generic_initializer() override;            ///the generic initializer, overrider from AlanPanel
    virtual bool initializeListView();              ///@returns true if the initialization step of QListView was successful
    virtual bool initializeSlots();

    ///User-to-Override methods..
    virtual QListWidget *onGenerateListView();      ///intializes and @returns the QListView object , needed for initialization
    QListWidget *getListView() const;

private:
    QListWidget*listView;                           ///TODO in later version , use a custom QListView instead..
private slots:
    virtual void onDataClicked(QListWidgetItem *)=0;

};


#endif //IKARUS_PROJECT_STREAMPANEL_H
