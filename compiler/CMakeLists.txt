cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Compiler VERSION 0.1 LANGUAGES CXX)

add_library(libcompiler

)
add_library(dem::libcompiler ALIAS libcompiler)

target_include_directories(libcompiler
    PUBLIC include
)

target_link_libraries(libcompiler
    PRIVATE dem::libparser
)

add_executable(compiler
    src/main.cpp
)

target_include_directories(compiler
    PRIVATE include
)


# install
install(TARGETS compiler DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_EXECUTABLES compiler, "compiler")
include(CPack)