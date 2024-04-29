project(Details VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Sql REQUIRED)

# Define the details1 library target
add_library(Details SHARED


    details1.h details1.cpp

)

# Link the details1 library against Qt Core
target_link_libraries(Details PRIVATE Qt${QT_VERSION_MAJOR}::Core)

# Link the details1 library against Qt Widgets (optional, if needed)
target_link_libraries(Details PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Details PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
