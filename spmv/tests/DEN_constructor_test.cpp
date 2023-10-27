#include <SpMV.hpp>
#include "unit_test_framework.hpp"

template <typename T>

TEST_CASE(size_t N_rows,size_t N_columns,rows_test) //Checks that the number of rows is correctly assigned

{
    SpMV::SparseMatrix_DEN<T> test_constructor=SpMV::SparseMatrix_DEN<T>(N_rows, N_columns);

    ASSERT(test_constructor.getNumRows()==static_cast<size_t>(N_rows));

}

template <typename T>

TEST_CASE(size_t N_rows,size_t N_columns,columns_Test)  //Checks that the number of columns is correctly assigned


    SpMV::SparseMatrix_DEN<T> test_constructor=SpMV::SparseMatrix_DEN<T>(N_rows, N_columns);
    ASSERT(test_constructor.getNumCols()==static_cast<size_t>(N_columns));



template <typename T>

TEST_SUITE(construction) 
{
   TEST(rows_test<32,23,T>);
   TEST(columns_Test<32,23,T>);


auto

main() -> int

    RUN_SUITE(construction<float>);
    RUN_SUITE(construction<double>);

    return 0; 
