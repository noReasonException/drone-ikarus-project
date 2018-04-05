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
class MainWindow;
using namespace std;
int main(int argc,char *argv[]) {
    QApplication application(argc,argv);
    QMainWindow *waa= new AlanMainWindow();
    waa->show();
    QMainWindow*ptr= new QMainWindow;
    (QWidget*)ptr;
    return application.exec();
}