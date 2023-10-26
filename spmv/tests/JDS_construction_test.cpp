#include <SpMV.hpp>
#include "unit_test_framework.hpp"

// Create a unit test
template <typename T>
TEST_CASE(matrix_row_size) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_JDS<T> matrix = SpMV::SparseMatrix_JDS<T>(nrows, ncols);
    ASSERT(matrix.getNumRows() == static_cast<size_t>(nrows));
}

template <typename T>
TEST_CASE(matrix_col_size) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_JDS<T> matrix = SpMV::SparseMatrix_JDS<T>(nrows, ncols);
    ASSERT(matrix.getNumCols() == static_cast<size_t>(ncols));
}


// Create a test suite
template <typename T>
TEST_SUITE(construction) {
    TEST(matrix_row_size<T>);
    TEST(matrix_col_size<T>);
}

auto
main() -> int
{
    RUN_SUITE(construction<float>);
    RUN_SUITE(construction<double>);
    return 0; 
}