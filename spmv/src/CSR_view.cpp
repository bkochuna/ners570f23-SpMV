#include "SparseMatrix_CSR.hpp"
#include <iostream>
#include <fstream> 

namespace SpMV
{

template <class fp_type>
void SparseMatrix_CSR<fp_type>::CSR_view(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return;
    }
    
    outputFile << "[ ";
    for (int i = 0; i < this->_nrows; i++) {
        for (int j = 0; j < this->_ncols; j++) {
            int columnIdx = -1;
            for (size_t k = this->rowPtrs[i]; k < this->rowPtrs[i + 1]; k++) {
                if (this->colIdx[k] == j) {
                    columnIdx = k;
                    break;
                }
            }
            if (columnIdx != -1) {
                outputFile << this->value[columnIdx] << " ";
            } else {
                outputFile << "0 ";
            }
        }
        outputFile << std::endl;
    }
    outputFile << "]";

    outputFile.close();
}


}