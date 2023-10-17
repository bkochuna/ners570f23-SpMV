#include <SpMV.hpp>
#include <vector>
#include "unit_test_framework.hpp"

namespace SpMV{
    TEST_CASE(int_in) 
    {
        try{
            int input = 0;
            SparseMatrix<double>* test_matrix = new SparseMatrix_CSR()
            test_matrix::matvec(input);
            ASSERT(false);
        }catch(const std::runtime_error&){
            
        }
        // update implementation for templating
    }

}

