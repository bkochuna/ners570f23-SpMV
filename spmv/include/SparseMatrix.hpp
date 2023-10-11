#ifndef _SPMV570_
#define _SPMV570_

#include <cstddef>
#include <cassert>
#include <iostream>

namespace SpMV
{
    // Enumerations for matrix state to support Builder Pattern
    enum MatrixState { undefined, initialized, building, assembled };

    template <class fp_type>
    class SparseMatrix
    {
    protected: 
        size_t _ncols = 0;
        size_t _nrows = 0;
        size_t _nnz   = 0;

        MatrixState _state = undefined;

    public:
        SparseMatrix(const int nrows, const int ncols);
       ~SparseMatrix();

        void setCoefficient(const size_t row, const size_t col, const fp_type aij);

        inline size_t      getNumRows()     const { return _nrows; };
        inline size_t      getNumCols()     const { return _ncols; };
        inline size_t      getNumNonZeros() const { return _nnz;   };
        inline MatrixState getState()       const { return _state; };
    };

    template <class fp_type>
    SparseMatrix<fp_type>::SparseMatrix(const int nrows, const int ncols) :
        _nrows(nrows), _ncols(ncols)
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

        this->_state = building;

        //Store value
        //Increment nnz
        std::cout << "i,j,aij" << row << "," << col << "," << aij << std::endl;

        assert(this->_state == building);
    }
}

#endif