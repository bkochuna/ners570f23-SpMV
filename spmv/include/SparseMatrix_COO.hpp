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
        void matvec(fp_type* vecin, fp_type* vecout);

        // For destruction unit test
        // size_t*  getPointerI()   const {return I;};
        // size_t*  getPointerJ()   const {return J;};
        // fp_type* getPointerVal() const {return val;};
    };
}

#endif