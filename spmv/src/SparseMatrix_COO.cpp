#include "SparseMatrix_COO.hpp"

#include <iostream>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_COO<fp_type>::SparseMatrix_COO(const int nrows, const int ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols, COO) {}


    template <class fp_type>
    fp_type SparseMatrix_COO<fp_type>::getCoefficient(const size_t row, const size_t col)
    {
        return 1.0;
    }

    template <class fp_type>
    void SparseMatrix_COO<fp_type>::view()
    {

    }

    template <class fp_type>
    void SparseMatrix_COO<fp_type>::assembleStorage()
    {

    }

    template <class fp_type>
    void SparseMatrix_COO<fp_type>::_disassembleStorage()
    {

    }

    template <class fp_type>
    void SparseMatrix_COO<fp_type>::matVec(const size_t nx, const fp_type* x, const size_t ny, fp_type* y)
    {

    }


    template class SparseMatrix_COO<float>;
    template class SparseMatrix_COO<double>;
}
