include(${PROJECT_SOURCE_DIR}/cmake/add_spmv_test.cmake)

add_spmv_test(./example_unit_test.cpp)
add_spmv_test(./DEN_accessor_test.cpp)
add_spmv_test(./DEN_storage_test.cpp)
add_spmv_test(./DEN_constructor_test.cpp)
