#ifndef __SPMV570_COO__
#define __SPMV570_COO__

#include "SparseMatrix.hpp"

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_COO : public SparseMatrix<fp_type>
    {
    private:
        size_t *I    = nullptr;
        size_t *J    = nullptr;
        fp_type *val = nullptr;

    public:
        SparseMatrix_COO(const int nrows, const int ncols);
        void assembleStorage() {};
    };
}

#endif