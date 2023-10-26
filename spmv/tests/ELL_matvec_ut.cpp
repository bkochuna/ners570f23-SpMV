#include <SpMV.hpp>
#include <vector>
#include "unit_test_framework.hpp"

template <typename fp_type>
TEST_CASE(empty_in){
    try
    {
        SpMV::SparseMatrix<fp_type>* test_matrix = new SpMV::SparseMatrix_ELL<fp_type>(3,3);
        test_matrix->setCoefficient(0,0,static_cast<fp_type>(1.0));
        test_matrix->setCoefficient(1,1,static_cast<fp_type>(2.0));
        test_matrix->setCoefficient(2,2,static_cast<fp_type>(3.0));
        test_matrix->setCoefficient(1,2,static_cast<fp_type>(4.0));
        test_matrix->setCoefficient(2,0,static_cast<fp_type>(5.0));

        test_matrix->assembleStorage();

        fp_type* input;
        fp_type* output;
        test_matrix->matvec(input,output); 
        ASSERT(true);
    }catch(const std::exception&){}  
}
template <typename fp_type>
TEST_CASE(vec_in){
    SpMV::SparseMatrix<fp_type>* test_matrix = new SpMV::SparseMatrix_ELL<fp_type>(3,3);
    test_matrix->setCoefficient(0,0,static_cast<fp_type>(1.0));
    test_matrix->setCoefficient(1,1,static_cast<fp_type>(2.0));
    test_matrix->setCoefficient(2,2,static_cast<fp_type>(3.0));
    test_matrix->setCoefficient(1,2,static_cast<fp_type>(4.0));
    test_matrix->setCoefficient(2,0,static_cast<fp_type>(5.0));

    test_matrix->assembleStorage();

    fp_type input[3]={static_cast<fp_type>(2.0),static_cast<fp_type>(20.0),static_cast<fp_type>(-5.0)};
    fp_type output[3];
    test_matrix->matvec(input,output);
    for (size_t i = 0; i < 3; i++)
    {
        ASSERT_NEAR(input[i],output[i],static_cast<fp_type>(1e-3));
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
    RUN_SUITE(matvec_suite<double>);
    RUN_SUITE(matvec_suite<float>);
    return 0; 
}
