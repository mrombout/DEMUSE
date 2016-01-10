![DEMUSE](/docs/logo.png "DEMUSE")

# Compiling

DEMUSE uses [CMake](https://www.cmake.org/) to generate build files for your preferred environment.

**Warning!** You need a C++11 compliant compiler.

## Dependencies

DEMUSE directly depends on the following libraries:

| Library                                            | Version                                                                                          | Notes                              |
| -------------------------------------------------- | ------------------------------------------------------------------------------------------------ | ---------------------------------- |
| [wxWidgets](https://www.wxwidgets.org/)            | >= 3.0.2                                                                                         | Only required for IDE              |
| [midifile](https://github.com/craigsapp/midifile)  | [9ee5898](https://github.com/craigsapp/midifile/commit/9ee589869b25f66cb09808a721b31f095d07482a) | Only required for MIDI compilation |
| [googletest](https://github.com/google/googletest) | >= 1.7.0                                                                                         | Only required for building tests   |

