#include "SparseMatrix_CSR.hpp"

#include <iostream>
using namespace std;

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_CSR<fp_type>::SparseMatrix_CSR(const int nrows, const int ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_CSR Constructor!" << std::endl;
        this->rowPtrs = new size_t[nrows+1];
        for (int i = 0; i < nrows+1; i++){
            this->rowPtrs[i] = 0;
        }
        this->colIdx = new size_t[this->_nnz];
        this->value = new fp_type[this->_nnz];
    }

    template <class fp_type>
    void SparseMatrix_CSR<fp_type>::setCoefficient(const size_t row, const size_t col, const fp_type aij){
        
        // Set Coefficient for the SparseMatrix
        SparseMatrix<fp_type>::setCoefficient(row, col, aij);
        
        // Set the rowPtrs 
        for (size_t i = row+1; i < this->_nrows+1; i++){
            this->rowPtrs[i] += 1;
            // std::cout << i << " " << this->rowPtrs[i] << std::endl;
        }

        // Move the colIdx in following rows to the next place
        if (this->_nnz == 1){
            // Before: nullptr -> should malloc spaces for colIdx & value pointers
            this->colIdx = static_cast<size_t*>(malloc(this->_nnz * sizeof(size_t)));
            this->value = static_cast<fp_type*>(malloc(this->_nnz * sizeof(fp_type)));
            this->colIdx[0] = col;
            this->value[0] = aij;
        } else {
            // Set the colIdx & values
            this->colIdx = static_cast<size_t*>(realloc(this->colIdx, this->_nnz * sizeof(size_t)));
            this->value = static_cast<fp_type*>(realloc(this->value, this->_nnz * sizeof(fp_type)));

            for (size_t i = this->_nnz-1; i >= this->rowPtrs[row+1]; i--){
                this->colIdx[i] = this->colIdx[i-1]; 
                this->value[i] = this->value[i-1]; 
            }
            // Move the colIdx in the same row to the next place
            for (size_t i = this->rowPtrs[row+1]-1; i >= this->rowPtrs[row]; i--){
                // cout << i << " " << this->rowPtrs[row] << endl;
                if (i == this->rowPtrs[row]){ // do not need to move, very left case
                    this->colIdx[i] = col;
                    this->value[i] = aij;
                    break;
                }
                if (colIdx[i-1] > col){ // Old: need to move
                    this->colIdx[i] = this->colIdx[i-1]; 
                    this->value[i] = this->value[i-1]; 
                } else { // New: add new coefficients
                    this->colIdx[i] = col;
                    this->value[i] = aij;
                    break;
                } 
            }
        }

        for (size_t i = 0; i < this->_nnz; i++){
            std::cout << i << " " << this->colIdx[i] << " " << this->value[i] << std::endl;
        }
        std::cout << this->_nnz << std::endl;
    }

    template <class fp_type>
    void SparseMatrix_CSR<fp_type>::matvec(fp_type* vecin, fp_type* vecout){
	//Previous Fortran Implementation:
        //DO rownum = 1, numrows
	////DO idx = rowPtrs(rownum),(rowPtrs(rownum+1)-1)
	//////rhsvec(rownum) = rhsvec(rownum) + values(idx)*lhsvec(colIdx(idx))
        ////END DO
        //END DO
		
	//C++ Implementation:
	for (size_t rownum = 0; rownum < this->nrows+1; rownum++){
		for (size_t idx = this->rowPtrs[rownum]; idx < rowPtrs[rownum+1]; idx++){
			vecout[rownum] = vecout[rownum] + (this->values[idx]*vecin[this->colIdx[idx]]);
		}
	}	
    }
    
    template class SparseMatrix_CSR<float>;
    template class SparseMatrix_CSR<double>;
}
