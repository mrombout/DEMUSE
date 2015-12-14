# - Try to find Jdksmidi
#
# The following variables will be defined:
#
#   Jdksmidi_FOUND - system has Jdksmidi
#   Jdksmidi_INCLUDE_DIRS - the Jdksmidi include directories
#   Jdksmidi_LIBRARIES - the libraries needed to use Jdksmidi

find_package(PkgConfig)
pkg_check_modules(PC_JDKSMIDI QUIET jdksmidi)

set(FIND_JDKSMIDI_PATHS
    ${JDKSMIDI_ROOT}
    $ENV{JDKSMIDI_ROOT}
)

find_path(JDKSMIDI_INCLUDE_DIR jdksmidi/parser.h
    HINTS ${PC_JDKSMIDI_INCLUDEDIR} ${PC_JDKSMIDI_INCLUDE_DIRS}
    PATH_SUFFIXES include
    PATHS ${FIND_JDKSMIDI_PATHS})

find_library(JDKSMIDI_LIBRARY NAMES jdksmidi
    HINTS ${PC_JDKSMIDI_LIBDIR} ${PC_JDKSMIDI_LIBRARY_DIRS}
    PATH_SUFFIXES lib
    PATHS ${FIND_JDKSMIDI_PATHS})

set(Jdksmidi_LIBRARIES ${JDKSMIDI_LIBRARY})
set(Jdksmidi_INCLUDE_DIRS ${JDKSMIDI_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Jdksmidi DEFAULT_MSG JDKSMIDI_LIBRARY JDKSMIDI_INCLUDE_DIR)

mark_as_advanced(JDKSMIDI_INCLUDE_DIR JDKSMIDI_LIBARY)