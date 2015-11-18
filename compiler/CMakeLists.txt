cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Compiler VERSION 0.1 LANGUAGES CXX)

set(Compiler_SRCS
    inc/Compiler.h
    src/Compiler.cpp

    inc/MidiCompiler.h
    src/MidiCompiler.cpp
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

# install
install(TARGETS compiler DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_EXECUTABLES compiler, "compiler")
include(CPack)