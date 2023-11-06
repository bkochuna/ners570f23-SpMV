#ifndef __SPMV570_CSR__
#define __SPMV570_CSR__

#include "SparseMatrix.hpp"

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_CSR : public SparseMatrix<fp_type>
    {
    private:
        size_t  *_ia  = nullptr;
        size_t  *_ja  = nullptr;
        fp_type *_aa  = nullptr;

        void _disassembleStorage() {};

    public:
        SparseMatrix_CSR(const int nrows, const int ncols);
        void assembleStorage() {};
    };
}

#endif
