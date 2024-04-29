cmake_minimum_required(VERSION 3.5)

project(models VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets )
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets REQUIRED)

add_library(models SHARED
usermodel.h usermodel.cpp
vehiclemodel.h vehiclemodel.cpp)

target_link_libraries(models PRIVATE
    Qt6::Core
    Qt6::Widgets
)

