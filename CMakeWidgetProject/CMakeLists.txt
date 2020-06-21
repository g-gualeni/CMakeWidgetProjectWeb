cmake_minimum_required(VERSION 3.5)

project(CMakeWidgetProject LANGUAGES CXX VERSION 1.2.3.4)

set(LEGAL_COPYRIGHT "(C) 2020 www.GianbattistaGualeni.it")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MACOSX_BUNDLE ON)
set(MACOSX_BUNDLE_BUNDLE_NAME "${PROJECT_NAME}")
set(MACOSX_BUNDLE_GUI_IDENTIFIER "${PROJECT_NAME}")
set(MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}")
set(MACOSX_BUNDLE_LONG_VERSION_STRING "${PROJECT_VERSION}")
set(MACOSX_BUNDLE_SHORT_VERSION_STRING
    "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")
set(MACOSX_BUNDLE_INFO_STRING "${PROJECT_NAME} - ${LEGAL_COPYRIGHT}")
set(MACOSX_BUNDLE_COPYRIGHT ${LEGAL_COPYRIGHT})

set(WIN_APPLICATION_ICON "icons/satellite.ico")
set(RESOURCE_FILE "WinResources.rc")
configure_file(${RESOURCE_FILE}.in ${RESOURCE_FILE})


set(MACOSX_BUNDLE_ICON_FILE CMakeWidgetProject)
set(MACOSX_ICON_FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/icons/${MACOSX_BUNDLE_ICON_FILE}.icns)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS TextToSpeech REQUIRED)


if(ANDROID)
  add_library(CMakeWidgetProject SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
    add_executable(CMakeWidgetProject
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    CMakeWidgetProject-Doc.odt
    CMakeWidgetProject-Doc.pdf
    CMakeWidgetProject-res.qrc
    ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_FILE}
    ${MACOSX_ICON_FILE}
  )
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST
    ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in)
set_source_files_properties(${MACOSX_ICON_FILE} PROPERTIES
       MACOSX_PACKAGE_LOCATION "Resources")


target_link_libraries(CMakeWidgetProject PRIVATE Qt5::Widgets)
target_link_libraries(CMakeWidgetProject PRIVATE Qt5::TextToSpeech)
