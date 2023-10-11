#include "SparseMatrix.hpp"

namespace SpMV
{
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