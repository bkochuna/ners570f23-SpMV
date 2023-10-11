#ifndef _SPMV570_
#define _SPMV570_

#include <cstddef>
#include <cassert>

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

}

#endif