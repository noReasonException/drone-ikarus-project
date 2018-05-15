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

#include <QFileDialog>
#include "AlanDefaultFactory.h"
#include "../../MainWindow/AlanMainWindow.h"
#include "../../MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetDroneAddrDialog.h"
#include "../../MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialog.h"
#include "../../MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h"
#include "../../MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetLatencyDialog.h"
#include "../../MainWindow/Dialogs/ChildDialogs/AlanAboutDialog.h"
#include "../../MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetDroneAddrDialogState.h"
#include "../../MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetServersAddrDialogState.h"
#include "../../RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/AlanDefaultRTSPClientSubsystem.h"
#include "../../res/Suppliers/OptionSuppliers.h"
#include "../../res/misc.h"

AlanDefaultFactory::AlanDefaultFactory():rtspsystem(nullptr){}
QMainWindow *AlanDefaultFactory::getMainWindow() {
    return new AlanMainWindow(this);
}

QDialog *AlanDefaultFactory::getResolutionDialog() {
    return (new SetResolutionDialog(
            new SetResolutionDialogState(),
            getRTSPSubsystem()->createSupplier(RESOLUTION_OPTION_SUPPLIER)))->prepare();
}

QDialog *AlanDefaultFactory::getLatencyDialog() {

    return (new SetLatencyDialog(
            new SetLatencyDialogState(),
            getRTSPSubsystem()->createSupplier(LATENCY_OPTION_SUPPLIER)))->prepare();
}

QString AlanDefaultFactory::getDataFileDialog() {
    return QFileDialog::getOpenFileName(NULL,DATA_FILE_DIALOG_TITLE,
                                        DATA_FILE_DIALOG_INITIAL_DIRECTORY,
                                        DATA_FILE_DIALOG_FILE_TYPES_ACCEPTED);

}

QString AlanDefaultFactory::getErrorFileDialog() {
    return QFileDialog::getOpenFileName(NULL,
                                        LOG_FILE_DIALOG_TITLE,
                                        LOG_FILE_DIALOG_INITIAL_DIRECTORY,
                                        LOG_FILE_DIALOG_FILE_TYPES_ACCEPTED);
}
QString AlanDefaultFactory::getVideoFileDialog() {
    return QFileDialog::getOpenFileName(NULL,
                                        VIDEO_FILE_DIALOG_TITLE,
                                        VIDEO_FILE_DIALOG_INITIAL_DIRECTORY,
                                        VIDEO_FILE_DIALOG_FILE_TYPES_ACCEPTED);
}
QDialog *AlanDefaultFactory::getDroneAddrDialog() {
    return (new SetDroneAddrDialog(
            new SetDroneAddrDialogState(),
            getRTSPSubsystem()->createSupplier(SETDRONEADDR_OPTION_SUPPLIER)))->prepare();
}

QDialog *AlanDefaultFactory::getServerAddrDialog() {
    return (new SetServersAddrDialog(
            new SetServersAddrDialogState(),
            getRTSPSubsystem()->createSupplier(SETSERVERADDR_OPTION_SUPPLIER)))->prepare();

}

QDialog *AlanDefaultFactory::getAboutDialog() {
    return (new AlanAboutDialog())->prepare();
}

AbstractRTSPClientSubsystem *AlanDefaultFactory::getRTSPSubsystem() {
    return rtspsystem!= nullptr?rtspsystem:(rtspsystem=new AlanDefaultRTSPClientSubsystem);

}

AlanDefaultFactory::~AlanDefaultFactory() {
    delete rtspsystem;

}


