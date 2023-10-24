#ifndef __SPMV570_COO__
#define __SPMV570_COO__

#include "SparseMatrix.hpp"
#include <string>

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_COO : public SparseMatrix<fp_type>
    {
    private:
        size_t *I    = nullptr;
        size_t *J    = nullptr;
        fp_type *val = nullptr;

        //std::string _filename;
        std::string _format;

    public:
        SparseMatrix_COO(const int nrows, const int ncols);
        void assembleStorage() {};
        void matvec(fp_type* vecin, fp_type* vecout);

        //getter functions
        //std::string getFilename(); //get underlying file
        fp_type getCoefficient(const size_t row, const size_t col); //read from the file and get the coefficients.
        inline std::string getFormat() const {return _format;}; //get the format of the spmv
        fp_type operator()(const size_t row, const size_t col); //get the value from the _buildcoeff map
        // Don't really need these four getter functions since there are already decleared and defined in the SparseMatrix class
        // size_t      getNumRows();
        // size_t      getNumCols();
        // size_t      getNumNonZeros();
        // MatrixState getState();

        //setter functions
        void setCoefficient(const size_t row, const size_t col, const fp_type aij);
    };
}

#endif