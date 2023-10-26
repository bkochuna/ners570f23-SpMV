#include <SpMV.hpp>

#include <vector> // std::vector
#include <string>

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"


// Test for getRows
template <size_t N,typename T>
TEST_CASE(getRowsTest) {

  SpMV::SparseMatrix_CSR<T> Af = SpMV::SparseMatrix_CSR<T>(N,2);
  ASSERT(Af.getNumRows() == N);

}


// Test for getCols
template <size_t N,typename T>
TEST_CASE(getColsTest) {

  SpMV::SparseMatrix_CSR<T> Af = SpMV::SparseMatrix_CSR<T>(2,N);
  ASSERT(Af.getNumCols() == N);

}


// Test for getCoeffs
template <typename T>
TEST_CASE(getCoefTest) {

  SpMV::SparseMatrix_CSR<T> Af = SpMV::SparseMatrix_CSR<T>(5,5);

  Af.setCoefficient(3,2,static_cast<T>(3.67));

  ASSERT_NEAR(Af.getCoef(3,2), static_cast<T>(3.67), static_cast<T>(1e-3));

}


// Test for getCoeffs for initialized matrix
template <typename T>
TEST_CASE(getCoefInitTest) {

  SpMV::SparseMatrix_CSR<T> Af = SpMV::SparseMatrix_CSR<T>(5,5);

  ASSERT_NEAR(Af.getCoef(3,2), static_cast<T>(0.0), static_cast<T>(1e-3));

}


// Test for getFormat
template <typename T>
TEST_CASE(getFormatTest) {

  SpMV::SparseMatrix_CSR<T> Af = SpMV::SparseMatrix_CSR<T>(3,3);

  std::string frmt_String = "CSR";
  ASSERT(Af.getFormat() == frmt_String);

}


template <typename T>
TEST_SUITE(CSR_accessor_tests) {
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
  RUN_SUITE(CSR_accessor_tests<float>);
  RUN_SUITE(CSR_accessor_tests<double>);
  return 0; 
}