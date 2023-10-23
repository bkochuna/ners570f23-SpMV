# ners570f23-SpMV

## How to use this library for sparce matrix-vector multiplication
1. instantiate a the preferred storage method's class with the required arguments (number of rows and columns)

        SpMV::SparseMatrix<float>* ptr_A = new SpMV::SparseMatrix_ELL<float>(5,5);

2. read in the values of the array using the setCoefficients method (`rowIdx,colIdx,val` can be defined however you like)

        for (size_t i=0;i<nnz;i++){
            ptr_A::setCoefficients(rowIdx[i],colIdx[i],val[i])
        }

3. Assemble the data into the proper storage format

        ptr_A::assembleStorge();

4. Use the `matvec()` method to compute matrix-vector mutliplication.
        std::vector input={};
        std::vector output = ptr_A::matvec(input);

## Additional Features
- the `setCoefficients(i,j,a)` method can be used after the matrix has been assembled, but it will have to be re-assembled.

- You can view the type of storage method or the value of the coefficients at any time
    - `getFormat()` gives you the storage format
    - `getCoefficients(i,j)` gives you the coefficient at row i and column j. The storage must be assembled to used this method.

- you can print the matrix with the `view()` method