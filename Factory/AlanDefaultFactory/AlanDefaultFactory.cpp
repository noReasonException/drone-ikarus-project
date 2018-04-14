//
// Created by noreasonexception on 4/5/18.
//

#include "AlanDefaultFactory.h"
#include "../../MainWindow/AlanMainWindow.h"
#include "../../MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetDroneAddrDialog.h"
#include "../../MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialog.h"
#include "../../MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h"
#include "../../MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetLatencyDialog.h"
#include "../../MainWindow/Dialogs/ChildDialogs/AlanAboutDialog.h"
#include "../../MainWindow/State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetLatencyDialogState.h"
#include "../../MainWindow/State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetResolutionDialogState.h"
#include "../../MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetDroneAddrDialogState.h"
#include "../../MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetServersAddrDialogState.h"
#include "../../RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/AlanDefaultRTSPClientSubsystem.h"

QMainWindow *AlanDefaultFactory::getMainWindow() {
    return new AlanMainWindow(this);
}

QDialog *AlanDefaultFactory::getResolutionDialog() {
    return (new SetResolutionDialog(new SetResolutionDialogState()))->prepare();
}

QDialog *AlanDefaultFactory::getLatencyDialog() {
    return (new SetLatencyDialog(new SetLatencyDialogState()))->prepare();
}

QDialog *AlanDefaultFactory::getDataFileDialog() {
    return nullptr;
}

QDialog *AlanDefaultFactory::getErrorFileDialog() {
    return nullptr;
}

QDialog *AlanDefaultFactory::getDroneAddrDialog() {
    return (new SetDroneAddrDialog(new SetDroneAddrDialogState()))->prepare();
}

QDialog *AlanDefaultFactory::getServerAddrDialog() {
    return (new SetServersAddrDialog(new SetServersAddrDialogState()))->prepare();

}

QDialog *AlanDefaultFactory::getAboutDialog() {
    return (new AlanAboutDialog())->prepare();
}

AbstractRTSPClientSubsystem *AlanDefaultFactory::getRTSPSubsystem() {
    return new AlanDefaultRTSPClientSubsystem();
}
