cmake_minimum_required(VERSION 3.16)

project(GizWebPluginLab2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core)
qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appGizWebPluginLab2
    src/main.cpp
)
add_subdirectory(src)
qt_add_qml_module(appGizWebPluginLab2
    URI GizWebPluginLab2
    VERSION 1.0
    QML_FILES
        Main.qml
        Theme.qml
        ./qml/plugins/Header.qml
        ./qml/plugins/HeaderLetterBox.qml
        ./qml/plugins/HeaderMobileMenu.qml
        ./qml/plugins/BoxIntroduction.qml
        ./qml/plugins/ImageRounded.qml
        ./qml/plugins/BlogCards.qml
        ./qml/plugins/TechSkills.qml
        qml/plugins/Separator.qml
        qml/plugins/Footer.qml
    RESOURCES
        assets.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appGizWebPluginLab2 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appGizWebPluginLab2
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appGizWebPluginLab2
    PRIVATE Qt6::Quick Qt6::Core
    src_lib
)

include(GNUInstallDirs)
install(TARGETS appGizWebPluginLab2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
