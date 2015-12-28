# - Try to find Midifile
#
# The following variables will be defined:
#
#   Midifile_FOUND - system has Midifile
#   Midifile_INCLUDE_DIRS - the Midifile include directories
#   Midifile_LIBRARIES - the libraries needed to use Midifile

find_package(PkgConfig)
pkg_check_modules(PC_MIDIFILE QUIET midifile)

set(FIND_MIDIFILE_PATHS
    ${MIDIFILE_ROOT}
    $ENV{MIDIFILE_ROOT}
)

find_path(MIDIFILE_INCLUDE_DIR MidiFile.h
    PATH_SUFFIXES include
    PATHS ${FIND_MIDIFILE_PATHS})

find_library(MIDIFILE_LIBRARY NAMES midifile
    HINTS ${PC_MIDIFILE_LIBDIR} ${PC_MIDIFILE_LIBRARY_DIRS}
    PATH_SUFFIXES lib
    PATHS ${FIND_MIDIFILE_PATHS})

set(Midifile_LIBRARIES ${MIDIFILE_LIBRARY})
set(Midifile_INCLUDE_DIRS ${MIDIFILE_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Midifile DEFAULT_MSG MIDIFILE_LIBRARY MIDIFILE_INCLUDE_DIR)

mark_as_advanced(MIDIFILE_INCLUDE_DIR MIDIFILE_LIBARY)