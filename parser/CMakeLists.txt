cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Parser VERSION 0.1 LANGUAGES CXX)

add_library(parser
    src/Parser.cpp include/Parser.h
)
add_library(dem::parser ALIAS parser)

target_include_directories(parser
    PUBLIC include
)