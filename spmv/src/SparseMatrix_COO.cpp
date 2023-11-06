#include "SparseMatrix_COO.hpp"

#include <iostream>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_COO<fp_type>::SparseMatrix_COO(const int nrows, const int ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols, COO)
    {
        std::cout << "Hello from SparseMatrix_COO Constructor! " << std::endl;
    }

    template class SparseMatrix_COO<float>;
    template class SparseMatrix_COO<double>;
}
