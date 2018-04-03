cmake_minimum_required(VERSION 3.9)
project(Ikarus_project)

include_directories(/usr/include/x86_64-linux-gnu/qt5/QtMultimediaWidgets)
include_directories(/usr/include/gstreamer-1.0)
include_directories(/usr/include/gstreamer-1.0/gst/)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
add_executable(Ikarus_project main.cpp MainWindow/AlanMainWindow.cpp MainWindow/AlanMainWindow.h misc/version.h misc/errors/AlanMainWindowErrors.h misc/generic_text/AlanMainWindowDialogs.h misc/img/AlanMainWindowImagePaths.h MainWindow/Panels/StreamPanel/LogPanel/LogPanel.cpp MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h MainWindow/Panels/LogWidget/LogWidget.cpp MainWindow/Panels/LogWidget/LogWidget.h MainWindow/Panels/AlanPanel.cpp MainWindow/Panels/AlanPanel.h MainWindow/Panels/StreamPanel/StreamPanel.cpp MainWindow/Panels/StreamPanel/StreamPanel.h MainWindow/Supplier/AbstractSupplier.cpp MainWindow/Supplier/AbstractSupplier.h MainWindow/Supplier/StreamSupplier/StreamSupplier.cpp MainWindow/Supplier/StreamSupplier/StreamSupplier.h MainWindow/Supplier/StreamSupplier/LogSupplier/LogSupplier.cpp MainWindow/Supplier/StreamSupplier/LogSupplier/LogSupplier.h misc/errors/AlanPanelErrors.h misc/generic_text/generic_dialogs.h MainWindow/InformationObject/InformationObject.cpp MainWindow/InformationObject/InformationObject.h MainWindow/InformationObject/Log/Log.cpp MainWindow/InformationObject/Log/Log.h MainWindow/InformationObject/Data/Data.cpp MainWindow/InformationObject/Data/Data.h)
target_link_libraries(Ikarus_project Qt5::Widgets Qt5::Multimedia)