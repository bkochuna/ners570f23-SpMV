#include "SparseMatrix_DEN.hpp"

#include <iostream>

namespace SpMV
{
    template <class fp_type>
    SparseMatrix_DEN<fp_type>::SparseMatrix_DEN(const int nrows, const int ncols) : SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {
        std::cout << "Hello from SparseMatrix_DEN Constructor!" << std::endl;
    }

    template <class fp_type>
    static void SparseMatrix_DEN<fp_type>::test_matvec()
    {
        std::cout << "Running DEN matvec unit test..." << std::endl;

        // 2. Benchmark Data from HW 2
        // These should be populated based on the actual data from HW 2
        std::vector<fp_type> inputVector = {...};          // Sample input vector
        std::vector<fp_type> expectedOutputVector = {...}; // Expected output vector

        // Construct the Dense Matrix using SparseMatrix_DEN
        SparseMatrix_DEN<fp_type> matrix(...); // Initialize with appropriate size/values

        std::vector<fp_type> outputVector;
        matrix.matvec(inputVector.data(), outputVector.data());

        // 3. Accuracy Test
        for (size_t i = 0; i < expectedOutputVector.size(); ++i)
        {
            fp_type diff = std::abs(expectedOutputVector[i] - outputVector[i]);
            assert(diff < 1e-5 && "Mismatch in DEN matvec output!"); // Using 1e-5 as precision
        }

        // 4. Invalid Input Handling
        try
        {
            std::vector<fp_type> wrongSizeInputVector = {...}; // Input vector with wrong size
            matrix.matvec(wrongSizeInputVector.data(), outputVector.data());
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            assert(std::string(e.what()) == "Invalid input size" && "Expected invalid input size error!");
        }

        // ... You can add more invalid input scenarios

        std::cout << "All DEN matvec tests passed!" << std::endl;
    }

    template class SparseMatrix_DEN<float>;
}