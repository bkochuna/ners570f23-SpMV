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
	//string format = "DEN";

    public:
        SparseMatrix_DEN(const int nrows, const int ncols);
        //void setCoefficient(const size_t row, const size_t col, const fp_type aij);
        void assembleStorage() {};
	void disassembleStorage() {};
	void Matmul() {};
        //void getCoef(size_t i,size_t j);
        //string getFormat();
    };
}
