#include "SparseMatrix_COO.hpp"

#include <cassert>
#include <iostream>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_COO<fp_type>::SparseMatrix_COO(const size_t nrows, const size_t ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols, COO)
    {
        assert(this->_fmt == COO);
    }

    template <class fp_type>
    SparseMatrix_COO<fp_type>::SparseMatrix_COO(const size_t nrows, const size_t ncols, const size_t nnz, size_t* rows, size_t* cols, fp_type* vals) :
        SparseMatrix<fp_type>::SparseMatrix(nrows, ncols, COO), _i(rows), _j(cols), _a(vals)
    {
        assert(nnz <= ncols*nrows);
        assert(rows != nullptr);
        assert(cols != nullptr);
        assert(vals != nullptr);

#ifndef NDEBUG
        for (size_t i=0; i<nnz; i++)
        {
            assert(rows[i] < nrows);
            assert(cols[i] < ncols);
        }
#endif

        this->_nnz   = nnz;
        this->_state = assembled;

        assert(this->_nnz == nnz);
        assert(this->_state == assembled);
        assert(this->_i == rows);
        assert(this->_j == cols);
        assert(this->_a == vals);
    }


    template <class fp_type>
    SparseMatrix_COO<fp_type>::~SparseMatrix_COO()
    {
        if(this->_state == assembled)
        {
            delete this->_i;
            delete this->_j;
            delete this->_a;
        }

        if(!this->_buildCoeff.empty())
            this->_buildCoeff.clear();

        assert(this->_buildCoeff.empty());
        assert(this->_i == nullptr);
        assert(this->_j == nullptr);
        assert(this->_a == nullptr);
    }

    template <class fp_type>
    fp_type SparseMatrix_COO<fp_type>::getCoefficient(const size_t row, const size_t col)
    {
        if(this->_state == assembled) {
            return 1.0;
        } else {
            return SparseMatrix<fp_type>::getCoefficient(row,col);
        }
    }

    template <class fp_type>
    void SparseMatrix_COO<fp_type>::_viewAssembled()
    {
        for(size_t n=0; n<this->_nnz; n++)
        {
            std::cout << this->_i[n] << " " <<
                         this->_j[n] << " " <<
                         this->_a[n] << std::endl;
        }
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
