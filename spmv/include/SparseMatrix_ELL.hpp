#pragma once

#include "SparseMatrix.hpp"
#include <string>

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_ELL : public SparseMatrix<fp_type>
    {
    private:
        size_t *I    = nullptr;
        size_t *J    = nullptr;
        fp_type *val = nullptr;
        string format = nullptr;

    public:
        SparseMatrix_COO(const int nrows, const int ncols);
        void assembleStorage() {};
        void getCoef(size_t i,size_t j);
        string getFormat();
    };
}