#include <SpMV.hpp>
#include "unit_test_framework.hpp"

template <typename T>
TEST_CASE(all_tests) {
    int nrows = 10;
    int ncols = 20;
    size_t[2] colIdx = {5, 2};
    fp_type[2] val = {1.0, 2.0}; 
    size_t nrowsmax = 2;  
    SpMV::SparseMatrix_ELL<T>* matrix = new SpMV::SparseMatrix_ELL<T>(nrows, ncols, &colIdx[0], &val[0], nrowsmax);
    ASSERT(matrix.getNumRows() == static_cast<size_t>(nrows));
    ASSERT(matrix.getNumCols() == static_cast<size_t>(ncols));
    size_t * ell_colIdx = matrix.getColIdxPtr();
    ASSERT(ell_colIdz[0] = 5);
    ASSERT(ell_colIdz[1] = 5);
    fp_type * ell_val = matrix.getValPtr();
    ASSERT(ell_val[0] = 1.0);
    ASSERT(ell_val[1] = 2.0);
    ASSERT(true);
}
    

// Create a test suite
template <typename T>
TEST_SUITE(construction) {
    TEST(all_tests);
}

auto
main() -> int
{
    RUN_SUITE(construction<float>);
    RUN_SUITE(construction<double>);
    return 0; 
}
