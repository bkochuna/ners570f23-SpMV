#include "SparseMatrix_JDS.hpp"

#include <iostream>

namespace SpMV
{

    template <class fp_type>
    SparseMatrix_JDS<fp_type>::SparseMatrix_JDS() :
        SparseMatrix<fp_type>::SparseMatrix(0, 0)
    {
        std::cout << "Hello from SparseMatrix_JDS default Constructor!" << std::endl;
    }



    template <class fp_type>
    SparseMatrix_JDS<fp_type>::SparseMatrix_JDS(const int nrows, const int ncols) :
        SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_JDS Constructor!" << std::endl;
        // get _nrowsmax
        size_t _nrowsmax = 0;
        for (size_t i = 0; i < nrows; i++) {
            size_t _temp = 0;
            for (size_t j = 0; j < ncols; i++) {
                 if (this->_buildCoeff[std::make_pair(i,j)] != 0) {
                    _temp = _temp + 1;
                 }
            }
            if (_nrowsmax < _temp) {
                _nrowsmax = _temp;
            }
        }
        this->colIdx = new size_t[this->_nnz];
        this->val = new fp_type[this->_nnz];
        this->iterPtr = new size_t[this->_nrowsmax + 1];
        this->row = new size_t[this->_nrows];
    }


    template <class fp_type>
    SparseMatrix<fp_type>::~SparseMatrix()
    {
        std::cout << "Goodbye from SparseMatrix Destructor!" << std::endl;
        delete colIdx;
        delete val;
        delete iterPtr;
        delete row;
    }



    template class SparseMatrix_JDS<float>;
    template class SparseMatrix_JDS<double>;
}