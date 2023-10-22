#ifndef __SPMV570_JDS__
#define __SPMV570_JDS__

#pragma once

#include "SparseMatrix.hpp"
#include <string>

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_JDS : public SparseMatrix<fp_type>
    {
    private:
        size_t *colIdx = nullptr;
        fp_type *val = nullptr;
        size_t *iterPtr = nullptr;
        size_t _nrowsmax;

    public:
        // default constructor
        SparseMatrix_JDS();

        // overloaded constructor
        SparseMatrix_JDS(const int nrows, const int ncols);
        
        // SparseMatrix_JDS(const int nrows, const int ncols);
        // void setCoefficient(const size_t row, const size_t col, const fp_type aij);
        void assembleStorage() {};
        void disaaembleStorage() {};
        void Matmul() {};
    };

}


#endif