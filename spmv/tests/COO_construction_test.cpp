#include <SpMV.hpp>
#include "unit_test_framework.hpp"

// Create a unit test
template <typename T>
TEST_CASE(matrix_row_size) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    ASSERT(matrix.getNumRows() == static_cast<size_t>(nrows));
}

template <typename T>
TEST_CASE(matrix_col_size) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    ASSERT(matrix.getNumCols() == static_cast<size_t>(ncols));
}

template <typename T>
TEST_CASE(matrix_type) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    ASSERT(matrix.getFormat() == "COO");
}

// Create a test suite
template <typename T>
TEST_SUITE(construction) {
    TEST(matrix_row_size<T>);
    TEST(matrix_col_size<T>);
    TEST(matrix_type<T>);
}

auto
main() -> int
{
    RUN_SUITE(construction<float>);
    RUN_SUITE(construction<double>);
    return 0; 
}
