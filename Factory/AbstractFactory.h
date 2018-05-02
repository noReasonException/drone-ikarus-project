//
// Created by noreasonexception on 4/5/18.
//

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
    virtual QDialog                     *getDataFileDialog()    =0;
    virtual QDialog                     *getErrorFileDialog()   =0;
    virtual QDialog                     *getDroneAddrDialog()   =0;
    virtual QDialog                     *getServerAddrDialog()  =0;
    virtual QDialog                     *getAboutDialog()       =0;
};


#endif //IKARUS_PROJECT_ABSTRACTGUIFACTORY_H
