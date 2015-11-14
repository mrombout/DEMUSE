cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Parser VERSION 0.1 LANGUAGES CXX)

set(Parser_SRCS
    inc/Parser.h

    inc/Symbol.h
    src/Symbol.cpp

    inc/MuseParser.h
    src/MuseParser.cpp

    inc/factory/ProgramFactory.h
    src/factory/ProgramFactory.cpp
)

add_library(libparser ${Parser_SRCS})
add_library(dem::libparser ALIAS libparser)
set_target_properties(liblexer PROPERTIES OUTPUT_NAME "parser")

add_executable(parser ${Parser_SRCS} src/main.cpp)

target_link_libraries(libparser dem::liblexer)
target_include_directories(libparser PUBLIC inc ${Lexer_INCLUDE_DIRS})

target_link_libraries(parser dem::liblexer)
target_include_directories(parser PUBLIC inc ${Lexer_INCLUDE_DIRS})