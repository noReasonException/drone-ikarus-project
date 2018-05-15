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
#ifndef IKARUS_PROJECT_ALANPANEL_H
#define IKARUS_PROJECT_ALANPANEL_H


#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QVBoxLayout>
/****
 * AlanPanel represents an abstract panel to exist in AlanMainWindow .
 * Panels exists in two flavors , Stream panels ( a panel witch is a stream , that means that
 * the data witch enter in panel , will never change , for example LogPanel or DataPanel)
 * and StaticPanels (a panel that the view data is fixed and changes, for example a
 * Telemetry panel (not implemented yet //TODO telemetry panel))
 *
 */
class AlanPanel : public QWidget{
    Q_OBJECT;


protected:
    QVBoxLayout*mainLayout;
    QWidget *titleArea;
    QString  title;
    AlanPanel(QString str);

    virtual bool generic_initializer();                     ///@returns true if every initialization step was successful
    virtual bool initializeLayout();                        ///@returns true if the initialization of layout was successful
    virtual bool initializeTitleArea();                     ///@returns true if the title area initialization was successful


    QWidget*    onGenerateTitleArea() throw(std::exception);///@returns a new QWidget designed to be the title area of the panel
    QVBoxLayout*onGenerateLayout()throw(std::exception);    ///@returns the layout designed to be the panels main layout



};


#endif //IKARUS_PROJECT_ALANPANEL_H
