/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */
#include <iostream>
#include <gst/gst.h>
#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QToolBar>
#include <QMainWindow>
#include <QtCore/QSettings>
#include "MainWindow/AlanMainWindow.h"
#include "Factory/AlanDefaultFactory/AlanDefaultFactory.h"

class MainWindow;
using namespace std;
int main(int argc,char *argv[]) {
    gst_init(&argc,&argv);

    QApplication application(argc,argv);
    QSettings set;
    set.clear();

    application.setOrganizationName("noReasonException");
    application.setOrganizationDomain("com.noreasonException");
    application.setApplicationName("Alan");
    AbstractFactory*a=new AlanDefaultFactory();

    a->getMainWindow()->show();

    return application.exec();
}