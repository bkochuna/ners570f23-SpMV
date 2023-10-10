#pragma once

#include <iostream>

namespace SpMV
{
    class SparseMatrix
    {
    private: 
        /* put our attributes here */
    public:
        SparseMatrix(/* args go here */);
       ~SparseMatrix();
    };

    SparseMatrix::SparseMatrix(/* args go here */)
    {
        std::cout << "Hello from SparseMatrix Constructor!" << std::endl;
    }

    SparseMatrix::~SparseMatrix()
    {
        std::cout << "Hello from SparseMatrix Destructor!" << std::endl;
    }
}
