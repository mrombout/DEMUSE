cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Compiler VERSION 0.1 LANGUAGES CXX)

set(Compiler_SRCS
    inc/exception/RuntimeException.h
    src/exception/RuntimeException.cpp

    inc/Scope.h
    src/scope/Scope.cpp

    inc/GlobalScope.h
    src/scope/GlobalScope.cpp

    inc/value/Variable.h
    src/value/Variable.cpp

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

    inc/value/BooleanValue.h
    src/value/BooleanValue.cpp

    inc/value/function/FunctionValue.h
    src/value/function/FunctionValue.cpp

    inc/value/function/InternalFunction.h
    src/value/function/InternalFunction.cpp

    inc/value/TextValue.h
    src/value/TextValue.cpp

    inc/value/NoteValue.h
    src/value/NoteValue.cpp

    inc/Compiler.h
    src/Compiler.cpp

    inc/MuseMidiCompiler.h
    src/MuseMidiCompiler.cpp

    inc/MusePlayEvaluator.h
    src/MusePlayEvaluator.cpp

    inc/MuseMidiPlayEvaluator.h
    src/MuseMidiPlayEvaluator.cpp

    inc/ExpressionEvaluator.h
    src/ExpressionEvaluator.cpp
)

set(TestCompiler_SRCS
    test/value/BooleanValueTest.cpp
    test/value/TextValueTest.cpp
    test/value/NumberValueTest.cpp
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

# dependencies
find_package(Jdksmidi REQUIRED)
if(Jdksmidi_FOUND)
    message(STATUS "Include: " ${Jdksmidi_INCLUDE_DIRS})
    message(STATUS "Include: " ${Jdksmidi_LIBRARIES})

    target_include_directories(compiler PRIVATE ${Jdksmidi_INCLUDE_DIRS})
    target_link_libraries(compiler PRIVATE ${Jdksmidi_LIBRARIES})

    target_include_directories(libcompiler PUBLIC ${Jdksmidi_INCLUDE_DIRS})
    target_link_libraries(libcompiler PRIVATE ${Jdksmidi_LIBRARIES})
endif()

find_package(Midifile REQUIRED)
if(Midifile_FOUND)
    message(STATUS "Include: " ${Midifile_INCLUDE_DIRS})
    message(STATUS "Include: " ${Midifile_LIBRARIES})

    target_include_directories(compiler PRIVATE ${Midifile_INCLUDE_DIRS})
    target_link_libraries(compiler PRIVATE ${Midifile_LIBRARIES})

    target_include_directories(libcompiler PUBLIC ${Midifile_INCLUDE_DIRS})
    target_link_libraries(libcompiler PRIVATE ${Midifile_LIBRARIES})
endif()

# testing
enable_testing()

add_executable(testcompiler ${Compiler_SRCS} ${TestCompiler_SRCS})

target_link_libraries(testcompiler dem::libparser dem::liblexer)
target_include_directories(testcompiler PRIVATE inc ${Lexer_INCLUDE_DIRS})

find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_include_directories(testcompiler PRIVATE P:/Libraries/googletest-release-1.7.0/include)
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
