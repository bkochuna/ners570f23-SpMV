#include <SpMV.hpp>
#include <SparseMatrix.hpp>
#include <SparseMatrix_COO.hpp>
#include "unit_test_framework.hpp"

template <typename T>
TEST_CASE(testcase){
    try
    {
        SpMV::SparseMatrix<T> *test_matrix = new SpMV::SparseMatrix_COO<T>(3,3);
        test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(0),static_cast<T>(1));
	test_matrix->setCoefficient(static_cast<size_t>(0),static_cast<size_t>(2),static_cast<T>(2));
	test_matrix->setCoefficient(static_cast<size_t>(1),static_cast<size_t>(1),static_cast<T>(3));
	test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(0),static_cast<T>(4));
	test_matrix->setCoefficient(static_cast<size_t>(2),static_cast<size_t>(2),static_cast<T>(5));

        test_matrix->assembleStorage();
 	
	T* vecin = new T[3];
	T* vecout = new T[3];

	// Initialize the elements of vecin
	for (int i = 0; i < 3; i++)
	{
	    vecin[i] = static_cast<T>(i)+static_cast<T>(1);
	}
        // Initialize result
	T* result = new T[3];

	// Assign values
	result[0] = static_cast<T>(7);
	result[1] = static_cast<T>(6);
	result[2] = static_cast<T>(19);
        test_matrix->matvec(vecin,vecout);

	for (size_t i=0; i<test_matrix->getNumRows(); i++)
	{
		ASSERT_NEAR(vecout[i],result[i],static_cast<T>(1e-4));
	}
	delete(test_matrix);
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

        // Initialize the elements of vecin
        for (int i = 0; i < 3; i++)
        {
            vecin[i] = static_cast<double>(i)+1.0;
        }
        // Initialize result
        double* result = new double[3];

        // Assign values
        result[0] = 7.0;
        result[1] = 6.0;
        result[2] = 19.0;
        test_matrix->matvec(vecin,vecout);

        for (size_t i=0; i<test_matrix->getNumRows(); i++)
        {
                ASSERT_NEAR(vecout[i],result[i],1e-3);
	}
        delete(test_matrix);
    }catch(const std::exception&){}
}

auto
main() -> int
{	
    TEST(testcase<float>);
    TEST(testcase<double>);
    return 0; 
}
