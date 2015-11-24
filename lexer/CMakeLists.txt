cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Lexer VERSION 0.1 LANGUAGES CXX)

set(Lexer_SRCS
    inc/Lexer.h
    src/Lexer.cpp

    inc/MuseLexer.h
    src/MuseLexer.cpp

    inc/MusicStringLexer.h
    src/MusicStringLexer.cpp

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

    inc/matcher/PlayMatcher.h
    src/matcher/PlayMatcher.cpp

    inc/matcher/NoteMatcher.h
    src/matcher/NoteMatcher.cpp

    inc/matcher/AccidentalMatcher.h
    src/matcher/AccidentalMatcher.cpp
)

set(TestLexer_SRCS
    test/TokenTest.cpp
    test/TokenDefinitionTest.cpp
    test/LexerTest.cpp
    test/MuseLexerTest.cpp
    test/MusicStringLexerTest.cpp
    test/matcher/NullMatcherTest.cpp
    test/matcher/CharMatcherTest.cpp
    test/matcher/StringMatcherTest.cpp
    test/matcher/RegexMatcherTest.cpp
)

add_library(liblexer ${Lexer_SRCS})
add_library(dem::liblexer ALIAS liblexer)
set_target_properties(liblexer PROPERTIES OUTPUT_NAME "lexer")

add_executable(lexer ${Lexer_SRCS} src/main.cpp)

target_include_directories(liblexer PUBLIC inc)
target_include_directories(lexer PRIVATE inc)

target_compile_features(liblexer
    PRIVATE
        cxx_auto_type
        cxx_nullptr
        cxx_strong_enums
)
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/inc CACHE INTERNAL "${PROJECT_NAME}: Include directories" FORCE)

# testing
enable_testing()

add_executable(testlexer ${Lexer_SRCS} ${TestLexer_SRCS})
target_include_directories(testlexer PRIVATE inc)

find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_include_directories(testlexer PRIVATE E:/Libraries/googletest-release-1.7.0/include)
    target_link_libraries(testlexer ${GTEST_BOTH_LIBRARIES})
endif()

add_test(AllLexerTests testlexer)
