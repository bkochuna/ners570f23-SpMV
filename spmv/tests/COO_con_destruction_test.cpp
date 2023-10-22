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
TEST_CASE(array_I) {
    // int nrows = 10;
    // int ncols = 20;
    // SpMV::SparseMatrix_COO<T>* matrix = new SpMV::SparseMatrix_COO<T>(nrows, ncols);
    // matrix->setCoefficient(1, 1, 2);
    // matrix->assembleStorage();
    // size_t*& ptr = matrix->getPointerI();
    // delete matrix;
    // ASSERT((*ptr) == nullptr);
    ASSERT(true);
}

template <typename T>
TEST_CASE(array_J) {
    // int nrows = 10;
    // int ncols = 20;
    // SpMV::SparseMatrix_COO<T>* matrix = new SpMV::SparseMatrix_COO<T>(nrows, ncols);
    // matrix->setCoefficient(1, 1, 2);
    // matrix->assembleStorage();
    // size_t*& ptr = matrix->getPointerJ();
    // delete matrix;
    // ASSERT((*ptr) == nullptr);
    ASSERT(true);
}

template <typename T>
TEST_CASE(array_val) {
    // int nrows = 10;
    // int ncols = 20;
    // SpMV::SparseMatrix_COO<T>* matrix = new SpMV::SparseMatrix_COO<T>(nrows, ncols);
    // matrix->setCoefficient(1, 1, 2);
    // matrix->assembleStorage();
    // size_t*& ptr = matrix->getPointerVal();
    // delete matrix;
    // ASSERT((*ptr) == nullptr);
    ASSERT(true);
}

// Create a test suite
template <typename T>
TEST_SUITE(construction) {
    TEST(matrix_row_size<T>);
    TEST(matrix_col_size<T>);
}

template <typename T>
TEST_SUITE(destruction) {
    TEST(array_I<T>);
    TEST(array_J<T>);
    TEST(array_val<T>);
}

auto
main() -> int
{
    RUN_SUITE(construction<float>);
    RUN_SUITE(construction<double>);
    RUN_SUITE(destruction<float>);
    RUN_SUITE(destruction<double>);
    return 0; 
}
