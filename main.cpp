#include <iostream>
#include <gst/gst.h>
#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QToolBar>
#include <iostream>
#include <QMainWindow>
#include <QFileDialog>
#include "MainWindow/AlanMainWindow.h"
#include "MainWindow/Factory/AlanDefaultGuiFactory/AlanDefaultGuiFactory.h"

class MainWindow;
using namespace std;
int main(int argc,char *argv[]) {
    QApplication application(argc,argv);
    AbstractGuiFactory*as=new AlanDefaultGuiFactory();
    as->getMainWindow()->show();
    return application.exec();
}