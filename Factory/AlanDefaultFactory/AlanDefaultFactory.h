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

#ifndef IKARUS_PROJECT_ALANDEFAULTGUIFACTORY_H
#define IKARUS_PROJECT_ALANDEFAULTGUIFACTORY_H


#include "../AbstractFactory.h"
/****
 * This is the default implementation of AbstractGuiFactory
 */
class AlanDefaultFactory : public AbstractFactory{
private:
    AbstractRTSPClientSubsystem*rtspsystem;

public:
    AlanDefaultFactory();
    ~AlanDefaultFactory();
    QMainWindow *getMainWindow() override;

    QDialog *getResolutionDialog() override;

    QDialog *getLatencyDialog() override;

    QString getDataFileDialog() override;

    QString getErrorFileDialog() override;

    QDialog *getDroneAddrDialog() override;

    QDialog *getServerAddrDialog() override;

    QDialog *getAboutDialog() override;

    AbstractRTSPClientSubsystem *getRTSPSubsystem() override;

    QString getVideoFileDialog() override;
};


#endif //IKARUS_PROJECT_ALANDEFAULTGUIFACTORY_H
