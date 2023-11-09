#include <SpMV.hpp>

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"

// User ASSERT(condition) to test if a condition is true.
// Direct comparison of floating point numbers is not recommended, so we define
// ASSERT_NEAR(a, b, epsilon) to test if a and b are within epsilon of each
// other.

using namespace SpMV;

// Create a unit test
TEST_CASE(nominal) {

  SparseMatrix_COO<fp_type> A = SparseMatrix_COO<fp_type>(2,3);

  ASSERT(A.getNumRows() == 2);
  ASSERT(A.getNumCols() == 3);
  ASSERT(A.getFormat() == COO);
  ASSERT(A.getState() == initialized);
  ASSERT(A.getNumNonZeros() == 0);

}

TEST_CASE(null) {
    SparseMatrix_COO<fp_type> A = SparseMatrix_COO<fp_type>(0,0);
}

int main()
{
  // Run the unit tests. If a test fails, the program will print failure info
  // and return 1.
  TEST(nominal);
  return 0; 
}
