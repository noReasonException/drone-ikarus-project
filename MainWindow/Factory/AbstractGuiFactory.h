//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_ABSTRACTGUIFACTORY_H
#define IKARUS_PROJECT_ABSTRACTGUIFACTORY_H


#include <QMainWindow>
#include <QWindow>


/****
 * This is the interface for abstract gui factory of Alan
 */
class AbstractGuiFactory {
public:
    virtual QMainWindow *getMainWindow()        =0;
    virtual QDialog     *getResolutionDialog()  =0;
    virtual QDialog     *getLatencyDialog()     =0;
    virtual QDialog     *getDataFileDialog()    =0;
    virtual QDialog     *getErrorFileDialog()   =0;
    virtual QDialog     *getDroneAddrDialog()   =0;
    virtual QDialog     *getServerAddrDialog()  =0;
    virtual QDialog     *getAboutDialog()       =0;
};


#endif //IKARUS_PROJECT_ABSTRACTGUIFACTORY_H
