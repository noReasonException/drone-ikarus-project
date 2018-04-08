//
// Created by noreasonexception on 4/5/18.
//

#include "AlanDefaultGuiFactory.h"
#include "../../AlanMainWindow.h"
#include "../../Dialogs/AlanTwoButtonDialog/AlanSingleLineConfiguration/ChildDialogs/setDroneAddrDialog.h"
#include "../../Dialogs/AlanTwoButtonDialog/AlanSingleLineConfiguration/ChildDialogs/setServersAddrDialog.h"

QMainWindow *AlanDefaultGuiFactory::getMainWindow() {
    return new AlanMainWindow(this);
}

QDialog *AlanDefaultGuiFactory::getResolutionDialog() {
    return nullptr;
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
    return (new setDroneAddrDialog(new AlanMultipleChoiceDialogState()))->prepare();
}

QDialog *AlanDefaultGuiFactory::getServerAddrDialog() {
    return (new setServersAddrDialog(new AlanMultipleChoiceDialogState()))->prepare();

}

QDialog *AlanDefaultGuiFactory::getAboutDialog() {
    return nullptr;
}
