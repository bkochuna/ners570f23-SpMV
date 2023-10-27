#include "SparseMatrix_ELL.hpp"
#include<fstream>
#include<iostream>
#include<stdexcept>
#include <algorithm>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_ELL<fp_type>::SparseMatrix_ELL(const int nrows, const int ncols) :
         SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_ELL Constructor!" << std::endl;
        this->colIdx = new size_t[this->_nrowsmax*this->_nrows];
        this->val = new fp_type[this->_nrowsmax*this->_nrows];
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

        if(this->_state!=assembled){
            throw std::runtime_error("Matrix must be assembled before its values are accessed");
        }
        if(row>this->_nrows||col>this->_ncols){
            throw std::runtime_error("Indices specified are out of bounds");
        }

        fp_type output = 0;
        for (size_t i=0;i<_nrowsmax;i++){
            if(colIdx[this->_nrows*i+row]==col){
                output = val[this->_nrows*i+row];
            }
        }
        return output;
    }

    template <class fp_type>
    size_t SparseMatrix_ELL<fp_type>::getLongestRow(){
        // need ot iterate through map entries but unsure how.
        // https://stackoverflow.com/questions/26281979/c-loop-through-map
        // https://cplusplus.com/reference/utility/pair/pair/

        size_t * rowLengths = new size_t(this->_nrows);
        for (auto const &ent1:this->_buildCoeff){
            size_t rowidx= ent1.first.first; //should be the rowidx for jth entry
            rowLengths[rowidx]++;
        }
        std::sort(rowLengths,rowLengths+this->_nrows);
        return rowLengths[this->_nrows-1];
    }

    // template <class fp_type>
    // void SparseMatrix_ELL<fp_type>::ELL_view() {
    //         std::ofstream outputFile("ELL.matout");
    //         if (!outputFile.is_open()){
    //             std::cerr << "Unable to open the file for writing." << std::endl;
    //             return;
    //         }

    //         for (size_t i = 0; i < this->_nrowsmax*this->_nrows; i++){
    //              if (val[i] != 0){
    //                  outputFile << colIdx[i] << "," << val[i] << " ";    
    //                  }
    //             outputFile << std::endl;
    //         }
    //     outputFile.close();
    // }

    template class SparseMatrix_ELL<float>;
    template class SparseMatrix_ELL<double>;
}