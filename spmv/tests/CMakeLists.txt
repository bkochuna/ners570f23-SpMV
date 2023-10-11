add_executable(example_test
    example_unit_test.cpp
)

target_include_directories(example_test PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)

target_link_libraries(example_test spmv)