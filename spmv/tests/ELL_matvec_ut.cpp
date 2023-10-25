#include <SpMV.hpp>
#include <vector>
#include "unit_test_framework.hpp"

namespace SpMV{
    template <typename fp_type>
    TEST_CASE(empty_in){
        try
        {
            SparseMatrix<fp_type>* test_matrix = new SparseMatrix_ELL<fp_type>(3,3);
            test_matrix->setCoefficient(0,0,1.0);
            test_matrix->setCoefficient(1,1,2.0);
            test_matrix->setCoefficient(2,2,3.0);
            test_matrix->setCoefficient(1,2,4.0);
            test_matrix->setCoefficient(2,0,5.0);

            test_matrix->assembleStorage();

            fp_type* input;
            fp_type* output;
            test_matrix->matvec(input,output);
            ASSERT(false);
        }catch(const std::exception&)
        
    }
    template <typename fp_type>
    TEST_CASE(vec_in){
        SparseMatrix<fp_type>* test_matrix = new SparseMatrix_ELL<fp_type>(3,3);
        test_matrix->setCoefficient(0,0,1.0);
        test_matrix->setCoefficient(1,1,2.0);
        test_matrix->setCoefficient(2,2,3.0);
        test_matrix->setCoefficient(1,2,4.0);
        test_matrix->setCoefficient(2,0,5.0);

        test_matrix->assembleStorage();

        fp_type input[3]={2.0,20.0,-5.0};
        fp_type output[3];
        test_matrix->matvec(input,output);
        for (size_t i = 0; i < 3; i++)
        {
            ASSERT_NEAR(input[i],output[i],1e-3);
        }
        
    }
    template<typename fp_type>
    TEST_SUITE(matvec_suite){
        TEST(empty_in<fp_type>);
        TEST(vec_in<fp_type>);
    }

    auto
    main() -> int
    {
        RUN_SUITE(matvec_suite<float>);
        return 0; 
    }
}
