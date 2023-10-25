#ifndef __SPMV570_DEN__
#define __SPMV570_DEN__

#pragma once

#include "SparseMatrix.hpp"
#include <string>

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_DEN : public SparseMatrix<fp_type>
    {
    private:
        fp_type *A = nullptr;//nrows*ncols array storing the values of the desne matrix

    public:
        //default constructor
        SparseMatrix_DEN();
        
        // overloaded constructor
        SparseMatrix_DEN(const int nrows, const int ncols, fp_type *A);

        void assembleStorage() {};
	    void disassembleStorage() {};
	    void Matmul() {};

    };
}
