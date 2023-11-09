include(add_spmv_test)
include(add_spmv_test_fail)

add_spmv_test(./example_unit_test.cpp)
add_spmv_test_fail(./example_unit_test_fail.cpp)

add_spmv_test(./testCOO_Constructor.cpp)