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

    int idx[4] = {0, 1, 2, 3};
    int jdx[4] = {0, 1, 2, 3};
    T rval[4] = {T(2.0), T(3.0), T(-6.5), T(-8.1)};

    string reference;
    int k = 0;
    int i = 0;

    T value;
    ifstream ViewResults("./COO.out");
    while (getline(ViewResults, reference)){

        int j = 0;
        istringstream iss(reference);
        while(iss >> value){
            if (i==idx[k] && j==jdx[k]){
                ASSERT_NEAR(value, T(rval[k]), T(1.E-6));
                k++;
            } else {
                ASSERT_NEAR(value, T(0.), T(1.E-6));
            }
            j++;
        }

        i++;
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

    int idx[6] = {0, 0, 0, 1, 1, 2};
    int jdx[6] = {0, 1, 2, 0, 1, 0};
    T rval[6] = {T(2.0), T(-2.0), T(12.0), T(-3.0), T(-12.5), T(-6.1)};

    string reference;
    int k = 0;
    int i = 0;

    T value;
    ifstream ViewResults("./COO.out");
    while (getline(ViewResults, reference)){

        int j = 0;
        istringstream iss(reference);
        while(iss >> value){
            if (i==idx[k] && j==jdx[k]){
                ASSERT_NEAR(value, T(rval[k]), T(1.E-6));
                k++;
            } else {
                ASSERT_NEAR(value, T(0.), T(1.E-6));
            }
            j++;
        }
        i++;
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
