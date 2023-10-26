#ifndef __SPMV570_CSR__
#define __SPMV570_CSR__

#pragma once

#include "SparseMatrix.hpp"
#include <string>
#include <vector>

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_CSR : public SparseMatrix<fp_type>
    {
    private:
        // Default Constructor
        size_t *rowPtrs   = nullptr;
        size_t *colIdx    = nullptr;
        fp_type *value    = nullptr;
        // string format = "CSR";

    public:
        // Constructor that takes arguments
        SparseMatrix_CSR(const int nrows, const int ncols);
        std::string getFormat();
        void setCoefficient(const size_t row, const size_t col, const fp_type aij);
        void CSR_view(const std::string& filename);
        void assembleStorage() {};
        void disassembleStorage() {};
        void getCoefficient(size_t i, size_t j, fp_type* Val);
	     void matvec(fp_type* vecin, fp_type* vecout);
    };
}

#endif
