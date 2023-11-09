#include <SpMV.hpp>

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"

// User ASSERT(condition) to test if a condition is true.
// Direct comparison of floating point numbers is not recommended, so we define
// ASSERT_NEAR(a, b, epsilon) to test if a and b are within epsilon of each
// other.

using namespace SpMV;

// Test the basic constructor usage
TEST_CASE(nominalConstructor) {

  SparseMatrix_COO<fp_type> A = SparseMatrix_COO<fp_type>(2,3);

  ASSERT(A.getNumRows() == 2);
  ASSERT(A.getNumCols() == 3);
  ASSERT(A.getFormat() == COO);
  ASSERT(A.getState() == initialized);
  ASSERT(A.getNumNonZeros() == 0);

}

// Test overloaded constructor 
TEST_CASE(overloadedConstructor) {

  size_t  i[5],j[5];
  fp_type vals[5];

  for(size_t n=0; n<5; n++)
    vals[n] = static_cast<fp_type>(n);

  i[0] = 0;
  i[1] = 1;
  i[2] = 0;
  i[3] = 1;
  i[4] = 0;

  j[0] = 0;
  j[1] = 0;
  j[2] = 1;
  j[3] = 1;
  j[4] = 2;
  SparseMatrix_COO<fp_type> A = SparseMatrix_COO<fp_type>(2,3,5,&i[0],&j[0],&vals[0]);

  ASSERT(A.getNumRows() == 2);
  ASSERT(A.getNumCols() == 3);
  ASSERT(A.getFormat() == COO);
  ASSERT(A.getState() == assembled);
  ASSERT(A.getNumNonZeros() == 5);

  // Not a clean way to check values of _i,_j,_a 
  // We can use getCoefficient, but in some sense that may not be tested yet
  // This situation is not uncommon. My opinion is to test the values _i,_j,_a with getCoefficient
  // in the test for getCoefficient

}

// Test that null constructor is ok.
TEST_CASE(null) {
    SparseMatrix_COO<fp_type> A = SparseMatrix_COO<fp_type>(0,0);
}

int main()
{
  // Run the unit tests. If a test fails, the program will print failure info
  // and return 1.
  TEST(nominalConstructor);
  TEST(overloadedConstructor);
  TEST(null)
  return 0; 
}
