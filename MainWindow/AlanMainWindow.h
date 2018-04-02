//
// Created by noreasonexception on 4/1/18.
//

#ifndef IKARUS_PROJECT_ALANMAINWINDOW_H
#define IKARUS_PROJECT_ALANMAINWINDOW_H


#include <QMainWindow>

#include "../misc/errors/AlanMainWindowErrors.h"
#include "../misc/version.h"
#include "../misc/generic_text/AlanMainWindowDialogs.h"
#include "../misc/img/AlanMainWindowImagePaths.h"
class AlanMainWindow : public QMainWindow{
    Q_OBJECT

public:
    AlanMainWindow();
private :
    //Misc Members
    bool isStreaming;
    bool isReTransmitting;

    //Initializers
    bool genericInitializer();
    bool initializeMenu();
    bool initializeToolBar();
    bool initializeTelemetryPanel();
    bool initializeDataPanel();
    bool initializeControlPanel();
    bool initializeLogPanel();
    bool initializeStatusBar();

    //Menu Stuff
    QMenu     *optionsMenu;
        QAction *setResolutionAction;
        QAction *setLatencyAction;
        QAction *setErrorFile;
        QAction *setDataFile;
        QAction *Exit;
    QMenu   *sourceMenu;
        QAction *setDroneAddress;
        QAction *startStreaming;
        QAction *stopStreaming;
    QMenu   *retransmitMenu;
        QAction *setServerIp;
        QAction *startBroadcast;
        QAction *stopBroadcast;

    QMenu     *toolsMenu;
    QMenu     *miscMenu;
    QAction   *aboutMenu;

private slots:
    void operationNotSupportedSlot();
    void closeSlot();
protected:
    void                onGenerateMenu(QMenuBar*bar);
    std::vector<QToolBar*>*            onGenerateToolBar();
    QWidget*            onGenerateTelemetryPanel();
    QWidget*            onGenerateDataPanel();
    QWidget*            onGenerateControlPanel();
    QWidget*            onGenerateLogPanel();
    QWidget*            onGenerateStatusBar();



};


#endif //IKARUS_PROJECT_ALANMAINWINDOW_H
