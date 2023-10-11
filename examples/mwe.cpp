#include <iostream>
#include "SpMV.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  cout << "Hello World!" << endl;

  SpMV::SparseMatrix<float>* ptr_A = new SpMV::SparseMatrix_COO<float>(1,5);
  
  // New scoping unit. This means variables defined in here, stay here.
  {
    SpMV::SparseMatrix_COO<double> A = SpMV::SparseMatrix_COO<double>(2,2);
    A.setCoefficient(1,1,1.0);

  }
  ptr_A->setCoefficient(0,3,4.0);

  delete(ptr_A);

  return 0;
}
