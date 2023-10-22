#include "SparseMatrix_JDS.hpp"

#include <iostream>

namespace SpMV
{

    template <class fp_type>
    SparseMatrix_JDS<fp_type>::SparseMatrix_JDS() :
        SparseMatrix<fp_type>::SparseMatrix(0, 0)
    {
        std::cout << "Hello from SparseMatrix_JDS default Constructor!" << std::endl;
        this->colIdx = new size_t[this->_nnz];
        this->val = new fp_type[this->_nnz];
        this->iterPtr = new size_t[this->_nrowsmax + 1];
        _nrowsmax = 0;
    }



    template <class fp_type>
    SparseMatrix_JDS<fp_type>::SparseMatrix_JDS(const int nrows, const int ncols) :
        SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_JDS Constructor!" << std::endl;
        this->colIdx = new size_t[this->_nnz];
        this->val = new fp_type[this->_nnz];
        this->iterPtr = new size_t[this->_nrowsmax + 1];
        
        // TODO find _nrowsmax
        _nrowsmax = 0;
    }


    template <class fp_type>
    SparseMatrix<fp_type>::~SparseMatrix()
    {
        std::cout << "Goodbye from SparseMatrix Destructor!" << std::endl;
    }



    template <class fp_type>
    void SparseMatrix<fp_type>::setCoefficient(const size_t row, const size_t col, const fp_type aij)
    {
        SparseMatrix<fp_type>::setCoefficient(row,col,aij);

    }

    template class SparseMatrix_JDS<float>;
    template class SparseMatrix_JDS<double>;
}