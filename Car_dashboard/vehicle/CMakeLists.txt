cmake_minimum_required(VERSION 3.5)

project(vehicle VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(database/)
add_subdirectory(dataProvider/)
add_subdirectory(models/)
add_subdirectory(googletest/)
add_subdirectory(googlemock/)
add_subdirectory(testing/)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(vehicle
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        dashboard1.h dashboard1.cpp dashboard1.ui
        user.h user.cpp user.ui
        adduser.h adduser.cpp adduser.ui
        Resources.qrc

        test1.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET vehicle APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(vehicle SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(vehicle
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(vehicle PUBLIC database)
target_link_libraries(vehicle PRIVATE database)

target_include_directories(vehicle PUBLIC dataProvider)
target_link_libraries(vehicle PRIVATE dataProvider)

target_include_directories(vehicle PUBLIC googletest)
target_include_directories(vehicle PUBLIC googlemock)
target_link_libraries(vehicle PRIVATE gtest)
target_link_libraries(vehicle PRIVATE gmock)
# target_include_directories(vehicle PUBLIC testing)
# target_link_libraries(vehicle PRIVATE testing)


target_link_libraries(vehicle PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(vehicle PRIVATE Qt${QT_VERSION_MAJOR}::Test)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.vehicle)
endif()
set_target_properties(vehicle PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS vehicle
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(vehicle)
endif()
