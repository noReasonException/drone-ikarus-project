#include <iostream>
#include <gst/gst.h>
#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QToolBar>
#include <QLineEdit>
#include <QIcon>
#include <QLabel>
#include <QSpacerItem>
#include <iostream>
#include <fstream>
#include <iostream>
#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include "MainWindow/AlanMainWindow.h"
#include "MainWindow/Dialogs/AlanSingleOptionDialog.h"
#include "MainWindow/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialog.h"
#include "MainWindow/Dialogs/AlanTwoButtonDialog/AlanSingleLineConfiguration/AlanMultipleChoiceDialog.h"
#include "MainWindow/Factory/AlanDefaultGuiFactory/AlanDefaultGuiFactory.h"

class MainWindow;
using namespace std;
int main(int argc,char *argv[]) {
    QApplication application(argc,argv);
    AbstractGuiFactory*factory=new AlanDefaultGuiFactory();
    factory->getMainWindow()->show();
    return application.exec();
}