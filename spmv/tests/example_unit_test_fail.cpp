#include <SpMV.hpp>

#include <vector>
#include <csignal> // std::vector
#include <iostream>

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"

// User ASSERT(condition) to test if a condition is true.
// Direct comparison of floating point numbers is not recommended, so we define
// ASSERT_NEAR(a, b, epsilon) to test if a and b are within epsilon of each
// other.

// Create a unit test
TEST_CASE(fail_compareVectors) {

  // Initialize variables for testing
  std::vector<int> const a = {1, 3, 3};
  std::vector<int> const b = {1, 2, 3};

  // Test that the elements are equal
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT(a[i] == b[i]); 
  }
}

int main()
{
  // Run the unit tests. If a test fails, the program will print failure info
  // and return 1.

  TEST(fail_compareVectors);
  return 0;
}
