cmake_minimum_required(VERSION 3.5)

project(database VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Sql REQUIRED)

add_library(database
SHARED
database1.h database1.cpp)

target_include_directories(database PRIVATE models)
target_link_libraries(database PUBLIC models)
# target_include_directories(database PUBLIC dataProvider)
# target_link_libraries(database PRIVATE dataProvider)

# target_link_libraries(database PRIVATE Qt${QT_VERSION_MAJOR}:: Core Qt${QT_VERSION_MAJOR}::Widgets)
# target_link_libraries(database PRIVATE Qt${QT_VERSION_MAJOR}:: Sql)
target_link_libraries(database PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Sql
)
