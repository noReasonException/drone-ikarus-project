cmake_minimum_required(VERSION 3.9)
project(Ikarus_project)

include_directories(/usr/include/x86_64-linux-gnu/qt5/QtMultimediaWidgets)
include_directories(/usr/include/gstreamer-1.0)
include_directories(/usr/include/gstreamer-1.0/gst/)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
add_executable(Ikarus_project main.cpp
        MainWindow/AlanMainWindow.cpp
        MainWindow/AlanMainWindow.h
        misc/version.h
        misc/errors/AlanMainWindowErrors.h
        misc/generic_text/AlanMainWindowDialogs.h
        misc/img/generic_paths.h
        MainWindow/Panels/StreamPanel/LogPanel/LogPanel.cpp
        MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h
        MainWindow/Panels/StreamPanel/LogPanel/LogWidget/LogWidget.cpp
        MainWindow/Panels/StreamPanel/LogPanel/LogWidget/LogWidget.h
        MainWindow/Panels/AlanPanel.cpp
        MainWindow/Panels/AlanPanel.h
        MainWindow/Panels/StreamPanel/StreamPanel.cpp
        MainWindow/Panels/StreamPanel/StreamPanel.h
        MainWindow/Supplier/InformationObjectSupplier.cpp
        MainWindow/Supplier/InformationObjectSupplier.h
        MainWindow/Supplier/LogSupplier/LogSupplier.cpp
        MainWindow/Supplier/LogSupplier/LogSupplier.h misc/errors/AlanPanelErrors.h
        misc/generic_text/generic_dialogs.h
        MainWindow/InformationObject/InformationObject.cpp
        MainWindow/InformationObject/InformationObject.h
        MainWindow/InformationObject/Log/Log.cpp
        MainWindow/InformationObject/Log/Log.h
        MainWindow/InformationObject/Data/Data.cpp
        MainWindow/InformationObject/Data/Data.h MainWindow/Interfaces/InformationSupplierFactory.h MainWindow/Interfaces/LogSupplierFactory.h MainWindow/Consumer/InformationObjectConsumer.cpp MainWindow/Consumer/InformationObjectConsumer.h MainWindow/Consumer/LogConsumer/LogConsumer.cpp MainWindow/Consumer/LogConsumer/LogConsumer.h MainWindow/Factory/AbstractGuiFactory.cpp MainWindow/Factory/AbstractGuiFactory.h MainWindow/Factory/AlanDefaultGuiFactory/AlanDefaultGuiFactory.cpp MainWindow/Factory/AlanDefaultGuiFactory/AlanDefaultGuiFactory.h MainWindow/State/State.cpp MainWindow/State/State.h MainWindow/State/WindowStates/AlanMainWindowState.h MainWindow/State/WindowStates/AlanRestorationDialogState.h MainWindow/State/WindowStates/AlanLatencyDialogState.h MainWindow/State/WindowStates/AlanDataFileDialogState.h MainWindow/State/WindowStates/AlanErrorFileDialogState.h MainWindow/State/WindowStates/AlanDroneAddrDialogState.h MainWindow/State/WindowStates/AlanServerAddrDialogState.h MainWindow/Interfaces/StateRestorable.h MainWindow/Dialogs/AlanSingleOptionDialog.cpp MainWindow/Dialogs/AlanSingleOptionDialog.h)
target_link_libraries(Ikarus_project Qt5::Widgets Qt5::Multimedia)