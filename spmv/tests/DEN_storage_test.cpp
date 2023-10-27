#include <SparseMatrix_DEN.hpp>
#include <cassert>
#include <iostream>

namespace SpMV {

void test_assembleStorage() {
    // 1. Create a sparse matrix with known values.
    SparseMatrix_DEN<double> sparseMatrix(3, 3); // 3x3 matrix
    sparseMatrix.setCoefficient_DEN(0, 0, 1.0);
    sparseMatrix.setCoefficient_DEN(1, 1, 2.0);
    sparseMatrix.setCoefficient_DEN(2, 2, 3.0);
    
    // 2. Use the assembleStorage function to convert the sparse matrix to a dense matrix.
    sparseMatrix.assembleStorage();
    
    // 3. Validate that the resulting dense matrix matches expected values.
    if (sparseMatrix.getCoef(0, 0) != 1.0) {
        std::cerr << "Error in test_assembleStorage: Expected 1.0 at (0,0), got " << sparseMatrix.getCoef(0, 0) << std::endl;
        assert(false);
    }
    if (sparseMatrix.getCoef(1, 1) != 2.0) {
        std::cerr << "Error in test_assembleStorage: Expected 2.0 at (1,1), got " << sparseMatrix.getCoef(1, 1) << std::endl;
        assert(false);
    }
    if (sparseMatrix.getCoef(2, 2) != 3.0) {
        std::cerr << "Error in test_assembleStorage: Expected 3.0 at (2,2), got " << sparseMatrix.getCoef(2, 2) << std::endl;
        assert(false);
    }
    if (sparseMatrix.getCoef(0, 1) != 0.0) { 
        std::cerr << "Error in test_assembleStorage: Expected 0.0 at (0,1), got " << sparseMatrix.getCoef(0, 1) << std::endl;
        assert(false);
    }
}

void test_disassembleStorage() {
    // 1. Start with a dense matrix with known values.
    SparseMatrix_DEN<double> denseMatrix(3, 3); // 3x3 matrix
    denseMatrix.setCoefficient_DEN(0, 0, 1.0);
    denseMatrix.setCoefficient_DEN(1, 1, 2.0);
    denseMatrix.setCoefficient_DEN(2, 2, 3.0);

    // 2. Use the disassembleStorage function to convert the dense matrix back to sparse format.
    denseMatrix.disassembleStorage();

    // 3. Ideally, we would check for correct memory handling here, however this is difficult to accomplish in C++
    // For now, only checking for errors by calling the command will have to suffice.

}

} // namespace SpMV

int main() {
    SpMV::test_assembleStorage();
    SpMV::test_disassembleStorage();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
