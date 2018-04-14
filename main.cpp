#include <iostream>
#include <gst/gst.h>
#include <QApplication>
#include <QJsonObject>
#include <QDialog>
#include <QHBoxLayout>
#include <QToolBar>
#include <iostream>
#include <QMainWindow>
#include <QFileDialog>
#include "MainWindow/AlanMainWindow.h"
#include "Factory/AlanDefaultFactory/AlanDefaultFactory.h"
#include "misc/states.h"
#include "MainWindow/State/State.h"

class MainWindow;
using namespace std;
int main(int argc,char *argv[]) {
    gst_init(&argc,&argv);
    QApplication application(argc,argv);
    application.setOrganizationName("noReasonException");
    application.setOrganizationDomain("com.noreasonException");
    application.setApplicationName("Alan");
    AbstractFactory*a=new AlanDefaultFactory();
    a->getMainWindow()->show();

    return application.exec();
}