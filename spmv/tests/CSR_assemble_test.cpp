#include <SpMV.hpp>

#include <vector> // std::vector

#include "unit_test_framework.hpp"

// TESTS FOR CONSTRUCTOR
// - Max Herzog (maxzog)

// Unit test for constructor
// Takes in num rows and num cols
// Checks that those are stored correctly
template <size_t nr, size_t nc, typename T>
TEST_CASE(base_assemble) {
  SpMV::SparseMatrix_CSR<T> A = SparseMatrix_CSR(nr,nc);
  ASSERT(A._nrows == nr); 
  ASSERT(A._ncols == nc);
  // Bonuse test that rowPtrs is of length nrows + 1
  ASSERT(A.rowPtrs.size() == nr+1); 
}

// Unit test for constructor w/ example matrix
template <typename T>
TEST_CASE(popu_assemble) {
  SpMV::SparseMatrix_CSR<T> A = SparseMatrix_CSR(4,4);
  
  // Populate with sample matrix
  A.setCoefficient(0,0,1.0);
  A.setCoefficient(1,3,9.0);
  A.setCoefficient(0,1,7.0);
  A.setCoefficient(2,1,2.0);
  A.setCoefficient(2,2,8.0);
  A.setCoefficient(3,3,6.0);
  A.setCoefficient(1,0,5.0);
  A.setCoefficient(1,2,3.0);

  // Check number of non-zeros
  ASSERT(A._nnz == 8);

  ASSERT(A.rowPtrs.size() == 5); // should be nrows+1
  ASSERT(A.colIdx.size() == 8);  // should be nnz
  ASSERT(A.value.size() == 8);   // should be nnz
  
  // Make CSR vectors from example matrix
  std::vector<size_t> const rowT = {0, 2, 5, 7, 8};
  std::vector<size_t> const colT = {0, 1, 0, 2, 3, 1, 2, 3};
  std::vector<T> const valT = {1.0, 7.0, 5.0, 3.0, 9.0, 2.0, 8.0, 6.0};

  // Check that they were constructed correctly
  ASSERT(A.rowPtrs == rowT);
  ASSERT(A.colIdx == colT);
  ASSERT(A.value == valT);
}

// test suite for running all the tests
template <typename T>
TEST_SUITE(suiteass) {
  TEST(base_assemble<4,4,T>);
  TEST(base_assemble<32,32,T>);
  TEST(popu_assemble<T>);
}


auto
main() -> int
{
  RUN_SUITE(suiteass<float>);
  RUN_SUITE(suiteass<double>);
  return 0; 
}
