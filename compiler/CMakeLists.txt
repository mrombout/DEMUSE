cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Compiler VERSION 0.1 LANGUAGES CXX)

set(Compiler_SRCS
    inc/exception/RuntimeException.h
    src/exception/RuntimeException.cpp

    inc/Scope.h
    src/Scope.cpp

    inc/GlobalScope.h
    src/GlobalScope.cpp

    inc/value/Variable.h
    src/value/Variable.cpp

    inc/value/Value.h
    src/value/Value.cpp

    inc/value/ArrayValue.h
    src/value/ArrayValue.cpp

    inc/value/NullValue.h
    src/value/NullValue.cpp

    inc/value/NumberValue.h
    src/value/NumberValue.cpp

    inc/value/ObjectValue.h
    src/value/ObjectValue.cpp

    inc/value/BooleanValue.h
    src/value/BooleanValue.cpp

    inc/value/FunctionValue.h
    src/value/FunctionValue.cpp

    inc/value/TextValue.h
    src/value/TextValue.cpp

    inc/Compiler.h
    src/Compiler.cpp

    inc/MidiCompiler.h
    src/MidiCompiler.cpp

    inc/PlayEvaluator.h
    src/PlayEvaluator.cpp

    inc/ExpressionEvaluator.h
    src/ExpressionEvaluator.cpp
)

set(TestCompiler_SRCS
    test/value/BooleanValueTest.cpp
    test/value/TextValueTest.cpp
    test/value/NumberValueTest.cpp
    test/ExpressionEvaluatorTest.cpp
)

add_library(libcompiler ${Compiler_SRCS})
add_library(dem::libcompiler ALIAS libcompiler)
set_target_properties(libcompiler PROPERTIES OUTPUT_NAME "compiler")

add_executable(compiler ${Compiler_SRCS} src/main.cpp)

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/inc CACHE INTERNAL "${PROJECT_NAME}: Include directories" FORCE)

target_include_directories(libcompiler PUBLIC ${Compiler_INCLUDE_DIRS} ${Parser_INCLUDE_DIRS} ${Lexer_INCLUDE_DIRS})
target_link_libraries(libcompiler PRIVATE dem::libparser)

target_include_directories(compiler PRIVATE ${Compiler_INCLUDE_DIRS} ${Parser_INCLUDE_DIRS} ${Lexer_INCLUDE_DIRS})
target_link_libraries(compiler PRIVATE dem::libparser dem::liblexer)

# dependencies
find_package(Jdksmidi REQUIRED)
if(Jdksmidi_FOUND)
    message(STATUS "Include: " ${Jdksmidi_INCLUDE_DIRS})
    message(STATUS "Include: " ${Jdksmidi_LIBRARIES})
    target_include_directories(compiler PRIVATE ${Jdksmidi_INCLUDE_DIRS})
    target_link_libraries(compiler PRIVATE ${Jdksmidi_LIBRARIES})
endif()

# testing
enable_testing()

add_executable(testcompiler ${Compiler_SRCS} ${TestCompiler_SRCS})

target_link_libraries(testcompiler dem::libparser dem::liblexer)
target_include_directories(testcompiler PRIVATE inc ${Lexer_INCLUDE_DIRS})

find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_include_directories(testcompiler PRIVATE E:/Libraries/googletest-release-1.7.0/include)
    target_link_libraries(testcompiler ${GTEST_BOTH_LIBRARIES})
endif()

add_test(AllCompilerTests testcompiler)

# install
install(TARGETS compiler DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_EXECUTABLES compiler, "compiler")
include(CPack)
