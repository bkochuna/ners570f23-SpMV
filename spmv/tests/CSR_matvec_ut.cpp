#include <SpMV.hpp>
#include <vector>
#include "unit_test_framework.hpp"

namespace SpMV{

    template <typename fp_type>
    void createTestMatrix(SparseMatrix_CSR<fp_type>** test_matrix){
        int n_rows = 3;
        int n_cols = 3;
        (*test_matrix) = new SparseMatrix_CSR<fp_type>(n_rows,n_cols);

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
            SparseMatrix_CSR<fp_type>* test_matrix;
            createTestMatrix(&test_matrix);
            fp_type input[2];
            fp_type output[2];
            test_matrix->matvec(input,output);
            ASSERT(false);
        }catch(const std::runtime_error&){
            
        }
        // update implementation for templating
    }

    TEST_CASE(vec_in) 
    {
        
        SparseMatrix_CSR<fp_type>* test_matrix;
        createTestMatrix(&test_matrix);
        fp_type input[3]={1,0,5};
        fp_type output[3];
        fp_type output_corr[3] = {1,20,20};
        test_matrix->matvec(input,output);
        fp_type error = 1e-3f;
        for (size_t i = 0; i < 3; ++i) {
            ASSERT_NEAR(output_corr[i], output[i], error); 
        }
        
        // update implementation for templating
    }

    
}
int main(){
    TEST(SpMV::vec_in);
    TEST(SpMV::empty_in);
    return 0; 
}

