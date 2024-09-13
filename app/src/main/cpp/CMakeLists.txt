# Sets the minimum version of CMake required to build your native library.
cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC or SHARED,
# and provides the relative paths to its source code.
add_library(
        native-lib # Name of the library
        SHARED # Creates a shared library
        native-lib.cpp # The source file
)

# Specifies libraries C++ code will use and links them.
find_library(
        log-lib
        log
)

# Links the native library with the log library.
target_link_libraries(
        native-lib
        ${log-lib}
)
