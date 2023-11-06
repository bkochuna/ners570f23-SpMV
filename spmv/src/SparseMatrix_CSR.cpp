#include "SparseMatrix_CSR.hpp"

#include <iostream>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_CSR<fp_type>::SparseMatrix_CSR(const int nrows, const int ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols, CSR)
    {
        std::cout << "Hello from SparseMatrix_CSR Constructor!" << std::endl;
    }

    template class SparseMatrix_CSR<float>;
    template class SparseMatrix_CSR<double>;
}
