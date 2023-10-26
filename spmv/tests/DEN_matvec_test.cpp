#include <SpMV.hpp>
#include <vector>
#include <SparseMatrix.hpp>
#include <SparseMatrix_DEN.hpp>
#include "unit_test_framework.hpp"

namespace SpMV
{

    // Create a test dense matrix for use in the following test cases
    void createTestDenseMatrix(SparseMatrix<double> **test_matrix)
    {
        int n_rows = 3;
        int n_cols = 3;
        (*test_matrix) = new SparseMatrix_DEN<double>(n_rows, n_cols);

        (*test_matrix)->setCoefficient(0, 0, 3);
        (*test_matrix)->setCoefficient(0, 1, 5);
        (*test_matrix)->setCoefficient(1, 0, 6);
        (*test_matrix)->setCoefficient(1, 1, 7);
        (*test_matrix)->setCoefficient(1, 2, 8);
        (*test_matrix)->setCoefficient(2, 1, 9);
        (*test_matrix)->setCoefficient(2, 2, 10);

        (*test_matrix)->assembleStorage();
    }

    TEST_CASE(dense_empty_in)
    {
        try
        {
            SparseMatrix<double> *test_matrix;
            createTestDenseMatrix(&test_matrix);
            double *input;
            double *output;
            test_matrix->matvec(input, output);
            ASSERT(false); // Should not reach this line because matvec should throw an exception for uninitialized input
        }
        catch (const std::runtime_error &)
        {
            // Exception caught as expected
        }
    }

    TEST_CASE(dense_vec_in)
    {
        SparseMatrix<double> *test_matrix;
        createTestDenseMatrix(&test_matrix);
        double input[3] = {2.5, 1.5, 3.0}; // Changed input vector
        double output[3];
        test_matrix->matvec(input, output);

        double expectedOutput[3] = {13.5, 41.5, 42.0}; // Based on the matrix-vector multiplication
        for (size_t i = 0; i < 3; ++i)
        {
            ASSERT_NEAR(expectedOutput[i], output[i], 1e-3);
        }
    }

    TEST_SUITE(dense_matvec_suite)
    {
        TEST(dense_empty_in);
        TEST(dense_vec_in);
    }

}

auto main() -> int
{
    SpMV::TEST_SUITE(dense_matvec_suite);
    return 0;
}
