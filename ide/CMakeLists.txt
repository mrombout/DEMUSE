cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(IDE VERSION 0.1 LANGUAGES CXX)

add_executable(ide
        src/main.cpp
)

target_include_directories(ide
    PRIVATE include
)

target_link_libraries(ide
    PRIVATE dem::liblexer dem::libcompiler dem::libplayer
)

# install
install(TARGETS ide DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_EXECUTABLES ide, "IDE")
include(CPack)