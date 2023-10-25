#include "SparseMatrix_DEN.hpp"

#include <iostream>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_DEN<fp_type>::SparseMatrix_DEN() :
         SparseMatrix<fp_type>::SparseMatrix(0, 0)
    {
        std::cout << "Hello from SparseMatrix_DEN DefaultmConstructor!" << std::endl;
    }

    

    template <class fp_type>
    SparseMatrix_DEN<fp_type>::SparseMatrix_DEN(const int nrows, const int ncols,fp_type *A) :
        SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_DEN Overloaded Constructor!" << std::endl;
        this->rowPtrs = new size_t[nrows + 1];
        for (int i = 0; i < nrows + 1; i++)
        {
            this->rowPtrs[i] = 0;
        }

        this->A = new fp_type[this->_nrows*this->_ncols];
        this->nrows = new size_t[this->_nrows];
        this->ncols = new size_t[this->_ncols];
            
        for (int i = 0; i < this->_nrows + 1; i++){
            for (int j = 0; j < this->_ncols + 1; j++){
                this->A[i*this->_ncols+j] = 0;//initialize to zero
            }
        }
    }


    template <class fp_type>
    SparseMatrix<fp_type>::~SparseMatrix()
    {
        std::cout << "Goodbye from SparseMatrix Destructor!" << std::endl;
    }

    template class SparseMatrix_DEN<float>;
}