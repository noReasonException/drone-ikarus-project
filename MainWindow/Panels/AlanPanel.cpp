//
// Created by noreasonexception on 4/3/18.
//

#include <QMessageBox>
#include <QString>
#include <QVBoxLayout>
#include "AlanPanel.h"
#include "../../res/errors/AlanPanelErrors.h"
#include "../../res/generic_text/generic_dialogs.h"
AlanPanel::AlanPanel(QString str) : QWidget(nullptr),title(str) {}

/***
 * genericInitializer()
 * This is the top most error-check layer,
 * Checks all the initialization processes
 * In case of error , ask the user if want to continue or terminate.
 * @note this top-error-check layer differs by the AlanMainWindow::generic_initializer
 * this initializer is virtual , this means in case you override the AlanPanel
 * in order to accomplish perferct error-checking . you must override as follows
 * bool YourChildClass::genericInitializer(){
 *      return AlanPanel::generic_initializer()&&
 *             your_specific_initialize_method1() &&
 *             your_specific_initialize_method2();
 * }
 * for a hands-on example , please visit StreamPanel/StreamPanel.cpp::generic_initializer()
 * @return true if all initialization steps where successful
 *
 */
bool AlanPanel::generic_initializer() {
    return initializeLayout()&&
            initializeTitleArea();
}
/***
 * A simple wrapper over onGenerateTitleArea() ,it checks if this function is called successfully ,
 * and informs the upper error-protection layer (the generic_initializer() in case of error
 *
 * @note why we dont initialize directly from here?
 * @see the comment section of AlanMainWindow::initializeMenu
 * @return true if everything is okay , false otherwise
 */
bool AlanPanel::initializeTitleArea()try {
    mainLayout->addWidget(this->titleArea=onGenerateTitleArea(),0,Qt::AlignCenter);
    return true;
}catch(std::exception&e){return false;}
/***
 * onGenerateTitleArea() does the real job of initializing and returning a QWidget
 * destined to be in Title area of AlanPanel().
 * @return a new QWidget
 *  * @note this function HAS NOT responsibility of assigning the QWidget inside AlanPanel layout.
 * this means that commands like...
 *                      this->mainLayout->addWidget(...)
 * ...is strictly forbidden (To maintain a elegant code)
 */
QWidget *AlanPanel::onGenerateTitleArea() throw(std::exception){
    return new QLabel(title);
}

/***
 * A simple wrapper over onGenerateLayout ,it checks if this function is called successfully ,
 * and informs the upper error-protection layer (the generic_initializer() in case of error
 *
 * @note why we dont initialize directly from here?
 * @see the comment section of AlanMainWindow::initializeMenu
 * @return true if everything is okay , false otherwise
 *
***/
bool AlanPanel::initializeLayout()try{
    setLayout(mainLayout=onGenerateLayout());
    return true;
}catch(std::exception&e){return false;}
/***
 * onGenerateLayout() does the real job of initializing and returning a QVBoxLayout
 * destined to be the main layout of AlanPanel.
 * @return a new QWidget
 *  * @note this function HAS NOT responsibility of assigning the QWidget as AlanPanel layout.
 * this means that commands like...
 *                      this->setLayout(...->)
 * ...is strictly forbidden (To maintain a elegant code)
 */
QVBoxLayout *AlanPanel::onGenerateLayout()throw(std::exception) {
    return new QVBoxLayout();
}
