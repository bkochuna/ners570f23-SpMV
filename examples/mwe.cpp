#include <iostream>
#include "SpMV.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  cout << "Hello World!" << endl;

  SpMV::SparseMatrix<float>* ptr_A = new SpMV::SparseMatrix_COO<float>(1,5);
  
  // New scoping unit. This means variables defined in here, stay here.
  {
    SpMV::SparseMatrix<double> A = SpMV::SparseMatrix<double>(2,2);
    A.setCoefficient(1,1,1.0);

  }
  ptr_A->setCoefficient(1,3,4.0);

  delete(ptr_A);

  return 0;
}
