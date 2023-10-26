#ifndef __SPMV570_DEN__
#define __SPMV570_DEN__

#pragma once

#include "SparseMatrix.hpp"
#include <string>

namespace SpMV
{
    template <class fp_type>
    class SparseMatrix_DEN : public SparseMatrix<fp_type>
    {
    private:
        size_t *I    = nullptr;
        size_t *J    = nullptr;
        fp_type *A = nullptr;//nrows*ncols array storing the values of the dense matrix
	//int nrows;
	//std::map<std::pair<size_t, size_t>, fp_type> _buildCoeff;
	//string format = "DEN";

    public:
        //default constructor
        SparseMatrix_DEN();
        
        // overloaded constructor
        SparseMatrix_DEN(const int nrows, const int ncols);
        void assembleStorage();
	void disassembleStorage();
	void Matmul() {};
	// DEN Accessor Functions
	
	[[gnu::pure]] size_t getNumRows_DEN(); //Returns the number of rows
	[[gnu::pure]] size_t getNumCols_DEN(); //Returns the number of columns
	void setCoefficient_DEN(const size_t row, const size_t col, const fp_type aij); //Sets the coefficient at row and col to aij
        fp_type getCoef(const size_t i, const size_t j); //Returns the coefficient value at row and column indexes i and j
	std::string getFormat(); //Returns the format (DEN) of the matrix
    void DEN_view();
	// End DEN Accessor Functions
    };
}


#endif
