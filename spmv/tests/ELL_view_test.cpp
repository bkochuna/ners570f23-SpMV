#include <iostream>
#include <sstream>
#include "unit_test_framework.hpp"
#include "SpMV.hpp"
#include "SparseMatrix_ELL.hpp"

template <typename T>
TEST_CASE(Diagonal_ELL) {
    size_t nrows = 4;
    size_t ncols = 4;
    SpMV::SparseMatrix_ELL<T> matrix = SparseMatrix_ELL<T>(nrows, ncols);
    matrix.setCoefficient(0, 0, 2.0);
    matrix.setCoefficient(1, 1, 3.0);
    matrix.setCoefficient(2, 2, -6.5);
    matrix.setCoefficient(3, 3, -8.1);

    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

    matrix.ELL_view();

    std:: string text = buffer.str();
    std::cerr << "The string is: " << text << std::endl;

    std::string text_ref = "2.0 0.0 0.0 0.0\n0.0 3.0 0.0 0.0\n0.0 0.0 -6.5 0.0\n0.0 0.0 0.0 -8.1";

    if (text == text_ref){
        std::cerr << "Test passed" << std::endl;
    } else {
        std::cerr << "Test failed" << std::endl;
        return 1;
    }

    return 0;
}

template <typename T>
TEST_CASE(None_Diagonal_ELL) {
    size_t nrows = 3;
    size_t ncols = 3;
    SpMV::SparseMatrix_ELL<T> matrix = SparseMatrix_ELL<T>(nrows, ncols);
    matrix.setCoefficient(0, 1, 2.0);
    matrix.setCoefficient(1, 0, 3.0);
    matrix.setCoefficient(2, 0, -6.5);

    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

    matrix.ELL_view();

    std:: string text = buffer.str();
    std::cerr << "The string is: " << text << std::endl;

    std::string text_ref = "0.0 2.0 0.0\n3.0 0.0 0.0\n-6.5 0.0 0.0";

    if (text == text_ref){
        std::cerr << "Test passed" << std::endl;
    } else {
        std::cerr << "Test failed" << std::endl;
        return 1;
    }

    return 0;
}

template <typename T>
TEST_SUITE(ell_suite) {
  TEST(Diagonal_ELL<T>);
  TEST(None_Diagonal_ELL<T>);
}

auto
main() -> int
{
  RUN_SUITE(ell_suite<double>);
  return 0; 
}
