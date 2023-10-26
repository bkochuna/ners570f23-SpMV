#include <SpMV.hpp>

#include <vector> // std::vector

#include "unit_test_framework.hpp"

// TESTS FOR CONSTRUCTOR
// - Max Herzog (maxzog)

template <typename T>
TEST_CASE(base_assemble) {
  SpMV::SparseMatrix_CSR<T> A = SpMV::SparseMatrix_CSR<T>(4,4);
  ASSERT(A.getState() == 1);
}


template <typename T>
TEST_CASE(set_assemble) {
  SpMV::SparseMatrix_CSR<T> A = SpMV::SparseMatrix_CSR<T>(4,4);
  A.setCoefficient(2, 2, 1.0);
  ASSERT(A.getState() == 2);
}

template <typename T>
TEST_CASE(store_assemble) {
  SpMV::SparseMatrix_CSR<T> A = SpMV::SparseMatrix_CSR<T>(4,4);
  A.setCoefficient(2, 2, 1.0);
  A.assembleStorage();
  ASSERT(A.getState() == 3);
}


template <typename T>
TEST_CASE(dis_assemble) {
  SpMV::SparseMatrix_CSR<T> A = SpMV::SparseMatrix_CSR<T>(4,4);
  A.setCoefficient(2, 2, 1.0);
  A.assembleStorage();
  A.disassembleStorage();
  ASSERT(A.getState() == 2);
}

// test suite for running all the tests
template <typename T>
TEST_SUITE(suite) {
  TEST(base_assemble<T>);
  TEST(set_assemble<T>);
  TEST(store_assemble<T>);
  TEST(dis_assemble<T>);
}


auto
main() -> int
{
  RUN_SUITE(suite<float>);
  RUN_SUITE(suite<double>);
  return 0; 
}
