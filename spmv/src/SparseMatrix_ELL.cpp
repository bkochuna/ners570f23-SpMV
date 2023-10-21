#include "SparseMatrix_ELL.hpp"

#include<iostream>
#include<stdexcept>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_ELL<fp_type>::SparseMatrix_ELL(const int nrows, const int ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_ELL Constructor!" << std::endl;
        this->colIdx = new size_t[this->_nrowsmax*this->_nrows];
        this->val = new size_t[this->_nrowsmax*this->_nrows];
        for (size_t i = 0; i < this->_nrowsmax*this->_nrows; i++)
        {
            colIdx[i]=-1; // -1 corresponds to the zero entries
            val[i]=-1;
        }  
        
    }

    template <class fp_type>
    fp_type SparseMatrix_ELL<fp_type>::getCoefficient(const size_t row,const size_t col){
        // This function gets a matrix coefficient value given the row and 
        // column indices. It does this by accessing the sparse storage format.
        // Thus, the sparse storage format must be built in order for this 
        // method to function.

        if(_state!=assembled){
            throw std::exception("Matrix must be assembled before its values are accessed");
        }

        fp_type output = 0;
        for (size_t i=0;i<_nrowsmax;i++){
            if(colIdx[_nrows*i+row]==col){
                output = val[_nrows*i+row];
            }
        }
        return output;
    }

    template <class fp_type>
    size_t SparseMatrix_ELL<fp_type>::getLongestRow(){
        size_t count = 0;
        size_t max_count = 0;

        // need ot iterate through map entries but unsure how.
        // https://stackoverflow.com/questions/26281979/c-loop-through-map
        // https://cplusplus.com/reference/utility/pair/pair/
        for (int i=0; i<_nrows;i++){
            _buildCoeff::iterator j
            for (j=symbolTable.begin(); j!=symbolTable.end(); j++){
                size_t rowidx= j->first->first; //should be the rowidx for jth entry
                if (i==rowidx){
                    count++;
                }
            }
            if (max_count<count){
                max_count = count;
            }
            count = 0;
    }
    }

    template class SparseMatrix_ELL<float>;
    template class SparseMatrix_ELL<double>;
}