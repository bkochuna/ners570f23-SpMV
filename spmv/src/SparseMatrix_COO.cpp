#include "SparseMatrix_COO.hpp"

#include <iostream>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_COO<fp_type>::SparseMatrix_COO() : 
	 SparseMatrix<fp_type>::SparseMatrix(0,0)
    {
         std::cout << "From the default SparseMatrix_COO constructor!" << std::endl;
    }
    
    template <class fp_type>
    SparseMatrix_COO<fp_type>::SparseMatrix_COO(const int nrows, const int ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_COO Constructor!" << std::endl;
        //this->_nrows = nrows;
        //this->_ncols = ncols;    -> nrows and ncols are defined by the parent class constructors
        _format = "COO";
        //I = new size_t[this->_nnz];
        //J = new size_t[this->_nnz];
        //val = new fp_type[this->_nnz];   -> These must be set by the assembleStorage method
    }
    
    template <class fp_type>
    SparseMatrix_COO<fp_type>::~SparseMatrix_COO()
    {
	 delete(I);
	 delete(J);
	 delete(val);
	 I=nullptr;
	 J=nullptr;
	 val=nullptr;
    }
    template <class fp_type>
    void SparseMatrix_COO<fp_type>::matvec(fp_type* vecin, fp_type* vecout)
    {
        // Matrix-vector multiply method for COO. vecin should have size ncol, vecout should have size nrow 
        for (size_t i = 0; i < this->_nrows; i++)
            vecout[i] = 0.0;
        for (size_t i = 0; i < this->_nnz; i++)
            vecout[I[i]] += val[i] * vecin[J[i]];
    }

    template <class fp_type>
    std::string SparseMatrix_COO<fp_type>::getFormat()
    {
        return _format;
    }

    template <class fp_type>
    size_t SparseMatrix_COO<fp_type>::getNumRows()
    {
        return SparseMatrix<fp_type>::getNumRows();
    }
        
    template <class fp_type>
    size_t SparseMatrix_COO<fp_type>::getNumCols()
    {
        return SparseMatrix<fp_type>::getNumCols();
    }
        
    template <class fp_type>
    size_t SparseMatrix_COO<fp_type>::getNumNonZeros()
    {
        return SparseMatrix<fp_type>::getNumNonZeros();
    }
        
    template <class fp_type>
    MatrixState SparseMatrix_COO<fp_type>::getState()
    {
        return SparseMatrix<fp_type>::getState();
    }

    template <class fp_type>
    fp_type SparseMatrix_COO<fp_type>::getCoefficient(const size_t row, const size_t col)
    {
        if(this->_state!=assembled){
            throw std::runtime_error("Matrix must be assembled before its values are accessed");
        }
        if (col >= this->_ncols || row >= this->_nrows)
        {
            std::cout << "Specified matrix indices are not within the bounds of the matrix" << std::endl;	
            exit(1);
        }

        fp_type value = 0;

        for (size_t i = 0; i < this->_nnz; i++)
            if(I[i] == row && J[i] == col)
                value = val[i];
        
        return value;
    }

    template <class fp_type>
    fp_type SparseMatrix_COO<fp_type>::operator()(const size_t row, const size_t col)
    {
        if(this->_state!=assembled){
            throw std::runtime_error("Matrix must be assembled before its values are accessed");
        }
        if (col >= this->_ncols || row >= this->_nrows)
        {
            std::cout << "Specified matrix indices are not within the bounds of the matrix" << std::endl;	
            exit(1);
        }

        return this->_buildCoeff[{row , col}];
    }

    template <class fp_type>
    void SparseMatrix_COO<fp_type>::setCoefficient(const size_t row, const size_t col, const fp_type aij)
    {
        SparseMatrix<fp_type>::setCoefficient(row,col,aij);
    }

    template class SparseMatrix_COO<float>;
    template class SparseMatrix_COO<double>;
}
