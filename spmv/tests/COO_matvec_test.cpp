#include <SpMV.hpp>
#include <vector>
#include "unit_test_framework.hpp"

TEST_CASE(case_float){
    try
    {
        SpMV::SparseMatrix<float>* test_matrix = new SpMV::SparseMatrix_COO<float>(3,3);
        test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(0),static_cast<float>(1.0));
	test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(2),static_cast<float>(2.0));
	test_matrix->setCoefficient(static_cast<size_t>(1),static_cast<size_t>(1),static_cast<float>(3.0));
	test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(0),static_cast<float>(4.0));
	test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(2),static_cast<float>(5.0));

        test_matrix->assembleStorage();

	std::vector<float> *vecin= new std::vector<float>{1.0,2.0,3.0};
	std::vector<float> *result= new std::vector<float>{7.0,6.0,23.0};
	std::vector<float> *vecout;
        test_matrix->matvec(vecin,vecout);
        
	ASSERT(vecout.size()==test_matrix->getNumRows());

	for (size_t i=0; i<test_matrix->getNumRows(); i++)
	{
		ASSERT_NEAR(vecout[i],result[i],static_cast<float>(1e-3));
	}
    }catch(const std::exception&){}  
}

TEST_CASE(case_double){
    try
    {
        SpMV::SparseMatrix<double>* test_matrix = new SpMV::SparseMatrix_COO<double>(3,3);
        test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(0),static_cast<double>(1.0));
        test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(2),static_cast<double>(2.0));
        test_matrix->setCoefficient(static_cast<size_t>(1),static_cast<size_t>(1),static_cast<double>(3.0));
        test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(0),static_cast<double>(4.0));
        test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(2),static_cast<double>(5.0));

        test_matrix->assembleStorage();

        std::vector<double> *vecin= new std::vector<double>{1.0,2.0,3.0};
        std::vector<double> *result= new std::vector<double>{7.0,6.0,23.0};
        std::vector<double> *vecout;
        test_matrix->matvec(vecin,vecout);

        ASSERT(vecout.size()==test_matrix->getNumRows());

        for (size_t i=0; i<test_matrix->getNumRows(); i++)
        {
                ASSERT_NEAR(vecout[i],result[i],static_cast<double>(1e-3));
        }
    }catch(const std::exception&){}
}

TEST_SUITE(matvec_suite){
    TEST(case_float);
    TEST(case_double);
}

auto
main() -> int
{
    RUN_SUITE(matvec_suite);
    return 0; 
}
