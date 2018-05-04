cmake_minimum_required(VERSION 3.9)
project(Ikarus_project)

include_directories(/usr/include/x86_64-linux-gnu/qt5/QtMultimediaWidgets)
include_directories(/usr/include/gstreamer-1.0)
include_directories(/usr/include/gstreamer-1.0/gst/)

include_directories(/usr/include/glib-2.0)
set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
add_executable(Ikarus_project main.cpp
        ./RTSPClientSubsystem/AbstractRTSPClientSubsystem.h
        ./RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/AlanDefaultRTSPClientSubsystem.h
        ./RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/qsettings.h
        ./Consumer/InformationObjectConsumer.h
        ./Consumer/LogConsumer/LogConsumer.h
        ./Consumer/OptionConsumer/OptionConsumer.h
        ./MainWindow/Dialogs/ChildDialogs/AlanAboutDialog.h
        ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialog.h
        ./MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h
        ./MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetLatencyDialog.h
        ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialog.h
        ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetDroneAddrDialog.h
        ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/AlanMultipleChoiceDialog.h
        ./MainWindow/Dialogs/AlanSingleOptionDialog.h
        ./MainWindow/Panels/AlanPanel.h
        ./MainWindow/Panels/StreamPanel/LogPanel/LogWidget/LogWidget.h
        ./MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h
        ./MainWindow/Panels/StreamPanel/StreamPanel.h
        ./MainWindow/AlanMainWindow.h
        ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/AlanMultipleChoiceDialogState.h
        ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetServersAddrDialogState.h
        ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetDroneAddrDialogState.h
        ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h
        ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetResolutionDialogState.h
        ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetLatencyDialogState.h
        ./MainWindow/State/WindowStates/AlanSingleOptionDialogState.h
        ./MainWindow/State/State.h
        ./InformationObject/InformationObject.h
        ./InformationObject/Data/Data.h
        ./InformationObject/Log/Log.h
        ./InformationObject/Option/ChildOptions/LatencyOption.h
        ./InformationObject/Option/ChildOptions/ResolutionOption.h
        ./InformationObject/Option/ChildOptions/WindowHandleOption.h
        ./InformationObject/Option/ChildOptions/ClientStatusOption.h
        ./InformationObject/Option/Option.h
        ./Interfaces/LogSupplierFactory.h
        ./Interfaces/StateRestorable.h
        ./Interfaces/InformationSupplierFactory.h
        ./Interfaces/OptionSupplierFactory.h
        ./misc/states.h
        ./misc/version.h
        ./misc/Suppliers/LogSuppliers.h
        ./misc/Suppliers/OptionSuppliers.h
        ./misc/img/generic_paths.h
        ./misc/generic_text/AlanMainWindowMisc.h
        ./misc/generic_text/generic_dialogs.h
        ./misc/generic_text/AlanMainWindowDialogs.h
        ./misc/errors/AlanMainWindowErrors.h
        ./misc/errors/AlanPanelErrors.h
        ./Supplier/LogSupplier/LogSupplier.h
        ./Supplier/OptionSupplier/OptionSupplier.h
        ./Supplier/InformationObjectSupplier.h
        ./Factory/AlanDefaultFactory/AlanDefaultFactory.h
        ./Factory/AbstractFactory.h
        ./InformationObject/InformationObject.cpp
        ./InformationObject/Data/Data.cpp
        ./InformationObject/Log/Log.cpp
        ./InformationObject/Option/Option.cpp
        ./MainWindow/AlanMainWindow.cpp
        ./MainWindow/Dialogs/AlanSingleOptionDialog.cpp
        ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/AlanMultipleChoiceDialog.cpp
        MainWindow/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialogText.cpp
        ./MainWindow/Panels/AlanPanel.cpp
        ./MainWindow/Panels/StreamPanel/LogPanel/LogWidget/LogWidget.cpp
        ./MainWindow/Panels/StreamPanel/LogPanel/LogPanel.cpp
        ./MainWindow/Panels/StreamPanel/StreamPanel.cpp
        ./MainWindow/State/State.cpp
        ./Consumer/LogConsumer/LogConsumer.cpp
        ./Consumer/InformationObjectConsumer.cpp
        ./Consumer/OptionConsumer/OptionConsumer.cpp
        ./RTSPClientSubsystem/AbstractRTSPClientSubsystem.cpp
        ./RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/AlanDefaultRTSPClientSubsystem.cpp
        ./Factory/AlanDefaultFactory/AlanDefaultFactory.cpp
        ./Factory/AbstractFactory.cpp
        ./Supplier/InformationObjectSupplier.cpp
        ./Supplier/LogSupplier/LogSupplier.cpp
        ./Supplier/OptionSupplier/OptionSupplier.cpp
        InformationObject/Option/ChildOptions/LocationOption.h
        RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/utill.c RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/handle.c RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/common.h RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/MainLoopThread.h MainWindow/Panels/StreamPanel/DataPanel/DataPanel.cpp MainWindow/Panels/StreamPanel/DataPanel/DataPanel.h Supplier/DataSupplier/DataSupplier.cpp Supplier/DataSupplier/DataSupplier.h Consumer/DataConsumer/DataConsumer.cpp Consumer/DataConsumer/DataConsumer.h Interfaces/DataSupplierFactory.h RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/handle.h MainWindow/Panels/StreamPanel/DataPanel/DataWidget/DataWidget.cpp MainWindow/Panels/StreamPanel/DataPanel/DataWidget/DataWidget.h InformationExporter/InformationExporter.cpp InformationExporter/InformationExporter.h InformationExporter/ChildClasses/DataExporter.cpp InformationExporter/ChildClasses/DataExporter.h InformationExporter/ChildClasses/LogExporter.cpp InformationExporter/ChildClasses/LogExporter.h misc/Suppliers/InformationObjectSupplier.h misc/generic_text/Dialogs/AlanSingleOptionDialogText.h misc/generic_text/Dialogs/ChildDialogs/AlanAboutDialogText.h misc/generic_text/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialogText.h misc/generic_text/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetLatencyDialogText.h misc/generic_text/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialogText.h misc/generic_text/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/AlanMultipleChoiceDialogText.h misc/generic_text/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetDroneAddrDialogText.h misc/generic_text/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialogText.h)
target_link_libraries(Ikarus_project Qt5::Widgets Qt5::Multimedia)