#include "SparseMatrix.hpp"
#include "SparseMatrix_DEN.hpp"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <map>

namespace SpMV

{    template <class fp_type>

    SparseMatrix_DEN<fp_type>::SparseMatrix_DEN() : SparseMatrix<fp_type>::SparseMatrix(0, 0)

    {

        std::cout << "Hello from SparseMatrix_DEN Default Constructor!" << std::endl;

    }

    template <class fp_type>
    SparseMatrix_DEN<fp_type>::SparseMatrix_DEN(const int nrows, const int ncols) :
        SparseMatrix<fp_type>::SparseMatrix(nrows, ncols)
    {

        std::cout << "Hello from SparseMatrix_DEN Overloaded Constructor!" << std::endl;
     
       this->A = new fp_type[this->_nrows*this->_ncols];

    }

    template <class fp_type>

    void SparseMatrix_DEN<fp_type>::assembleStorage()

    {

	    assert(this->_state != undefined);

        this->_state = building;



        this->A = new fp_type[this->_nrows*this->_ncols]; //Assemble storage

                

        for (size_t i = 0; i < this->_nrows ; i++){

            for (size_t j = 0; j < this->_ncols; j++){

                this->A[i*this->_ncols+j] = 0;//initialize to zero

            }

        }



        typename std::map<std::pair<size_t, size_t>, fp_type>::iterator it = this->_buildCoeff.begin();



        std::pair<size_t,size_t> coordPair;

        fp_type aij = 0;

        while (it != this->_buildCoeff.end())

        {

            coordPair = it->first;

            aij=getCoef(coordPair.first,coordPair.second);

            A[coordPair.first*this->_ncols+coordPair.second]=aij;

            ++it;

        }

        this->_state = assembled;



    }



    template <class fp_type>

    void SparseMatrix_DEN<fp_type>::disassembleStorage()

    {

        if(this->_state != assembled) {

            throw std::runtime_error("Matrix must be assembled before it can be disassembled");

        }



        this->A=nullptr; //Disassemble A

        this->_state = undefined;



    }



    //START DEN ACCESSOR METHODS



    //Returns matrix coefficient value at row and column indices i and j

    template <class fp_type>

    fp_type SparseMatrix_DEN<fp_type>::getCoef(const size_t i, const size_t j)

    {

        

        assert(this->_state != undefined);



        if (j >= this->_ncols || i >= this->_nrows){



		std::cout << "Specified matrix indices are not within the bounds of the matrix" << std::endl;	

		exit(1);

	}



	std::pair<size_t,size_t> coordPair;

	coordPair.first = i;

	coordPair.second = j;



	fp_type aij = this->_buildCoeff[coordPair];



	return aij;



    }



    //Returns the format string for DEN matrices

    template <class fp_type>

    std::string SparseMatrix_DEN<fp_type>::getFormat()

    {

	    return "DEN";

    }

   

    //Returns the number of rows for a DEN format matrix

    template <class fp_type> 

    [[gnu::pure]] size_t SparseMatrix_DEN<fp_type>::getNumRows_DEN()

    {

	    size_t nrowDEN = this->_nrows;

	    return nrowDEN;

    }



    //Returns the number of columns for a DEN format matrix

    template <class fp_type>

    [[gnu::pure]] size_t SparseMatrix_DEN<fp_type>::getNumCols_DEN()

    {

            size_t ncolDEN = this->_ncols;

            return ncolDEN;

    }



    //Sets the coefficient value at row and col index values in specific matrix to aij

    template <class fp_type>

    void SparseMatrix_DEN<fp_type>::setCoefficient_DEN(const size_t row, const size_t col, const fp_type aij)

    {



	assert(this->_state != undefined);

        if (col >= this->_ncols || row >= this->_nrows){



                std::cout << "Specified matrix indices are not within the bounds of the matrix" << std::endl;

                exit(1);

        }







	this->_buildCoeff[std::make_pair(row,col)] = aij;

        this->_nnz = this->_buildCoeff.size();



    } 



    // View Dense matrix

    template <class fp_type>

    void SparseMatrix_DEN<fp_type>::DEN_view() {

	    

        

        std::ofstream outputFile("DEN.out");

	    if (!outputFile.is_open()) {

		    std::cerr << "Error: Could not open file for writing." << std::endl;

		    return;

	    }



	    outputFile << "[";

	    for (size_t i=0;i < this->_nrows;i++) {

		    for (size_t j=0;j< this->_ncols; j++) {

			    outputFile << this->A[i*this->_ncols+j] << "\t";

		}

	    outputFile<<std::endl;

	    }

	    outputFile << "]";

	    outputFile.close();



    }

    //Matvec method



    template <class fp_type>
    void SparseMatrix_DEN<fp_type>:: matvec(fp_type* vecin, fp_type* vecout)

    {
        for (size_t k = 0; k< this->_nrows; k++)
                vecout[k] = 0.0; //Initialising our vecout array as zero
        for (size_t i=0;i < this->_nrows;i++) 
        {
	        for (size_t j=0;j< this->_ncols; j++) 

            {		  
                vecout[i]+=vecin[j]*(this->A[i*this->_ncols+j]); 
            }
        }
    }

    //END DEN ACCESSOR METHODS



    template <class fp_type>

    SparseMatrix_DEN<fp_type>::~SparseMatrix_DEN()

    {

        std::cout << "Goodbye from SparseMatrix Destructor!" << std::endl;

        delete(A);

        A=nullptr;

    }





    template class SparseMatrix_DEN<float>;

    template class SparseMatrix_DEN<double>;

}
