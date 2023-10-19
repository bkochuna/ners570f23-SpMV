#include "SparseMatrix_ELL.hpp"

#include<iostream>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_ELL<fp_type>::SparseMatrix_ELL(const int nrows, const int ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_ELL Constructor!" << std::endl;
        this->colIdx = new size_t[this->_nrowsmax*this->_nrows];
        this->val = new size_t[this->_nrowsmax*this->_nrows];
        for (size_t i = 0; i < this->_nrowsmax*this->_nrows; i++)
        {
            colIdx[i]=-1; // -1 corresponds to the zero entries
            val[i]=-1;
        }  
        
    }

    template <class fp_type>
    void SparseMatrix_ELL<fp_type>::setCoefficient(const size_t row, const size_t col, const fp_type aij){

        // First call the sefCoeff from SparseMatrix
        SparseMatrix<fp_type>::setCoefficient(row,col,aij);

        // Now assign the entry to colIdx and val
        for (size_t i = 0; i < this->_nrowsmax; i++)
        {
            if(colIdx[this->_nrows*i+row]==-1){
                colIdx[this->_nrows*i+row]=col;
                val[this->_nrows*i+row]=aij;
                break;
            }
        }  
    }   

    template class SparseMatrix_ELL<float>;
    template class SparseMatrix_ELL<double>;
}