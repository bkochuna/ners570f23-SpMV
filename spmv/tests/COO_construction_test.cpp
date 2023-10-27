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

auto
main() -> int
{
    TEST(matrix_row_size<float>);
    TEST(matrix_col_size<float>);
    TEST(matrix_type<float>);
    TEST(matrix_row_size<double>);
    TEST(matrix_col_size<double>);
    TEST(matrix_type<double>);
    return 0; 
}
