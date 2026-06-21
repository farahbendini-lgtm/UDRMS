cmake_minimum_required(VERSION 3.16)

project(project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Quick Widgets)

qt_standard_project_setup(REQUIRES 6.10)

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

qt_add_executable(appproject
    main.cpp
    backend.cpp
    backend.h
    Main.qml
)

qt_add_qml_module(appproject
    URI project
    QML_FILES
        Main.qml
        SOURCES backend.h
        SOURCES dorminatory.cpp dorminatory.hpp
        SOURCES person.cpp person.hpp Restaurant.cpp Restaurant.hpp room.cpp Room.hpp student.cpp student.hpp university.cpp university.hpp
        SOURCES backend.cpp
)

set_target_properties(appproject PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appproject
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Widgets
)

install(TARGETS appproject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)