#include <SpMV.hpp>
#include<stdexcept>
#include <vector> // std::vector
#include <string>
#include <stdio.h>

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"


TEST_CASE(getRowsTest) {

  SpMV::SparseMatrix_ELL<fp_type> Af = SpMV::SparseMatrix_ELL<fp_type>(6,4);
  ASSERT(Af.getNumRows() == 6);

}

TEST_CASE(getColsTest) {

  SpMV::SparseMatrix_ELL<fp_type> Af = SpMV::SparseMatrix_ELL<fp_type>(4,6);
  ASSERT(Af.getNumCols() == 6);

}



TEST_CASE(getCoefTest) {

  SpMV::SparseMatrix_ELL<fp_type> Af = SpMV::SparseMatrix_ELL<fp_type>(5,5);
  
  Af.setCoefficient(3,2,static_cast<fp_type>(3.67));
  Af.assembleStorage();
  std::cout<<"here";

  ASSERT_NEAR(Af(3,2), static_cast<fp_type>(3.67), static_cast<fp_type>(1e-3));

}


// Test for getCoeffs for initialized matrix
TEST_CASE(getCoefInitTest) {

  SpMV::SparseMatrix_ELL<fp_type> Af = SpMV::SparseMatrix_ELL<fp_type>(5,5);
  try{
    Af(3,2);
    
  }
  catch(...){

  }

}


// Test for getFormat
TEST_CASE(getFormatTest) {

  SpMV::SparseMatrix_ELL<fp_type> Af = SpMV::SparseMatrix_ELL<fp_type>(3,3);

  std::string frmt_String = "ELL";
  ASSERT(Af.getFormat() == frmt_String);

}

auto
main() -> int
{
    
    TEST(getRowsTest);
    TEST(getColsTest);
    TEST(getCoefTest);
    TEST(getCoefInitTest);
    TEST(getFormatTest);
    return 0; 
}