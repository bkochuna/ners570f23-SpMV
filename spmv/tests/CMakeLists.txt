include(${PROJECT_SOURCE_DIR}/cmake/add_spmv_test.cmake)

add_spmv_test(./example_unit_test.cpp)
add_spmv_test(./COO_con_destruction_test.cpp)
add_spmv_test(./COO_accessor_test.cpp)
add_spmv_test(./COO_view_test.cpp)