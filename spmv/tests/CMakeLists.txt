include(${PROJECT_SOURCE_DIR}/cmake/add_spmv_test.cmake)

add_spmv_test(./example_unit_test.cpp)
add_spmv_test(./CSR_assemble_test.cpp)
# add_spmv_test(./CSR_matvec_ut.cpp)
