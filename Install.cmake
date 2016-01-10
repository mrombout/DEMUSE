if(MINGW)
    message(STATUS "Installing system-libraries: MinGW DLLs.")
    get_filename_component(Mingw_Path ${CMAKE_CXX_COMPILER} PATH)
    message(STATUS "MINGW_PATH: " ${Mingw_Path})
    set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS ${Mingw_Path}/libgcc_s_dw2-1.dll ${Mingw_Path}/libstdc++-6.dll ${Mingw_Path}/libwinpthread-1.dll)
    message(STATUS "Installing: " ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS})
endif( MINGW )
include(InstallRequiredSystemLibraries)

install(FILES ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS}
        DESTINATION /
        COMPONENT runtime)

set(CPACK_PACKAGE_NAME "DEMUSE")
set(CPACK_PACKAGE_VENDOR "Mike Rombout")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "DEMUSE")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/ide/res/icon/icon.ico")
set(CPACK_NSIS_MUI_UNICON "${CMAKE_SOURCE_DIR}/ide/res/icon/icon.ico")
set(CPACK_NSIS_INSTALLED_ICON_NAME "${CMAKE_SOURCE_DIR}/ide/res/icon/icon.ico")
set(CPACK_NSIS_URL_INFO_ABOUT "http://github.com/mrombout/DEMUSE")
set(CPACK_NSIS_EXECUTABLES_DIRECTORY ".")

set(CPACK_PACKAGE_EXECUTABLES ide "DEMUSE IDE")

set(CPACK_COMPONENTS_ALL ide compiler libcompiler libparser liblexer functionref manual examples runtime)

## documentation
install(DIRECTORY ${CMAKE_SOURCE_DIR}/docs/api DESTINATION docs COMPONENT functionref)
set(CPACK_COMPONENT_FUNCTIONREF_DISPLAY_NAME "Function Reference")
set(CPACK_COMPONENT_FUNCTIONREF_GROUP "Documentation")

install(DIRECTORY ${CMAKE_SOURCE_DIR}/docs/manual DESTINATION docs COMPONENT manual)
set(CPACK_COMPONENT_FUNCTIONREF_DISPLAY_NAME "Manual")
set(CPACK_COMPONENT_FUNCTIONREF_GROUP "Documentation")

install(DIRECTORY ${CMAKE_SOURCE_DIR}/examples DESTINATION / COMPONENT examples)
set(CPACK_COMPONENT_EXAMPLES_DISPLAY_NAME "Examples")
set(CPACK_COMPONENT_EXAMPLES_GROUP "Documentation")

## compiler
set(CPACK_COMPONENT_COMPILER_DISPLAY_NAME "Compiler")
set(CPACK_COMPONENT_COMPILER_DESCRIPTION "Compiles DEMUSE script to MIDI files. This includes only the executable version of the compiler that is used to run the compiler from a command-line interface.")
set(CPACK_COMPONENT_COMPILER_GROUP "Applications")
set(CPACK_COMPONENT_COMPILER_DEPENDS libcompiler libparser liblexer runtime)

## libcompiler
set(CPACK_COMPONENT_LIBCOMPILER_DISPLAY_NAME "Compiler")
set(CPACK_COMPONENT_LIBCOMPILER_GROUP "Libraries")
set(CPACK_COMPONENT_LIBCOMPILER_DEPENDS libparser liblexer runtime)

## libparser
set(CPACK_COMPONENT_LIBPARSER_DISPLAY_NAME "Parser")
set(CPACK_COMPONENT_LIBPARSER_GROUP "Libraries")
set(CPACK_COMPONENT_LIBPARSER_DEPENDS liblexer runtime)

## liblexer
set(CPACK_COMPONENT_LIBLEXER_DISPLAY_NAME "Lexer")
set(CPACK_COMPONENT_LIBLEXER_GROUP "Libraries")
set(CPACK_COMPONENT_LIBLEXER_DEPENDS runtime)

## ide
set(CPACK_COMPONENT_IDE_DISPLAY_NAME "IDE")
set(CPACK_COMPONENT_IDE_DESCRIPTION "Eases the development of DEMUSE scripts by providing a very simple editor that allows the compilation of DEMUSE script with the click of a button.")
set(CPACK_COMPONENT_IDE_GROUP "Applications")
set(CPACK_COMPONENT_IDE_DEPENDS libcompiler libparser liblexer runtime)

include(CPack)