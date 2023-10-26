#include "SpMV.hpp"
#include "SparseMatrix_CSR.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#include <vector> // std::vector

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"

using namespace std;

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
  std::vector<double> x = {1, 2, 3};
  std::vector<double> y = {1, 2, 3.00001};

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
  for (size_t i = 0; i < x.size(); ++i) {
    ASSERT_NEAR(x[i], y[i], 1e-3); 
  }
}

// Create a test suite
TEST_SUITE(my_suite) {
  // Run the unit test when the suite is run
  TEST(compareVectors);
}

// Test for getFormat
template <typename T>
TEST_CASE(getFormatTest) {

  SpMV::SparseMatrix_CSR<T> Af = SpMV::SparseMatrix_CSR<T>(3,3);

  string frmt_String = "CSR";
  ASSERT(Af.getFormat() == frmt_String);

}

// Test for CSR_View_Func
template <typename T>
TEST_CASE(ViewFuncTest) {

    const string pathname = "./Test_CSR_view.txt";
    SpMV::SparseMatrix_CSR<T> Af = SpMV::SparseMatrix_CSR<T>(4, 4);

    // Example of the HW2 instructions of CSR format
    // Set Coefficients & View (Saved as file in <pathname>)
    Af.setCoefficient(0, 0, T(1.));
    Af.setCoefficient(1, 3, T(9.));
    Af.setCoefficient(0, 1, T(7.));
    Af.setCoefficient(2, 1, T(2.));
    Af.setCoefficient(2, 2, T(8.));
    Af.setCoefficient(3, 3, T(6.));
    Af.setCoefficient(1, 0, T(5.));
    Af.setCoefficient(1, 2, T(3.));
    Af.CSR_view(pathname);

    // To read the results of "View" and check
    int indx[8] = {0, 0, 1, 1, 1, 2, 2, 3};
    int jndx[8] = {0, 1, 0, 2, 3, 1, 2, 3};
    T rval[8] = {T(1.), T(7.), T(5.), T(3.), 
                T(9.), T(2.), T(8.), T(6.)};
    
    string line;
    int k = 0, idx = 0, jdx;
    T value;
    ifstream ViewResults(pathname);
    while (getline(ViewResults, line)){
        
        jdx = 0;
        istringstream iss(line);
        while(iss >> value){
            if (idx==indx[k] and jdx==jndx[k]){
                ASSERT_NEAR(value, T(rval[k]), T(1.E-6));
                // cout << k << rval[k] << endl;
                k++;
            } else {
                // cout << k << value << endl;
                ASSERT_NEAR(value, T(0.), T(1.E-6));
            }
            jdx++;
        }
        idx++;
    }

}

template <typename T>
TEST_SUITE(CSR_View_Tests) {
  TEST(getFormatTest<T>);
  TEST(ViewFuncTest<T>);
}

auto
main() -> int
{
  // Run the unit tests. If a test fails, the program will print failure info
  // and return 1.
  RUN_SUITE(my_suite);
//   RUN_SUITE(CSR_View_Tests<int>);
//   RUN_SUITE(CSR_View_Tests<long>);
  RUN_SUITE(CSR_View_Tests<float>);
  RUN_SUITE(CSR_View_Tests<double>);
  return 0; 
}
