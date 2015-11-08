cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Player VERSION 0.1 LANGUAGES CXX)

add_library(libplayer
    src/Player.cpp include/Player.h
)
add_library(dem::libplayer ALIAS libplayer)

target_include_directories(libplayer
    PUBLIC include
)

add_executable(player
    src/main.cpp
)

target_include_directories(player
    PRIVATE include
)

# install
install(TARGETS player DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_EXECUTABLES player, "Player")
include(CPack)