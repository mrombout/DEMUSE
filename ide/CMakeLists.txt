cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(IDE VERSION 0.1 LANGUAGES CXX)

set(IDE_SRCS
    inc/App.h
    src/App.cpp

    inc/MainFrame.h
    src/MainFrame.cpp

    inc/MuseAuiDockArt.h
    src/MuseAuiDockArt.cpp

    inc/MuseAuiTabArt.h
    src/MuseAuiTabArt.cpp

    inc/MuseAuiToolbarArt.h
    src/MuseAuiToolbarArt.cpp
)

add_executable(ide
    src/main.cpp
    ${IDE_SRCS}
)

target_include_directories(ide
    PRIVATE inc
)

target_link_libraries(ide
    PRIVATE dem::liblexer dem::libcompiler dem::libplayer
)

# dependencies
find_package(wxWidgets COMPONENTS stc aui adv core base scintilla REQUIRED)
if(wxWidgets_FOUND)
    target_include_directories(ide PRIVATE ${wxWidgets_INCLUDE_DIRS})
    target_link_libraries(ide PRIVATE ${wxWidgets_LIBRARIES})
endif()

# install
install(TARGETS ide DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_EXECUTABLES ide, "IDE")
include(CPack)