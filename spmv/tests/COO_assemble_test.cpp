#include <SpMV.hpp>
#include "unit_test_framework.hpp"

// Create a unit test
template <typename T>
TEST_CASE(initialized_state_test) {
    size_t nrows = 100;
    size_t ncols = 100;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    ASSERT(matrix.getState() == 1);
}

template <typename T>
TEST_CASE(building_state_test_1) {
    size_t nrows = 100;
    size_t ncols = 100;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    matrix.setCoefficient(50,50,10.0);
    ASSERT(matrix.getState() == 2);
}

template <typename T>
TEST_CASE(assembled_state_test) {
    size_t nrows = 100;
    size_t ncols = 100;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    matrix.setCoefficient(50,50,10.0);
    matrix.assembleStorage();
    ASSERT(matrix.getState() == 3);
}

template <typename T>
TEST_CASE(building_state_test_2) {
    size_t nrows = 100;
    size_t ncols = 100;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    matrix.setCoefficient(50,50,10.0);
    matrix.assembleStorage();
    matrix.disassembleStorage();
    ASSERT(matrix.getState() == 2);
}

// Create a test suite
template <typename T>
TEST_SUITE(assemble) {
    TEST(initialized_state_test<T>);
    TEST(building_state_test_1<T>);
    TEST(building_state_test_2<T>);
    TEST(assembled_state_test<T>);
}

auto
main() -> int
{
    RUN_SUITE(construction<float>);
    RUN_SUITE(construction<double>);
    return 0; 
}
