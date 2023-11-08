#ifndef _SPMV570_
#define _SPMV570_

#include <cstddef>
#include <cassert>
#include <map>
#include <utility>


namespace SpMV
{
    // Enumerations for matrix state to support Builder Pattern
    enum MatrixState  { undefined, initialized, building, assembled };
    enum MatrixFormat { UDF, DEN, COO, CSR, ELL, JDS };

    template <class fp_type>
    class SparseMatrix
    {
    protected: 
        size_t _nrows = 0;
        size_t _ncols = 0;
        size_t _nnz   = 0;

              MatrixState  _state = undefined;
        const MatrixFormat _fmt;

        std::map<std::pair<size_t, size_t>, fp_type> _buildCoeff;

        virtual void _disassembleStorage() =0;
        virtual void _viewAssembled() =0;

    public:
        SparseMatrix(const size_t nrows, const size_t ncols, const MatrixFormat);
        virtual ~SparseMatrix();

        inline size_t       getNumRows()     const { return _nrows; };
        inline size_t       getNumCols()     const { return _ncols; };
        inline size_t       getNumNonZeros() const { return _nnz;   };
        inline MatrixState  getState()       const { return _state; };
        inline MatrixFormat getFormat()      const { return _fmt;   };

                   void setCoefficient(const size_t row, const size_t col, const fp_type aij);
        virtual fp_type getCoefficient(const size_t row, const size_t col);
        virtual    void view();
        virtual    void assembleStorage() =0;
        virtual    void matVec(const size_t nx, const fp_type* x, const size_t ny, fp_type* y) =0;
    };

}

#endif
