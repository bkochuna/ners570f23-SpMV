#include <SpMV.hpp>
#include <vector> 
#include "unit_test_framework.hpp"

namespace SpMV{

    TEST_CASE(diagonal) 
    {
        size_t n_rows = 4;
        size_t n_cols = 4;
        SparseMatrix_ELL<double> *test_matrix = new SparseMatrix_ELL<double>(n_rows,n_cols);
        test_matrix->setCoefficient(0,0,-2);
        test_matrix->setCoefficient(1,1,-2);
        test_matrix->setCoefficient(2,2,-2);
        test_matrix->setCoefficient(3,3,-2);
        test_matrix->assembleStorage();
        std::vector<double> true_colidx{ 0, 1, 2, 3 };
        std::vector<double> true_value{ -2, -2, -2, -2 };
        for (size_t i = 0; i < 4; i++) {
            ASSERT_NEAR(true_colidx[i], this->colIdx[i], 1e-4); 
            ASSERT_NEAR(true_value[i], this->val[i], 1e-4); 
        }
    }

    TEST_CASE(lower_tri) 
    {
        size_t n_rows = 4;
        size_t n_cols = 4;
        SparseMatrix_ELL<float> *test_matrix = new SparseMatrix_ELL<float>(n_rows,n_cols);

        test_matrix->setCoefficient(0,0,-1);
        test_matrix->setCoefficient(1,0,5);
        test_matrix->setCoefficient(1,1,-7);
        test_matrix->setCoefficient(2,0,6);
        test_matrix->setCoefficient(2,1,4);
        test_matrix->setCoefficient(2,2,3);
        test_matrix->setCoefficient(3,0,-3);
        test_matrix->setCoefficient(3,3,3);
        test_matrix->assembleStorage();
        // Here I use -10000 for padding index 
        std::vector<float> true_colidx{ 0, 0, 0, 0, -10000,1,1,3,-10000,-10000,2,-10000 };
        std::vector<float> true_value{ -1, 5, 6, -3, -10000, -7, 4, 3, -10000,-10000,2,-10000 };
        for (size_t i = 0; i < 12; i++) {
            ASSERT_NEAR(true_colidx[i], this->colIdx[i], 1e-4); 
            ASSERT_NEAR(true_value[i], this->val[i], 1e-4); 
        }
    }

TEST_SUITE(my_suite) {
  TEST(diagonal);
  TEST(lower_tri);
}

auto
main() -> int
{
  // Run the unit tests. If a test fails, the program will print failure info
  // and return 1.
  RUN_SUITE(my_suite);
  return 0; 
}


}