#include "SparseMatrix_CSR.hpp"

#include <iostream>
#include <fstream>
using namespace std;

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_CSR<fp_type>::SparseMatrix_CSR(const int nrows, const int ncols) : SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_CSR Constructor!" << std::endl;
        this->rowPtrs = new size_t[nrows + 1];
        for (int i = 0; i < nrows + 1; i++)
        {
            this->rowPtrs[i] = 0;
        }

        this->colIdx = new size_t[this->_nnz];
        this->value = new fp_type[this->_nnz];
        this->_nrows = nrows;
        this->_ncols = ncols;
    }

    // Returns string denoting the sparse matrix storage format
    // A string was chosen to be consistent with the header and the
    // implementations on other branches.
    // - Max Herzog (maxzog)
    template <class fp_type>
    std::string SparseMatrix_CSR<fp_type>::getFormat()
    {
        return "CSR";
    }

    template <class fp_type>
    void SparseMatrix_CSR<fp_type>::assembleStorage()
    {
        // If there was a previous allocation, delete it to prevent memory leaks.
        delete[] this->colIdx;
        delete[] this->value;
        delete[] this->rowPtrs;

        // The total number of non-zero elements is the size of _buildCoeff.
        this->_nnz = this->_buildCoeff.size();

        // Allocate memory for CSR format.
        this->rowPtrs = new size_t[this->_nrows + 1];
        this->colIdx = new size_t[this->_nnz];
        this->value = new fp_type[this->_nnz];

        int idx = 0;         // Index for colIdx and value arrays.
        int rptr = 0;        // Index for rowPtrs array.
        size_t last_row = 0; // To keep track of the last accessed row.

        // Loop over each non-zero entry in the matrix.
        for (const auto &entry : this->_buildCoeff)
        {
            // If the current row of entry is greater than the last_row, update rowPtrs.
            while (last_row < entry.first.first)
            {
                this->rowPtrs[rptr++] = idx;
                last_row++;
            }
            // Set the column index and value for the current non-zero element.
            this->colIdx[idx] = entry.first.second;
            this->value[idx] = entry.second;
            idx++;
        }

        // Fill the remaining rowPtrs entries. It should point to the end of the last row.
        while (rptr <= this->_nrows)
        {
            this->rowPtrs[rptr++] = idx;
        }
    }

    template <class fp_type>
    void SparseMatrix_CSR<fp_type>::disassembleStorage()
    {
        // Clear any existing data in the _buildCoeff map.
        this->_buildCoeff.clear();

        // Convert the CSR format back to the dense format.
        for (int i = 0; i < this->_nrows; ++i)
        {
            // Using rowPtrs, get the range of non-zero elements in the row.
            for (size_t j = this->rowPtrs[i]; j < this->rowPtrs[i + 1]; ++j)
            {
                // Add the non-zero values to the _buildCoeff map.
                this->_buildCoeff[{i, this->colIdx[j]}] = this->value[j];
            }
        }

        // Release the memory used for the CSR format.
        delete[] this->colIdx;
        delete[] this->value;
        delete[] this->rowPtrs;

        this->colIdx = nullptr;
        this->value = nullptr;
        this->rowPtrs = nullptr;
    }

    template <class fp_type>
    void SparseMatrix_CSR<fp_type>::setCoefficient(const size_t row, const size_t col, const fp_type aij)
    {

        // Set Coefficient for the SparseMatrix
        SparseMatrix<fp_type>::setCoefficient(row, col, aij);

        // Set the rowPtrs
        for (size_t i = row + 1; i < this->_nrows + 1; i++)
        {
            this->rowPtrs[i] += 1;
            // std::cout << i << " " << this->rowPtrs[i] << std::endl;
        }

        // Move the colIdx in following rows to the next place
        if (this->_nnz == 1)
        {
            // Before: nullptr -> should malloc spaces for colIdx & value pointers
            this->colIdx = static_cast<size_t *>(malloc(this->_nnz * sizeof(size_t)));
            this->value = static_cast<fp_type *>(malloc(this->_nnz * sizeof(fp_type)));
            this->colIdx[0] = col;
            this->value[0] = aij;
        }
        else
        {
            // Set the colIdx & values
            this->colIdx = static_cast<size_t *>(realloc(this->colIdx, this->_nnz * sizeof(size_t)));
            this->value = static_cast<fp_type *>(realloc(this->value, this->_nnz * sizeof(fp_type)));

            for (size_t i = this->_nnz - 1; i >= this->rowPtrs[row + 1]; i--)
            {
                this->colIdx[i] = this->colIdx[i - 1];
                this->value[i] = this->value[i - 1];
            }
            // Move the colIdx in the same row to the next place
            for (size_t i = this->rowPtrs[row + 1] - 1; i >= this->rowPtrs[row]; i--)
            {
                // cout << i << " " << this->rowPtrs[row] << endl;
                if (i == this->rowPtrs[row])
                { // do not need to move, very left case
                    this->colIdx[i] = col;
                    this->value[i] = aij;
                    break;
                }
                if (colIdx[i - 1] > col)
                { // Old: need to move
                    this->colIdx[i] = this->colIdx[i - 1];
                    this->value[i] = this->value[i - 1];
                }
                else
                { // New: add new coefficients
                    this->colIdx[i] = col;
                    this->value[i] = aij;
                    break;
                }
            }
        }

        for (size_t i = 0; i < this->_nnz; i++)
        {
            std::cout << i << " " << this->colIdx[i] << " " << this->value[i] << std::endl;
        }
        std::cout << this->_nnz << std::endl;
    }

    template <class fp_type>
    void SparseMatrix_CSR<fp_type>::matvec(fp_type *vecin, fp_type *vecout)
    {
	// Check that the matrix is assembled:
        if(this->_state != assembled) {
            throw std::runtime_error("Matrix must be assembled before matvec can be performed");
        }

	// Check that the matrix and vector sizes are compatible:
	if((this->_ncols != vecin.size()) || (this->_nrows != vecout.size())) {
		throw std::runtime_error("Matrix and vector sizes are incompatible");
	}

        // Perform the matvec operations:
        for (size_t rownum = 0; rownum < this->_nrows + 1; rownum++)
        {
            for (size_t idx = this->rowPtrs[rownum]; idx < rowPtrs[rownum + 1]; idx++)
            {
                vecout[rownum] = vecout[rownum] + (this->value[idx] * vecin[this->colIdx[idx]]);
            }
        }
    }

    template <class fp_type>
    void SparseMatrix_CSR<fp_type>::CSR_view(const std::string &filename)
    {
        std::ofstream outputFile(filename);
        if (!outputFile.is_open())
        {
            std::cerr << "Error: Could not open the file for writing." << std::endl;
            return;
        }

        // outputFile << "[ ";
        for (size_t i = 0; i < this->_nrows; i++)
        {
            for (size_t j = 0; j < this->_ncols; j++)
            {
                int columnIdx = -1;
                for (size_t k = this->rowPtrs[i]; k < this->rowPtrs[i + 1]; k++)
                {
                    if (this->colIdx[k] == j)
                    {
                        columnIdx = static_cast<int>(k);
                        break;
                    }
                }
                if (columnIdx != -1)
                {
                    outputFile << this->value[columnIdx] << " ";
                }
                else
                {
                    outputFile << "0 ";
                }
            }
            outputFile << std::endl;
        }
        // outputFile << "]";

        outputFile.close();
    }

    // Get coefficient at index (i,j), returns zero if no coefficient is present
    // - Max Herzog (maxzog)
    template <class fp_type>
    void SparseMatrix_CSR<fp_type>::getCoefficient(size_t i, size_t j, fp_type *Val)
    {
        size_t iloc; // row to access
        size_t rowl; // nnz per row

        *Val = 0.0; // set value to zero - only changes if the index (i,j) has a non-zero value
        if (i > this->_nrows)
        {
            std::cerr << "Error: Desired row index is not within matrix bounds." << std::endl;
        }
        if (j > this->_ncols)
        {
            std::cerr << "Error: Desired col index is not within matrix bounds." << std::endl;
        }
        iloc = this->rowPtrs[i];
        rowl = this->rowPtrs[i + 1] - this->rowPtrs[i];

        for (size_t jj = this->colIdx[iloc]; jj < rowl; j++)
        {
            // If the desired row, col has a non-zero change the *Val to that value
            if (jj == j)
            {
                *Val = value[jj];
            }
        }
    }

    template class SparseMatrix_CSR<float>;
    template class SparseMatrix_CSR<double>;
}
