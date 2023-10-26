#include <SpMV.hpp>
#include <vector> // std::vector
#include <string>
#include <stdlib.h>

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"


// Test for number of rows
template <size_t N,typename T>
TEST_CASE(getRowsTest) {

  SpMV::SparseMatrix_DEN<T> AD = SpMV::SparseMatrix_DEN<T>(N,2);
  ASSERT(AD.getNumRows_DEN() == N);

}


// Test for number of columns
template <size_t N,typename T>
TEST_CASE(getColsTest) {

  SpMV::SparseMatrix_DEN<T> AD = SpMV::SparseMatrix_DEN<T>(2,N);
  ASSERT(AD.getNumCols_DEN() == N);

}


// Test for getCoeffs and setCoeffs
template <typename T>
TEST_CASE(getCoefTest) {

  SpMV::SparseMatrix_DEN<T> AD = SpMV::SparseMatrix_DEN<T>(5,5);

  AD.setCoefficient_DEN(2,4,static_cast<T>(3.14));

  ASSERT_NEAR(AD.getCoef(2,4), static_cast<T>(3.14), static_cast<T>(1e-3));

}


// Test for getCoef for initialized zero matrix 
template <typename T>
TEST_CASE(getCoefInitTest) {

  SpMV::SparseMatrix_DEN<T> AD = SpMV::SparseMatrix_DEN<T>(5,5);
  ASSERT_NEAR(AD.getCoef(2,4), static_cast<T>(0.0),static_cast<T>(1e-3));

}


// Test for getFormat
template <typename T>
TEST_CASE(getFormatTest) {

  SpMV::SparseMatrix_DEN<T> AD = SpMV::SparseMatrix_DEN<T>(3,3);

  std::string fmt_String = "DEN";
  ASSERT(AD.getFormat() == fmt_String);

}

auto
main() -> int
{
    
    TEST((getRowsTest<6,float>));
    TEST((getColsTest<6,float>));
    TEST(getCoefTest<float>);
    TEST(getCoefInitTest<float>);
    TEST(getFormatTest<float>);
    
    TEST((getRowsTest<6,double>));
    TEST((getColsTest<6,double>));
    TEST(getCoefTest<double>);
    TEST(getCoefInitTest<double>);
    TEST(getFormatTest<double>);
    return 0; 
}

