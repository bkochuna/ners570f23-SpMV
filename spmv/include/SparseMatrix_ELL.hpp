#pragma once

#include "SparseMatrix.hpp"
#include <string>

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_ELL : public SparseMatrix<fp_type>
    {
    private:
        // size_t *I    = nullptr;
        // size_t *J    = nullptr;
        size_t *colIdx = nullptr;
        fp_type *val = nullptr;
        size_t _nrowsmax;
        //string format = "ELL";

    public:
        SparseMatrix_ELL(const int nrows, const int ncols);
        void setCoefficient(const size_t row, const size_t col, const fp_type aij);
        void assembleStorage() {};
        //void getCoef(size_t i,size_t j);
        //string getFormat();
    };
}