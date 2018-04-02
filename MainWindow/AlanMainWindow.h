//
// Created by noreasonexception on 4/1/18.
//

#ifndef IKARUS_PROJECT_ALANMAINWINDOW_H
#define IKARUS_PROJECT_ALANMAINWINDOW_H


#include <QMainWindow>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../misc/errors/AlanMainWindowErrors.h"
#include "../misc/version.h"
#include "../misc/generic_text/AlanMainWindowDialogs.h"
#include "../misc/img/AlanMainWindowImagePaths.h"

/***
 * AlanMainWindow
 * This window is the main window of Alan Streamer , inherits from QMainWindow
 *
 */
class AlanMainWindow : public QMainWindow{
    Q_OBJECT

public:
    AlanMainWindow();
private :
    //Misc Members
    bool isStreaming;
    bool isReTransmitting;

    //Initializers

    bool genericInitializer();              ///@return true if all initialization steps was successful
    bool initializeMenu();                  ///@return true if the menu initialization process was successful
    bool initializeToolBar();               ///@return true if ToolBar initialization process was successful
    bool initializeCentralWidget();
    bool initializeTelemetryPanel();        ///@return true if Telemetry panel initialization process was successful
    bool initializeDataPanel();             ///@return true if data panel initialization process was successful
    bool initializeControlPanel();          ///@return true if control panel initialization process was successful
    bool initializeLogPanel();              ///@return true if log panel initialization process was successful
    bool initializeStatusBar();             ///@return true if status bas initialization process was successful

    //Misc
    QAction* initializeQAction(QAction *act,QString filename, const char*onClickSlot);


protected slots:
    void operationNotSupportedSlot();   //Shows a Warning message that the pressed QAction is not supported
    void closeSlot();                   //triggers on QAction "Exit" //TODO connect with closeEvent() also
protected:
    std::vector<QMenu*>*                onGenerateMenu(QMenuBar*bar) throw(std::exception);
    std::vector<QToolBar*>*             onGenerateToolBar() throw(std::exception);
    QWidget*                            onGenerateCentralWidget()throw(std::exception);
    QVBoxLayout*                        onGenerateLeftLayout()throw(std::exception);
    QVBoxLayout*                        onGenerateVideoArea()throw(std::exception);
    QVBoxLayout*                        onGenerateRightLayout()throw(std::exception);


    QWidget*                            onGenerateTelemetryPanel();
    QWidget*                            onGenerateDataPanel();
    QWidget*                            onGenerateControlPanel();
    QWidget*                            onGenerateLogPanel();
    QWidget*                            onGenerateStatusBar();



};


#endif //IKARUS_PROJECT_ALANMAINWINDOW_H
