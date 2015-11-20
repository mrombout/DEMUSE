cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(DEMUSE VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(compiler)
add_subdirectory(player)
add_subdirectory(ide)