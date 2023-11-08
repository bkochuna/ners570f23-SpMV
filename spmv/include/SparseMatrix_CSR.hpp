#ifndef __SPMV570_CSR__
#define __SPMV570_CSR__

#include "SparseMatrix.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

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
           void _viewAssembled() {};
        fp_type _getAssembledCoeff(const size_t row, const size_t col) {return static_cast<fp_type>(0.0);};

    public:
        SparseMatrix_CSR(const size_t nrows, const size_t ncols);
        void assembleStorage() {};
        void matVec(const size_t nx, const fp_type* x, const size_t ny, fp_type* y) {};
    };
}

#pragma GCC diagnostic pop

#endif
