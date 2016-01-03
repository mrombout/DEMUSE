cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(IDE VERSION 0.1 LANGUAGES CXX)

set(IDE_SRCS
    inc/App.h
    src/App.cpp

    inc/AutocompleteVisitor.h
    src/AutocompleteVisitor.cpp

    inc/MainFrame.h
    src/MainFrame.cpp

    inc/MuseArtProvider.h
    src/MuseArtProvider.cpp

    inc/MuseStyledTextEditor.h
    src/MuseStyledTextEditor.cpp

    src/OutputTextCtrl.cpp
    src/OutputTextCtrl.h

    inc/preference/GeneralPanel.h
    src/preference/GeneralPanel.cpp

    inc/preference/GeneralPage.h
    src/preference/GeneralPage.cpp

    inc/preference/ExecutionPanel.h
    src/preference/ExecutionPanel.cpp

    inc/preference/ExecutionPage.h
    src/preference/ExecutionPage.cpp

    inc/preference/EditorPanel.h
    src/preference/EditorPanel.cpp

    inc/preference/EditorPage.h
    src/preference/EditorPage.cpp

    inc/preference/ColorsPage.h
    src/preference/ColorsPage.cpp

    inc/preference/ColorsPanel.h
    src/preference/ColorsPanel.cpp
)

if(WIN32)
    set(IDE_SRCS ${IDE_SRCS} resources.rc)
endif()

add_executable(ide
    src/main.cpp
    ${IDE_SRCS}
)

target_include_directories(ide PRIVATE inc ${Lexer_INCLUDE_DIRS} ${Parser_INCLUDE_DIRS} ${Compiler_INCLUDE_DIRS})
target_link_libraries(ide PRIVATE dem::liblexer dem::libparser dem::libcompiler)

# dependencies
SET(wxWidgets_USE_LIBS)
if(WIN32)
    find_package(wxWidgets REQUIRED propgrid aui stc adv core base scintilla)
else()
    find_package(wxWidgets REQUIRED propgrid aui stc adv core base)
endif()
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})

    message(STATUS "wxWidgets include: " ${wxWidgets_INCLUDE_DIRS})
    message(STATUS "wxWidgets libraries: " ${wxWidgets_LIBRARIES})

    target_include_directories(ide PRIVATE ${wxWidgets_INCLUDE_DIRS})
    target_link_libraries(ide PUBLIC ${wxWidgets_LIBRARIES})
endif()

# install
install(TARGETS ide DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_EXECUTABLES ide, "IDE")
include(CPack)