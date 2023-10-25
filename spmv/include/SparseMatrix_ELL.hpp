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
        size_t _nrowsmax; // the method getLongestRow() will return _nrowsmax
        std::string _format = "ELL";
        size_t getLongestRow();

    public:
        SparseMatrix_ELL(const int nrows, const int ncols);
        void assembleStorage() {};
        fp_type getCoefficient(size_t i,size_t j);
        std::string getFormat() const { return _format; };
        void View();
    };
}
