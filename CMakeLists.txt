cmake_minimum_required(VERSION 3.9)
project(Ikarus_project)

include_directories(/usr/include/x86_64-linux-gnu/qt5/QtMultimediaWidgets)
include_directories(/usr/include/gstreamer-1.0)
include_directories(/usr/include/gstreamer-1.0/gst/)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
add_executable(Ikarus_project main.cpp MainWindow/AlanMainWindow.cpp MainWindow/AlanMainWindow.h misc/version.h misc/errors/AlanMainWindowErrors.h)
target_link_libraries(Ikarus_project Qt5::Widgets Qt5::Multimedia)