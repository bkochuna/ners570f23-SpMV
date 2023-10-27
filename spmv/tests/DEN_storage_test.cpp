#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() function
#include <SpMV.hpp>

// Testing library required for testing (Always include this last!)
#include "unit_test_framework.hpp"
#include "SparseMatrix.hpp"
#include "SparseMatrix_DEN.hpp"

using namespace SpMV;

template<typename T>
void test_assembleStorage() {
    SparseMatrix_DEN<T> sparseMatrix(3, 3);
    sparseMatrix.setCoefficient_DEN(0, 0, static_cast<T>(1.0));
    sparseMatrix.setCoefficient_DEN(1, 1, static_cast<T>(2.0));
    sparseMatrix.setCoefficient_DEN(2, 2, static_cast<T>(3.0));

    sparseMatrix.assembleStorage();

    REQUIRE(sparseMatrix.getCoef(0, 0) == static_cast<T>(1.0));
    REQUIRE(sparseMatrix.getCoef(1, 1) == static_cast<T>(2.0));
    REQUIRE(sparseMatrix.getCoef(2, 2) == static_cast<T>(3.0));
    REQUIRE(sparseMatrix.getCoef(0, 1) == static_cast<T>(0.0));
}

template<typename T>
void test_disassembleStorage() {
    SparseMatrix_DEN<T> denseMatrix(3, 3);
    denseMatrix.setCoefficient_DEN(0, 0, static_cast<T>(1.0));
    denseMatrix.setCoefficient_DEN(1, 1, static_cast<T>(2.0));
    denseMatrix.setCoefficient_DEN(2, 2, static_cast<T>(3.0));

    denseMatrix.disassembleStorage();
}

TEST_CASE(disassembleSotrageTest) {
    test_assembleStorage<float>();
    test_assembleStorage<double>();
}

TEST_CASE(disassembleSotrageTest) {
    test_disassembleStorage<float>();
    test_disassembleStorage<double>();
}
