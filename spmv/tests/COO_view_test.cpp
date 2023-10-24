#include <iostream>
#include <sstream>
#include <SpMV.hpp>
#include "unit_test_framework.hpp"


// Create a unit test
template <typename T>
TEST_CASE(Diagonal) {
    size_t nrows = 4;
    size_t ncols = 4;
    SpMV::SparseMatrix_COO<T> matrix = SparseMatrix_COO<T>(nrows, ncols);
    matrix.setCoefficient(0, 0, 2.0);
    matrix.setCoefficient(1, 1, 3.0);
    matrix.setCoefficient(2, 2, -6.5);
    matrix.setCoefficient(3, 3, -8.1);

    std::stringstream buffer;
    std::streambuf * old = std::cout.rduf(buffer.rduf());

    matrix.COO_view();
    
    std:: string text = buffer.str();
    std::cerr << "The string is: " << text << std:endl;

    std::string text_ref = "2.0 0.0 0.0 0.0 \n 0.0 3.0 0.0 0.0 \n 0.0 0.0 -6.5 0.0 \n 0.0 0.0 0.0 -8.1";

    if (text == text_ref){
        std::cerr << "Test passed" << std:endl;
    } else {
        std::cerr << "Test failed" << std::endl;
        return 1;
    }

    return 0;
}

template <typename T>
TEST_CASE(Uppertri) {
    size_t nrows = 3;
    size_t ncols = 3;
    SpMV::SparseMatrix_COO<T> matrix = SparseMatrix_COO<T>(nrows, ncols);
    matrix.setCoefficient(0, 0, 2.0);
    matrix.setCoefficient(0, 1, -2.0);
    matrix.setCoefficient(0, 2, 12.0);
    matrix.setCoefficient(1, 0, -3.0);
    matrix.setCoefficient(1, 1, -12.5);
    matrix.setCoefficient(2, 0, -6.1);

    std::stringstream buffer;
    std::streambuf * old = std::cout.rduf(buffer.rduf());

    matrix.COO_view();
    
    std:: string text = buffer.str();
    std::cerr << "The string is: " << text << std:endl;

    std::string text_ref = "2.0 -2.0 12.0 \n -3.0 -12.5 0.0 \n -6.1 0.0 0.0";

    if (text == text_ref){
        std::cerr << "Test passed" << std::endl;
    } else {
        std::cerr << "Test failed" << std::endl;
        return 1;
    }

    return 0;
}


// Create a test suite
template <typename T>
TEST_SUITE(my_suite) {
  // Run the unit test when the suite is run
  TEST(Diagonal<T>);
  TEST(Uppertri<T>);

}

auto
main() -> int
{
  // Run the unit tests. If a test fails, the program will print failure info
  // and return 1.
  RUN_SUITE(my_suite<double>);
  return 0; 
}
