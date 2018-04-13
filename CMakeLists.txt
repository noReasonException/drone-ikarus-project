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
        Supplier/InformationObjectSupplier.cpp
        Supplier/InformationObjectSupplier.h
        Supplier/LogSupplier/LogSupplier.cpp
        Supplier/LogSupplier/LogSupplier.h misc/errors/AlanPanelErrors.h
        misc/generic_text/generic_dialogs.h
        InformationObject/InformationObject.cpp
        InformationObject/InformationObject.h
        InformationObject/Log/Log.cpp
        InformationObject/Log/Log.h
        InformationObject/Data/Data.cpp
        InformationObject/Data/Data.h
        Interfaces/InformationSupplierFactory.h
        Interfaces/LogSupplierFactory.h
        Consumer/InformationObjectConsumer.cpp
        Consumer/InformationObjectConsumer.h
        Consumer/LogConsumer/LogConsumer.cpp
        Consumer/LogConsumer/LogConsumer.h
        MainWindow/Factory/AbstractGuiFactory.cpp
        MainWindow/Factory/AbstractGuiFactory.h
        MainWindow/Factory/AlanDefaultGuiFactory/AlanDefaultGuiFactory.cpp
        MainWindow/Factory/AlanDefaultGuiFactory/AlanDefaultGuiFactory.h
        MainWindow/State/State.h
        MainWindow/State/WindowStates/AlanSingleOptionDialogState.h
        Interfaces/StateRestorable.h
        MainWindow/Dialogs/AlanSingleOptionDialog.cpp
        MainWindow/Dialogs/AlanSingleOptionDialog.h
        MainWindow/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialog.cpp
        MainWindow/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialog.h
        MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/AlanMultipleChoiceDialog.h
        MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/AlanMultipleChoiceDialog.cpp
        MainWindow/State/WindowStates/AlanSingleOptionDialogState.h MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetDroneAddrDialog.h MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialog.h misc/generic_text/AlanMainWindowMisc.h misc/Suppliers/LogSuppliers.h MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetLatencyDialog.h MainWindow/Dialogs/ChildDialogs/AlanAboutDialog.h MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/AlanMultipleChoiceDialogState.h MainWindow/State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetResolutionDialogState.h MainWindow/State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetLatencyDialogState.h MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetDroneAddrDialogState.h MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetServersAddrDialogState.h misc/states.h MainWindow/State/State.cpp Supplier/OptionSupplier/OptionSupplier.cpp Supplier/OptionSupplier/OptionSupplier.h InformationObject/Option/Option.cpp InformationObject/Option/Option.h InformationObject/Option/ChildOptions/LatencyOption.h InformationObject/Option/ChildOptions/ResolutionOption.h InformationObject/Option/ChildOptions/ClientStatusOption.h Consumer/OptionConsumer/OptionConsumer.cpp Consumer/OptionConsumer/OptionConsumer.h Interfaces/OptionSupplierFactory.h RTSPClientSubsystem/AbstractRTSPClientSubsystem.cpp RTSPClientSubsystem/AbstractRTSPClientSubsystem.h RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/AlanDefaultRTSPClientSubsystem.cpp RTSPClientSubsystem/AlanDefaultRTSPClientSubsystem/AlanDefaultRTSPClientSubsystem.h InformationObject/Option/ChildOptions/WindowHandleOption.h)
target_link_libraries(Ikarus_project Qt5::Widgets Qt5::Multimedia)