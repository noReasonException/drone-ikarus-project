//
// Created by noreasonexception on 4/5/18.
//

#include "AlanDefaultGuiFactory.h"
#include "../../AlanMainWindow.h"

QMainWindow *AlanDefaultGuiFactory::getMainWindow() {
    return new AlanMainWindow();
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
    return nullptr;
}

QDialog *AlanDefaultGuiFactory::getServerAddrDialog() {
    return nullptr;
}

QDialog *AlanDefaultGuiFactory::getAboutDialog() {
    return nullptr;
}
