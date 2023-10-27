include(${PROJECT_SOURCE_DIR}/cmake/add_spmv_test.cmake)

add_spmv_test(./example_unit_test.cpp)
add_spmv_test(./DEN_accessor_test.cpp)
add_spmv_test(./DEN_storage_test.cpp)
<<<<<<< HEAD
add_spmv_test(./DEN_constructor_test.cpp)
=======
add_spmv_test(./DEN_matvec_test.cpp)
>>>>>>> 2ed34506ab2edfb384709c5bb3fa26f3e9858ac1
