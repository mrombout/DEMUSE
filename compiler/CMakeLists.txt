cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Compiler VERSION 0.1 LANGUAGES CXX)

set(Compiler_SRCS
    inc/Scope.h
    src/Scope.cpp

    inc/GlobalScope.h
    src/GlobalScope.cpp

    inc/value/Variable.h
    src/value/Variable.cpp

    inc/value/Value.h
    src/value/Value.cpp

    inc/value/NullValue.h
    src/value/NullValue.cpp

    inc/value/NumberValue.h
    src/value/NumberValue.cpp

    inc/value/BooleanValue.h
    src/value/BooleanValue.cpp

    inc/function/Function.h
    src/function/Function.cpp

    inc/function/UserFunction.h
    src/function/UserFunction.cpp

    inc/Compiler.h
    src/Compiler.cpp

    inc/MidiCompiler.h
    src/MidiCompiler.cpp

    inc/ExpressionEvaluator.h
    src/ExpressionEvaluator.cpp
)

set(TestCompiler_SRCS

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

endif()

# install
install(TARGETS compiler DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_EXECUTABLES compiler, "compiler")
include(CPack)