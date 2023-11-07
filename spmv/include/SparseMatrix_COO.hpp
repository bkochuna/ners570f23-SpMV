#ifndef __SPMV570_COO__
#define __SPMV570_COO__

#include "SparseMatrix.hpp"

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_COO : public SparseMatrix<fp_type>
    {
    private:
        size_t  *_i = nullptr;
        size_t  *_j = nullptr;
        fp_type *_a = nullptr;

        void _disassembleStorage();

    public:
        SparseMatrix_COO(const int nrows, const int ncols);
        SparseMatrix_COO(const int nrows, const int ncols, const size_t nnz, size_t* rows, size_t* cols, fp_type* vals);
        fp_type getCoefficient(const size_t row, const size_t col);
           void view();
           void assembleStorage();
           void matVec(const size_t nx, const fp_type* x, const size_t ny, fp_type* y);
    };
}

#endif
