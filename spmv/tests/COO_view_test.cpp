#include "SpMV.hpp"
#include "SparseMatrix_COO.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "unit_test_framework.hpp"

using namespace std;

// Create a unit test
template <typename T>
TEST_CASE(Diagonal) {
    SpMV::SparseMatrix_COO<T> matrix = SpMV:: SparseMatrix_COO<T>(4, 4);
    matrix.setCoefficient(0, 0, T(2.0));
    matrix.setCoefficient(1, 1, T(3.0));
    matrix.setCoefficient(2, 2, T(-6.5));
    matrix.setCoefficient(3, 3, T(-8.1));

    matrix.COO_view();

    // int idx[4] = {0, 1, 2, 3};
    // int jdx[4] = {0, 1, 2, 3};
    // T rval[4] = {T(2.0), T(3.0), T(-6.5), T(-8.1)};

    // string reference;
    std::string reference = "0,0,2.0    1,1,3.0    2,2,-6.5    3,3,-8.1    ";

    // int k = 0;
    // int i = 0;

    // T value;
    ifstream ViewResults("COO.out");
    std::string line;
        while (std::getline(ViewResults, line)) {
            std::cout << line << std::endl;
        }
    if (reference == line){
        std::cerr << "Test passed" << std::endl;
    } else{
        std::cerr << "Test failed" << std::endl;
    }

}

template <typename T>
TEST_CASE(Uppertri) {
    SpMV::SparseMatrix_COO<T> matrix = SpMV::SparseMatrix_COO<T>(3, 3);
    matrix.setCoefficient(0, 0, T(2.0));
    matrix.setCoefficient(0, 1, T(-2.0));
    matrix.setCoefficient(0, 2, T(12.0));
    matrix.setCoefficient(1, 0, T(-3.0));
    matrix.setCoefficient(1, 1, T(-12.5));
    matrix.setCoefficient(2, 0, T(-6.1));

    matrix.COO_view();

    // int idx[6] = {0, 0, 0, 1, 1, 2};
    // int jdx[6] = {0, 1, 2, 0, 1, 0};
    // T rval[6] = {T(2.0), T(-2.0), T(12.0), T(-3.0), T(-12.5), T(-6.1)};

    // string reference;
    // int k = 0;
    // int i = 0;

    std::string reference = "0,0,2.0    0,1,-2.0    0,2,12.0    1,0,-3.0    1,1,-12.5    2,0,-6.1    ";

    // int k = 0;
    // int i = 0;

    // T value;
    ifstream ViewResults("COO.out");
    std::string line;
        while (std::getline(ViewResults, line)) {
            std::cout << line << std::endl;
        }
    if (reference == line){
        std::cerr << "Test passed" << std::endl;
    } else{
        std::cerr << "Test failed" << std::endl;
    }
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
