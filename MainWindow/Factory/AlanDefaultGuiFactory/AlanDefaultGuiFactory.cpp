//
// Created by noreasonexception on 4/5/18.
//

#include "AlanDefaultGuiFactory.h"
#include "../../AlanMainWindow.h"
#include "../../Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetDroneAddrDialog.h"
#include "../../Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialog.h"
#include "../../Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h"

QMainWindow *AlanDefaultGuiFactory::getMainWindow() {
    return new AlanMainWindow(this);
}

QDialog *AlanDefaultGuiFactory::getResolutionDialog() {
    return (new SetResolutionDialog(new AlanTwoButtonsDialogState()))->prepare();
}

QDialog *AlanDefaultGuiFactory::getLatencyDialog() {
    return nullptr;
}

QDialog *AlanDefaultGuiFactory::getDataFileDialog() {
    return nullptr;
}

QDialog *AlanDefaultGuiFactory::getErrorFileDialog() {
    return nullptr;
}

QDialog *AlanDefaultGuiFactory::getDroneAddrDialog() {
    return (new SetDroneAddrDialog(new AlanMultipleChoiceDialogState()))->prepare();
}

QDialog *AlanDefaultGuiFactory::getServerAddrDialog() {
    return (new SetServersAddrDialog(new AlanMultipleChoiceDialogState()))->prepare();

}

QDialog *AlanDefaultGuiFactory::getAboutDialog() {
    return nullptr;
}
