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
#ifndef IKARUS_PROJECT_ABSTRACTGUIFACTORY_H
#define IKARUS_PROJECT_ABSTRACTGUIFACTORY_H


#include <QMainWindow>
#include <QWindow>
#include "../RTSPClientSubsystem/AbstractRTSPClientSubsystem.h"


/****
 * class AbstractFactory
 * This class is responsible for object-implementation abstraction . that means that we can
 * implement a different Dialog, and just define the Factory to return this instead of default one
 * without any modifications or recompile the whole project!
 * The default implementation exist in Factory/AlanDefaultFactory/AlanDefaultFactory.h
 */
class AbstractFactory {
public:
    virtual AbstractRTSPClientSubsystem *getRTSPSubsystem()     =0;
    virtual QMainWindow                 *getMainWindow()        =0;
    virtual QDialog                     *getResolutionDialog()  =0;
    virtual QDialog                     *getLatencyDialog()     =0;
    virtual QString                      getDataFileDialog()    =0;
    virtual QString                      getErrorFileDialog()   =0;
    virtual QString                      getVideoFileDialog()   =0;
    virtual QDialog                     *getDroneAddrDialog()   =0;
    virtual QDialog                     *getServerAddrDialog()  =0;
    virtual QDialog                     *getAboutDialog()       =0;
};


#endif //IKARUS_PROJECT_ABSTRACTGUIFACTORY_H
