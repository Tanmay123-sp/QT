cmake_minimum_required(VERSION 3.5)

project(dataProvider VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets )
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets REQUIRED)

add_library(dataProvider
SHARED
dataprovider1.h dataprovider1.cpp
)

target_include_directories(dataProvider PUBLIC database)
target_link_libraries(dataProvider PRIVATE database)
# target_link_libraries(database PRIVATE Qt${QT_VERSION_MAJOR}:: Core Qt${QT_VERSION_MAJOR}::Widgets)
# target_link_libraries(database PRIVATE Qt${QT_VERSION_MAJOR}:: Sql)
target_link_libraries(dataProvider PRIVATE
    Qt6::Core
    Qt6::Widgets
)
