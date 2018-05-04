#include <iostream>
#include <gst/gst.h>
#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QToolBar>
#include <QMainWindow>
#include "MainWindow/AlanMainWindow.h"
#include "Factory/AlanDefaultFactory/AlanDefaultFactory.h"

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