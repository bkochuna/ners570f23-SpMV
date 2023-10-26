#include <SpMV.hpp>
#include <vector>
#include "unit_test_framework.hpp"

TEST_CASE(case_float){
    try
    {
        SpMV::SparseMatrix<float> *test_matrix = new SpMV::SparseMatrix_COO<float>(3,3);
        test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(0),static_cast<float>(1));
	test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(2),static_cast<float>(2));
	test_matrix->setCoefficient(static_cast<size_t>(1),static_cast<size_t>(1),static_cast<float>(3));
	test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(0),static_cast<float>(4));
	test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(2),static_cast<float>(5));

        test_matrix->assembleStorage();
 	
	float* vecin = new float[3];
	float* vecout = new float[3];

	// Initialize the elements of vecin, for example to 1.0. vecout is already initialized in matvec.
	for (int i = 0; i < 3; i++)
	{
	    vecin[i] = static_cast<float>(i)+1.0f;
	}
        // Initialize
	float* result = new float[3];

	// Assign values
	result[0] = 7.0f;
	result[1] = 6.0f;
	result[2] = 23.0f;
        test_matrix->matvec(vecin,vecout);

	for (size_t i=0; i<test_matrix->getNumRows(); i++)
	{
		ASSERT_NEAR(vecout[i],result[i],static_cast<float>(1e-3));
	}
    }catch(const std::exception&){}  
}

TEST_CASE(case_double){
    try
    {
        SpMV::SparseMatrix<double> *test_matrix = new SpMV::SparseMatrix_COO<double>(3,3);
        test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(0),static_cast<double>(1));
        test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(2),static_cast<double>(2));
        test_matrix->setCoefficient(static_cast<size_t>(1),static_cast<size_t>(1),static_cast<double>(3));
        test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(0),static_cast<double>(4));
        test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(2),static_cast<double>(5));

        test_matrix->assembleStorage();
	
	double* vecin = new double[3];
        double* vecout = new double[3];

        // Initialize the elements of vecin, for example to 1.0. vecout is already initialized in matvec.
        for (int i = 0; i < 3; i++)
        {
            vecin[i] = static_cast<double>(i)+1.0;
        }
        // Initialize
        double* result = new double[3];

        // Assign values
        result[0] = 7.0;
        result[1] = 6.0;
        result[2] = 23.0;
        test_matrix->matvec(vecin,vecout);

        for (size_t i=0; i<test_matrix->getNumRows(); i++)
        {
                ASSERT_NEAR(vecout[i],result[i],1e-3);
	}
    }catch(const std::exception&){}
}

TEST_SUITE(matvec_suite){
    TEST(case_float);
    //TEST(case_double);
}

auto
main() -> int
{
    RUN_SUITE(matvec_suite);
    return 0; 
}
