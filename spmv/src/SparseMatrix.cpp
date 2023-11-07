#include "SparseMatrix.hpp"

#include <iostream>

namespace SpMV
{
    
    template <class fp_type>
    SparseMatrix<fp_type>::SparseMatrix(const int nrows, const int ncols, const MatrixFormat fmt) :
        _nrows(nrows), _ncols(ncols), _fmt(fmt)
    {
        assert(this->_state == undefined);
        std::cout << "Hello from SparseMatrix Constructor!" << std::endl;
        std::cout << "Size is (nrows,ncols) = (" 
            << this->_nrows << "," << this->_ncols << ")" << std::endl;
        this->_state = initialized;
        assert(this->_state == initialized);
    }

    template <class fp_type>
    SparseMatrix<fp_type>::~SparseMatrix()
    {
        std::cout << "Hello from SparseMatrix Destructor!" << std::endl;
    }

    template <class fp_type>
    void SparseMatrix<fp_type>::setCoefficient(const size_t row, const size_t col, const fp_type aij)
    {
        assert(this->_state != undefined);
        assert(col < this->_ncols);
        assert(row < this->_nrows);

        this->_state = building;

        //Store value
        this->_buildCoeff[std::make_pair(row,col)] = aij;
        this->_nnz = this->_buildCoeff.size();

        std::cout << "i,j,aij    " << row << "," << col << "," << aij << std::endl;

        assert(this->_state == building);
    }

    template <class fp_type>
    fp_type SparseMatrix<fp_type>::getCoefficient(const size_t row, const size_t col)
    {
        return 0.0;
    }

    template <class fp_type>
    void SparseMatrix<fp_type>::view()
    {
        std::cout << "View!" << std::endl;
    }

    template class SparseMatrix<float>;
    template class SparseMatrix<double>;
}
