#include <SpMV.hpp>
#include "unit_test_framework.hpp"

// Create a unit test
template <typename T>
TEST_CASE(matrix_row_size) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    ASSERT(matrix.getNumRows == nrows);
}

template <typename T>
TEST_CASE(matrix_col_size) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(nrows, ncols);
    ASSERT(matrix.getNumCols == ncols);
}

template <typename T>
TEST_CASE(array_I) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_COO<T>* matrix = new SpMV::SparseMatrix_COO<T>(nrows, ncols);
    matrix->setCoefficient(1, 1, 2);
    matrix->assembleStorage();
    size_t*& ptr = matrix->getPointerI();
    delete matrix
    ASSERT(ptr == nullptr);
}

template <typename T>
TEST_CASE(array_J) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_COO<T>* matrix = new SpMV::SparseMatrix_COO<T>(nrows, ncols);
    matrix->setCoefficient(1, 1, 2);
    matrix->assembleStorage();
    size_t*& ptr = matrix->getPointerJ();
    delete matrix
    ASSERT(ptr == nullptr);
}

template <typename T>
TEST_CASE(array_val) {
    int nrows = 10;
    int ncols = 20;
    SpMV::SparseMatrix_COO<T>* matrix = new SpMV::SparseMatrix_COO<T>(nrows, ncols);
    matrix->setCoefficient(1, 1, 2);
    matrix->assembleStorage();
    size_t*& ptr = matrix->getPointerVal();
    delete matrix
    ASSERT(ptr == nullptr);
}

// Create a test suite
template <typename T>
TEST_SUITE(construction) {
    TEST<T>(matrix_row_size);
    TEST<T>(matrix_col_size);
}

template <typename T>
TEST_SUITE(destruction) {
    TEST<T>(array_I);
    TEST<T>(array_J);
    TEST<T>(array_val);
}

auto
main() -> int
{
    RUN_SUITE(construction<int>);
    RUN_SUITE(construction<float>);
    RUN_SUITE(construction<double>);
    RUN_SUITE(destruction<int>);
    RUN_SUITE(destruction<float>);
    RUN_SUITE(destruction<double>);
    return 0; 
}
