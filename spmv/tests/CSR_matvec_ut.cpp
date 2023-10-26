#include <SpMV.hpp>
#include <vector>
#include "unit_test_framework.hpp"

namespace SpMV{

    void createTestMatrix(SparseMatrix<double>** test_matrix){
        int n_rows = 3;
        int n_cols = 3;
        (*test_matrix) = new SparseMatrix_CSR<double>(n_rows,n_cols);

        (*test_matrix)->setCoefficient(0,0,1);
        (*test_matrix)->setCoefficient(1,1,2);
        (*test_matrix)->setCoefficient(2,2,3);
        (*test_matrix)->setCoefficient(1,2,4);
        (*test_matrix)->setCoefficient(2,0,5);

        (*test_matrix)->assembleStorage();

    }


    TEST_CASE(empty_in) 
    {
        try{
            SparseMatrix<double>* test_matrix;
            createTestMatrix(&test_matrix);
            double * input;
            double * output;
            test_matrix->matvec(input,output);
            ASSERT(false);
        }catch(const std::runtime_error&){
            
        }
        // update implementation for templating
    }
    TEST_CASE(vec_in) 
    {
        
        SparseMatrix<double>* test_matrix;
        createTestMatrix(&test_matrix);
        double input[3]={1,0,5};
        double output[3];
        test_matrix->matvec(input,output);
        for (size_t i = 0; i < 3; ++i) {
            ASSERT_NEAR(input[i], output[i], 1e-3); 
        }
        
        // update implementation for templating
    }
    TEST_SUITE(matvec_suite) {
        TEST(empty_in);
        TEST(vec_in);
    }
}

