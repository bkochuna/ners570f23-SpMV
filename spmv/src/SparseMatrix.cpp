#include "SparseMatrix.hpp"

#include <iostream>

namespace SpMV
{
    
    template <class fp_type>
    SparseMatrix<fp_type>::SparseMatrix(const size_t nrows, const size_t ncols, const MatrixFormat fmt) :
        _nrows(nrows), _ncols(ncols), _fmt(fmt), _state(initialized)
    {
        assert(this->_state == initialized);
        assert(this->_ncols == ncols);
        assert(this->_nrows == nrows);
        assert(this->_fmt != UDF);
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
        assert(row < this->_nrows);
        assert(col < this->_ncols);
        
        fp_type aij = 0.0;

        if(this->_state == building)
            aij = this->_buildCoeff[std::make_pair(row,col)];
        
        return aij;
    }

    template <class fp_type>
    void SparseMatrix<fp_type>::view()
    {
        std::cout << "View!" << std::endl;
    }

    template class SparseMatrix<float>;
    template class SparseMatrix<double>;
}
