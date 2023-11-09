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
    fp_type SparseMatrix_COO<fp_type>::_getAssembledCoeff(const size_t row, const size_t col)
    {
        fp_type aij = 0.0;

        for(size_t n=0; n<this->_nnz; n++)
        {
            if(this->_i[n] == row && this->_j[n] == col) {
                aij = this->_a[n];
                break;
            }
        }

        return aij;
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
        assert(this->_state == building);
        assert(this->_nnz > 0);

        // Convert this buildCoeff dictionary to i,j,a

        //allocate storage
        this->_i =  static_cast<size_t *>(malloc(this->_nnz * sizeof(size_t)));
        this->_j =  static_cast<size_t *>(malloc(this->_nnz * sizeof(size_t)));
        this->_a =  static_cast<fp_type *>(malloc(this->_nnz * sizeof(fp_type)));

        //assign values
        size_t n = 0;
        for (auto coeff : this->_buildCoeff) {
            this->_i[n] = coeff.first.first;
            this->_j[n] = coeff.first.second;
            this->_a[n] = coeff.second;
            n += 1;
        }

        // Destroy _buildCoeff
        this->_buildCoeff.clear();

        this->_state = assembled;
        assert(this->_state == assembled);
    }

    template <class fp_type>
    void SparseMatrix_COO<fp_type>::_disassembleStorage()
    {
        assert(this->_state == assembled);


        for(size_t n=0; n<this->_nnz; n++)
            this->_buildCoeff[std::make_pair(this->_i[n],this->_j[n])] = this->_a[n];

        delete this->_i;
        delete this->_j;
        delete this->_a;

        this->_state = building;

        assert(this->_i == nullptr);
        assert(this->_j == nullptr);
        assert(this->_a == nullptr);
        assert(this->_buildCoeff.size() == this->_nnz);
        assert(this->_state == building);
    }

    template <class fp_type>
    void SparseMatrix_COO<fp_type>::matVec(const size_t nx, const fp_type* x, const size_t ny, fp_type* y)
    {
        assert(this->_state == assembled);
        assert(this->_nrows <= ny);
        assert(this->_ncols <= nx);

        size_t i,j;
        fp_type aij;

        for(size_t n=0; n<ny; n++)
            y[n]=static_cast<fp_type>(0.0);

        for(size_t n=0; n<this->_nnz; n++)
        {
            i    = this->_i[n];
            j    = this->_j[n];
            aij  = this->_a[n];

            y[i]+= aij*x[j];
        }
    }


    template class SparseMatrix_COO<float>;
    template class SparseMatrix_COO<double>;
}
