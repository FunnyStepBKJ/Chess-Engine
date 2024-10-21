cmake_minimum_required(VERSION 3.16)

project(chess_engine_ui VERSION 0.1 LANGUAGES CXX)

# Enable automatic handling of UI, MOC, and resource files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

# Translation source files
set(TS_FILES chess_engine_ui_en_US.ts)

# List of source files for the project
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    ${TS_FILES}

    chess_board/chess_board.cpp
    chess_board/chess_board.h

    pieces/pieces.h
    pieces/pieces.cpp
)

# Add the executable based on the Qt version
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(chess_engine_ui
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(chess_engine_ui
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(chess_engine_ui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

add_custom_command(TARGET chess_engine_ui POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/../assets ${CMAKE_BINARY_DIR}/assets
)

# Set properties for macOS bundles if necessary
set_target_properties(chess_engine_ui PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Installation instructions
include(GNUInstallDirs)
install(TARGETS chess_engine_ui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(chess_engine_ui)
endif()

