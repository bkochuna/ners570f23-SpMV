#include <SpMV.hpp>

#include <vector> // std::vector
#include <string>

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"


// Test for getRows
template <size_t N,typename T>
TEST_CASE(getRowsTest) {

  SpMV::SparseMatrix_COO<T> Af = SpMV::SparseMatrix_COO<T>(N,2);
  ASSERT(Af.getNumRows() == N);

}


// Test for getCols
template <size_t N,typename T>
TEST_CASE(getColsTest) {

  SpMV::SparseMatrix_COO<T> Af = SpMV::SparseMatrix_COO<T>(2,N);
  ASSERT(Af.getNumCols() == N);

}


// Test for getCoeffs
template <typename T>
TEST_CASE(getCoefTest) {

  SpMV::SparseMatrix_COO<T> Af = SpMV::SparseMatrix_COO<T>(5,5);

  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wfloat-equal"
  #pragma GCC diagnostic ignored "-Werror=float-conversion"
  #pragma GCC diagnostic ignored "-Werror=double-promotion"

  T aij = 3.67;
  Af.setCoefficient(3,2,aij);

  ASSERT_NEAR(Af.getCoefficient(3,2), aij, 1e-3);

  #pragma GCC diagnostic pop

}


// Test for getCoeffs for initialized matrix
template <typename T>
TEST_CASE(getCoefInitTest) {

  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wfloat-equal"
  #pragma GCC diagnostic ignored "-Werror=float-conversion"
  #pragma GCC diagnostic ignored "-Werror=double-promotion"

  SpMV::SparseMatrix_COO<T> Af = SpMV::SparseMatrix_COO<T>(5,5);

  ASSERT_NEAR(Af.getCoefficient(3,2), 0.0, 1e-3);

  #pragma GCC diagnostic pop

}


// Test for getFormat
template <typename T>
TEST_CASE(getFormatTest) {

  SpMV::SparseMatrix_COO<T> Af = SpMV::SparseMatrix_COO<T>(3,3);

  std::string frmt_String = "COO";
  ASSERT(Af.getFormat() == frmt_String);

}


template <typename T>
TEST_SUITE(COO_accessor_tests) {
  TEST((getRowsTest<6,T>));
  TEST((getColsTest<6,T>));
  TEST(getCoefTest<T>);
  TEST(getCoefInitTest<T>);
  TEST(getFormatTest<T>);
}


auto
main() -> int
{
  // Run the unit tests. If a test fails, the program will print failure info
  // and return 1.
  RUN_SUITE(COO_accessor_tests<float>);
  RUN_SUITE(COO_accessor_tests<double>);
  return 0; 
}
