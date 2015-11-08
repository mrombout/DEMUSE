cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Lexer VERSION 0.1 LANGUAGES CXX)

set(Lexer_SRCS
    inc/Lexer.h
    src/Lexer.cpp

    inc/MuseLexer.h
    src/MuseLexer.cpp

    inc/Token.h
    src/Token.cpp

    inc/TokenType.h
    src/TokenType.cpp

    inc/TokenDefinition.h
    src/TokenDefinition.cpp

    inc/matcher/Matcher.h

    inc/matcher/RegexMatcher.h
    src/matcher/RegexMatcher.cpp

    inc/matcher/StringMatcher.h
    src/matcher/StringMatcher.cpp

    inc/matcher/NullMatcher.h
    src/matcher/NullMatcher.cpp

    inc/matcher/CharMatcher.h
    src/matcher/CharMatcher.cpp

    src/main.cpp
)

add_library(liblexer ${Lexer_SRCS})
add_library(dem::liblexer ALIAS liblexer)
add_executable(lexer ${Lexer_SRCS})

target_include_directories(liblexer
    PUBLIC inc
    )
target_include_directories(lexer
    PRIVATE inc
    )

target_compile_features(liblexer
    PRIVATE
        cxx_auto_type
        cxx_nullptr
        cxx_strong_enums
)