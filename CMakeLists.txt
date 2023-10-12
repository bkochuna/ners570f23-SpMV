cmake_minimum_required(VERSION 3.20)

project(SpMV VERSION 0.1.0 LANGUAGES CXX)

# Set module path to find our macros
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(hello) #include our macro

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Check that the compiler supports the C++17 standard
# We assume you are using GNU compilers
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "8.0.0")
    message(FATAL_ERROR "GCC version must be at least 8.0.0")
  endif()
else()
  message(WARNING "You are using an unsupported compiler! This might not work.")
endif()

# Enable a long list of warnings to ensure correctness
include(gnu_warning_flags)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GNU_WARNING_FLAGS}")

# Enable testing
include(CTest)
enable_testing()

add_subdirectory(spmv)
add_subdirectory(examples)
