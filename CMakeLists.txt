cmake_minimum_required(VERSION 3.20)

project(SpMV VERSION 0.1.0)

enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Modify CMake MODULE Path to find our macro
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(hello) #include our macro

add_subdirectory(spmv)
add_subdirectory(examples)

