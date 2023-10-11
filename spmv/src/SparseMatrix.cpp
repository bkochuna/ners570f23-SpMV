#include "SparseMatrix.hpp"

#include <iostream>

namespace SpMV
{
    
    template <class fp_type>
    SparseMatrix<fp_type>::SparseMatrix(const int nrows, const int ncols) :
        _nrows(nrows), _ncols(ncols)
    {
        assert(this->_state == undefined);
        std::cout << "Hello from SparseMatrix Constructor!" << std::endl;
        std::cout << "Size is (nrows,ncols) = (" 
            << this->_nrows << "," << this->_ncols << ")" << std::endl;
        this->_state = initialized;
        assert(this->_state == initialized);
    }

    template <class fp_type>
    SparseMatrix<fp_type>::~SparseMatrix()
    {
        std::cout << "Hello from SparseMatrix Destructor!" << std::endl;
    }

    template <class fp_type>
    void SparseMatrix<fp_type>::setCoefficient(const size_t row, const size_t col, const fp_type aij)
    {
        assert(this->_state != undefined);

        this->_state = building;

        //Store value
        //Increment nnz
        std::cout << "i,j,aij    " << row << "," << col << "," << aij << std::endl;

        assert(this->_state == building);
    }

    template class SparseMatrix<float>;
    template class SparseMatrix<double>;
}