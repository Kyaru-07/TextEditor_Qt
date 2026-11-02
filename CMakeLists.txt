cmake_minimum_required(VERSION 3.19)
project(TextEditor LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Svg)

qt_standard_project_setup()

# qt_standard_project_setup() 只打开 AUTOMOC / AUTOUIC，不打开 AUTORCC，
# 不显式打开的话 icons.qrc 会被静默忽略（能编译通过，但程序里取不到任何图标）。
set(CMAKE_AUTORCC ON)

qt_add_executable(TextEditor
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    icons.qrc
    aboutdialog.h aboutdialog.cpp aboutdialog.ui
    finddialog.h finddialog.cpp finddialog.ui
    replacedialog.h replacedialog.cpp replacedialog.ui
)

target_link_libraries(TextEditor
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::Svg
)

install(TARGETS TextEditor
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET TextEditor
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
