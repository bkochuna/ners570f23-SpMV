#include "SparseMatrix_COO.hpp"

#include <iostream>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_COO<fp_type>::SparseMatrix_COO(const int nrows, const int ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_COO Constructor!" << std::endl;
    }

    template <class fp_type>
    void SparseMatrix_COO<fp_type>::matvec(fp_type* vecin, fp_type* vecout)
    {
        // Matrix-vector multiply method for COO. vecin should have size ncol, vecout should have size nrow 
        for (size_t i = 0; i < this->_nrows; i++)
            vecout[i] = 0.0;
        for (size_t i = 0; i < this->_nnz; i++)
            vecout[I[i]] += val[i] * vecin[J[i]];
    }

    template class SparseMatrix_COO<float>;
    template class SparseMatrix_COO<double>;
}