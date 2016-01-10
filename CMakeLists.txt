cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(DEMUSE VERSION 0.1 LANGUAGES CXX)

# configuration
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
if(MINGW)
	set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static -lstdc++ -lpthread -dynamic")
endif()

# subdirectories
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(compiler)
add_subdirectory(ide)

# documentation
find_package(Doxygen)
if(DOXYGEN_FOUND)
    # DEMUSE developer documentation
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Developer_Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Developer_Doxyfile @ONLY)
	add_custom_target(dev_doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Developer_Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API documentation with Doxygen" VERBATIM)

    # DEMUSE user documentation
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/User_Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/User_Doxyfile @ONLY)
    add_custom_target(usr_doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/User_Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating user documentation with Doxygen" VERBATIM)

    add_custom_target(doc dev_doc COMMAND usr_doc)
endif(DOXYGEN_FOUND)

# install
include(Install.cmake)