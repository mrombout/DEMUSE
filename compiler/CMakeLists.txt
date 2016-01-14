cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(Compiler VERSION 0.1 LANGUAGES CXX)

set(Compiler_SRCS
    inc/exception/RuntimeException.h
    src/exception/RuntimeException.cpp

    inc/value/Variable.h
    src/value/Variable.cpp

    inc/value/Property.h
    src/value/Property.cpp

    inc/value/Value.h
    src/value/Value.cpp

    inc/value/function/PrintFunction.h
    src/value/function/PrintFunction.cpp

    inc/value/function/UserFunction.h
    src/value/function/UserFunction.cpp

    inc/value/ArrayValue.h
    src/value/ArrayValue.cpp

    inc/value/NullValue.h
    src/value/NullValue.cpp

    inc/value/NumberValue.h
    src/value/NumberValue.cpp

    inc/value/ObjectValue.h
    src/value/ObjectValue.cpp

    inc/value/SongValue.h
    src/value/SongValue.cpp

    inc/value/BooleanValue.h
    src/value/BooleanValue.cpp

    inc/value/function/FunctionValue.h
    src/value/function/FunctionValue.cpp

    inc/value/function/InternalFunction.h
    src/value/function/InternalFunction.cpp

    inc/value/function/InternalLambdaFunction.h
    src/value/function/InternalLambdaFunction.cpp

    inc/value/TextValue.h
    src/value/TextValue.cpp

    inc/value/NoteValue.h
    src/value/NoteValue.cpp

    inc/Compiler.h
    src/Compiler.cpp

    inc/MuseMidiCompiler.h
    src/MuseMidiCompiler.cpp

    inc/MuseMidiPlayEvaluator.h
    src/MuseMidiPlayEvaluator.cpp

    inc/ExpressionEvaluator.h
    src/ExpressionEvaluator.cpp
)

set(TestCompiler_SRCS
    test/value/BooleanValueTest.cpp
    test/value/NoteValueTest.cpp
    test/value/NullValueTest.cpp
    test/value/TextValueTest.cpp
    test/value/NumberValueTest.cpp
    test/value/ObjectValueTest.cpp
    test/ExpressionEvaluatorTest.cpp
)

add_library(libcompiler SHARED ${Compiler_SRCS})
add_library(dem::libcompiler ALIAS libcompiler)
set_target_properties(libcompiler PROPERTIES OUTPUT_NAME "compiler")

add_executable(compiler ${Compiler_SRCS} src/main.cpp)

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/inc CACHE INTERNAL "${PROJECT_NAME}: Include directories" FORCE)

target_include_directories(libcompiler PUBLIC ${Compiler_INCLUDE_DIRS} ${Parser_INCLUDE_DIRS} ${Lexer_INCLUDE_DIRS})
target_link_libraries(libcompiler PRIVATE dem::libparser)

target_include_directories(compiler PRIVATE ${Compiler_INCLUDE_DIRS} ${Parser_INCLUDE_DIRS} ${Lexer_INCLUDE_DIRS})
target_link_libraries(compiler PRIVATE dem::libparser dem::liblexer)

# testing
enable_testing()

add_executable(testcompiler ${Compiler_SRCS} ${TestCompiler_SRCS})

target_link_libraries(testcompiler PRIVATE dem::libparser dem::liblexer)
target_include_directories(testcompiler PRIVATE inc ${Lexer_INCLUDE_DIRS})

find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_include_directories(testcompiler PRIVATE P:/Libraries/googletest-release-1.7.0/include)
    target_link_libraries(testcompiler PRIVATE ${GTEST_BOTH_LIBRARIES})
endif()

add_test(AllCompilerTests testcompiler)

# dependencies
find_package(Midifile REQUIRED)
if(Midifile_FOUND)
    message(STATUS "Include: " ${Midifile_INCLUDE_DIRS})
    message(STATUS "Library: " ${Midifile_LIBRARIES})

    target_include_directories(compiler PUBLIC ${Midifile_INCLUDE_DIRS})
    target_link_libraries(compiler PRIVATE ${Midifile_LIBRARIES})

    target_include_directories(libcompiler PUBLIC ${Midifile_INCLUDE_DIRS})
    target_link_libraries(libcompiler PRIVATE ${Midifile_LIBRARIES})

    target_include_directories(testcompiler PUBLIC ${Midifile_INCLUDE_DIRS})
    target_link_libraries(testcompiler PRIVATE ${Midifile_LIBRARIES})
endif()

# install
install(TARGETS compiler DESTINATION bin COMPONENT compiler)
install(TARGETS libcompiler DESTINATION bin COMPONENT libcompiler)
