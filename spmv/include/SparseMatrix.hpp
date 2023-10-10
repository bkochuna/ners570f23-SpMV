#ifndef _SPMV570_
#define _SPMV570_

#include <cstddef>
#include <cassert>
#include <iostream>

namespace SpMV
{
    // Enumerations for matrix state to support Builder Pattern
    enum MatrixState { undefined, initialized, building, assembled };

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

       void setCoefficient(const size_t row, const size_t col, const double aij);
    };

    SparseMatrix::SparseMatrix(const int nrows, const int ncols) :
        _nrows(nrows), _ncols(ncols)
    {
        assert(this->_state == undefined);
        std::cout << "Hello from SparseMatrix Constructor!" << std::endl;
        std::cout << "Size is (nrows,ncols) = (" 
            << this->_nrows << "," << this->_ncols << ")" << std::endl;
        this->_state = initialized;
        assert(this->_state == initialized);
    }

    SparseMatrix::~SparseMatrix()
    {
        std::cout << "Hello from SparseMatrix Destructor!" << std::endl;
    }

    void SparseMatrix::setCoefficient(const size_t row, const size_t col, const double aij)
    {
        assert(this->_state != undefined);

        this->_state = building;

        //Store value
        //Increment nnz

        assert(this->_state == building);
    }
}

#endif