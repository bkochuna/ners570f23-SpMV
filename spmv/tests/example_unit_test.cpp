#include <SpMV.hpp>

#include <vector> // std::vector

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"

// User ASSERT(condition) to test if a condition is true.
// Direct comparison of floating point numbers is not recommended, so we define
// ASSERT_NEAR(a, b, epsilon) to test if a and b are within epsilon of each
// other.

// Create a unit test
TEST_CASE(compareVectors) {

  // Initialize variables for testing
  std::vector<int> const a = {1, 2, 3};
  std::vector<int> const b = {1, 2, 3};

  // Test that the elements are equal
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT(a[i] == b[i]); 
  }
  
  // Repeat for floating point numbers
  std::vector<fp_type> x = {1, 2, 3};
  std::vector<fp_type> y = {1, 2, 3.00001};

  // One should avoid floating point equality comparisons due to rounding errors
  // We will briefly turn off compiler warnings about this to demonstrate why
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
  //
  // In ℝ (real numbers), 0.1 + 0.2 == 0.3
  // However, in finite precision binary arithmetic, 0.1 + 0.2 != 0.3
  // In binary 0.1 is an irrational number, hence in finite precision it is
  // truncated, incuring a rounding error.
  ASSERT(0.1 + 0.2 != 0.3); // Will evaluate to true if 0.1 + 0.2 != 0.3
#pragma GCC diagnostic pop

  // Instead, we can test if the numbers are within a small epsilon of each
  // other
  auto const epsilon = static_cast<fp_type>(1e-3); 
  for (size_t i = 0; i < x.size(); ++i) {
    ASSERT_NEAR(x[i], y[i], epsilon); 
  }
}

int main()
{
  // Run the unit tests. If a test fails, the program will print failure info
  // and return 1.
  TEST(compareVectors);
  return 0; 
}
