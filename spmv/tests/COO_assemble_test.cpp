#include <SpMV.hpp>
#include "unit_test_framework.hpp"

// Create a unit test
template <typename T>
TEST_CASE(initialized_state_test) {
    const int nrows = 100;
    const int ncols = 100;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    ASSERT(matrix.getState() == 1);
}

template <typename T>
TEST_CASE(building_state_test_1) {
    const int nrows = 100;
    const int ncols = 100;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    matrix.setCoefficient(50,50,10.0);
    ASSERT(matrix.getState() == 2);
}

template <typename T>
TEST_CASE(assembled_state_test) {
    const int nrows = 100;
    const int ncols = 100;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    matrix.setCoefficient(50,50,10.0);
    matrix.assembleStorage();
    ASSERT(matrix.getState() == 3);
}

template <typename T>
TEST_CASE(building_state_test_2) {
    const int nrows = 100;
    const int ncols = 100;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    matrix.setCoefficient(50,50,10.0);
    matrix.assembleStorage();
    matrix.disassembleStorage();
    ASSERT(matrix.getState() == 2);
}

auto
main() -> int
{
    TEST(initialized_state_test<float>);
    TEST(building_state_test_1<float>);
    TEST(building_state_test_2<float>);
    TEST(assembled_state_test<float>);
    TEST(initialized_state_test<double>);
    TEST(building_state_test_1<double>);
    TEST(building_state_test_2<double>);
    TEST(assembled_state_test<double>);
    return 0; 
}
