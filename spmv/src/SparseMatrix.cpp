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

        assert(this->_state == building);
    }

    template <class fp_type>
    fp_type SparseMatrix<fp_type>::getCoefficient(const size_t row, const size_t col)
    {
        assert(row < this->_nrows);
        assert(col < this->_ncols);
        
        fp_type aij = 0.0;

        if(this->_state == building) {
            aij = this->_buildCoeff[std::make_pair(row,col)];
        } else if(this->_state == assembled) {
            aij = this->_getAssembledCoeff(row,col);
        }
        
        return aij;
    }

    template <class fp_type>
    void SparseMatrix<fp_type>::view()
    {
        assert(this->_state != initialized);

        std::cout << "% Matrix in matlab format" << std::endl;
        std::cout << "% printed as i,j,val" << std::endl;
        std::cout << "% Nonzeros=" << this->_nnz << std::endl;
        std::cout << "zzz = zeros(" << this->_nnz << ",3);" << std::endl;
        std::cout << "zzz = [" << std::endl;
        if(this->_state == building) {
            for (auto coeff : this->_buildCoeff) {
                std::cout << coeff.first.first  << " " <<
                             coeff.first.second << " " <<
                             coeff.second       << std::endl;
            }
        } else if(this->_state == assembled) {
            this->_viewAssembled();
        }
        std::cout << "];" << std::endl;
    }

    template class SparseMatrix<float>;
    template class SparseMatrix<double>;
}
