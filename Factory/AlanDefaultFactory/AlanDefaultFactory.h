//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_ALANDEFAULTGUIFACTORY_H
#define IKARUS_PROJECT_ALANDEFAULTGUIFACTORY_H


#include "../AbstractFactory.h"
/****
 * This is the default implementation of AbstractGuiFactory
 */
class AlanDefaultFactory : public AbstractFactory{

public:
    QMainWindow *getMainWindow() override;

    QDialog *getResolutionDialog() override;

    QDialog *getLatencyDialog() override;

    QDialog *getDataFileDialog() override;

    QDialog *getErrorFileDialog() override;

    QDialog *getDroneAddrDialog() override;

    QDialog *getServerAddrDialog() override;

    QDialog *getAboutDialog() override;
};


#endif //IKARUS_PROJECT_ALANDEFAULTGUIFACTORY_H
