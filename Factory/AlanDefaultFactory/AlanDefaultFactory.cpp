//
// Created by noreasonexception on 4/5/18.
//

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


