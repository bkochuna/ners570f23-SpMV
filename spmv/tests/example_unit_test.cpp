#include <SpMV.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> // std::vector

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"
#include "SparseMatrix.hpp"
#include "SparseMatrix_DEN.hpp"

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

// We can also create templated tests and suites
template <typename T>
TEST_CASE(addition) {
  T const a = 1;
  T const b = 2;
  T const c = 3;
  ASSERT(a + b == c);
}

template <typename T>
TEST_CASE(subtraction) {
  T const a = 3;
  T const b = 2;
  T const c = 1;
  ASSERT(a - b == c);
}

template <size_t N, typename T>
TEST_CASE(fixed_size_dot_product) {
  // Create an array of N 1's and an array of N 2's
  T a[N]; 
  T b[N];
  for (size_t i = 0; i < N; ++i) {
    a[i] = 1;
    b[i] = 2;
  }
  // Compute the dot product
  T dot = 0;
  for (size_t i = 0; i < N; ++i) {
    dot += a[i] * b[i];
  }
  // Compare to the solution
  T const soln = 2 * N;
  ASSERT(dot == soln);
}

// Create a DEN view unit test
template <typename T>
TEST_CASE(sample_mat) {
  // size_t nrows = 5;
  // size_t ncols = 5;
  SpMV::SparseMatrix_DEN<double> *A = new SpMV::SparseMatrix_DEN<double>(5, 5);
  A->setCoefficient(0, 2, 2.5);
  A->setCoefficient(0, 3, 3.3);
  A->setCoefficient(2, 2, 2.0);
  A->setCoefficient(3, 2, 4.5);

  // Prints DENSE matrix in .out format 
  A->DEN_view();

  //print a sample DENSE matrix in .out format
  std::vector<std::vector<double>> matrix0 = {
      {0.0, 0.0, 2.5, 3.3, 0.0},
      {0.0, 0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 2.0, 0.0, 0.0},
      {0.0, 0.0, 4.5, 0.0, 0.0}};

  std::ofstream outputFile("DEN_ref.out");

  if (!outputFile)
  {
    std::cerr << "Failed to create or open the file." << std::endl;
  }

  // Write the matrix to the file
  outputFile << '[';
  for (const auto &row : matrix0)
  {
    for (const double &value : row)
    {
      outputFile << value << ' ';
    }
    outputFile << '\n'; // Start a new line for each row
  }
  outputFile << ']';
  outputFile.close();

  std::cout << "Matrix has been written to 'DEN_ref.out'." << std::endl;

  std::string filename1 = "DEN.out";
  std::string filename2 = "DEN_ref.out";

  std::vector<std::vector<double>> matrix1;
  std::vector<std::vector<double>> matrix2;
  std::ifstream inputFile1(filename1);

  if (!inputFile1)
  {
    std::cerr << "Failed to open the file: "  << std::endl;
    exit(1);
  }

  std::string line1;
  while (std::getline(inputFile1, line1))
  {
    std::vector<double> row;
    std::istringstream iss(line1);
    double value;
    while (iss >> value)
    {
      row.push_back(value);
    }
    matrix1.push_back(row);
  }

  inputFile1.close();
  std::ifstream inputFile2(filename2);

  if (!inputFile2)
  {
    std::cerr << "Failed to open the file: " << std::endl;
    exit(1);
  }

  std::string line2;
  while (std::getline(inputFile2, line2))
  {
    std::vector<double> row;
    std::istringstream iss(line2);
    double value;
    while (iss >> value)
    {
      row.push_back(value);
    }
    matrix2.push_back(row);
  }

  inputFile2.close();

  if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
  {
    std::cout << "Matrices have different dimensions" << std::endl;
    exit(1); // Matrices have different dimensions
  }

  for (size_t i = 0; i < matrix1.size(); ++i)
  {
    for (size_t j = 0; j < matrix1[i].size(); ++j)
    {
      if ((matrix1[i][j] - matrix2[i][j])<1e-4)
      {
        std::cout << "Matrices are not the same" << std::endl;
        exit(1); // Matrices differ at this element
      }
    }
  }

  std::cout << "Matrices are same" << std::endl; // Matrices are equal
}


template <typename T>
TEST_SUITE(add_sub_suite) {
  TEST(addition<T>);
  TEST(subtraction<T>);
  // Use parentheses to pass a function with multiple template arguments
  // This is necessary because a comma is used to separate arguments in a
  // template argument list as well as arguments to a macro
  TEST((fixed_size_dot_product<3, T>));
  TEST((fixed_size_dot_product<4, T>));
}

// Test suite for the Den view unit test
template <typename T>
TEST_SUITE(unit_test_suite) {
  //Run the random matrix unit test (for now just testing 5x5 matrix)
  TEST(sample_mat<T>);
}

auto
main() -> int
{
  // Run the unit tests. If a test fails, the program will print failure info
  // and return 1.
  RUN_SUITE(my_suite);
  RUN_SUITE(add_sub_suite<int>);
  RUN_SUITE(add_sub_suite<size_t>);
  RUN_SUITE(unit_test_suite<double>);
  return 0; 
}
