#include <iostream>
#include "SparseMatrix.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  cout << "Hello World!" << endl;

  SpMV::SparseMatrix<float>* ptr_A = new SpMV::SparseMatrix<float>(1,5);
  
  // New scoping unit. This means variables defined in here, stay here.
  {
    SpMV::SparseMatrix<double> A = SpMV::SparseMatrix<double>(2,2);
  }

  delete(ptr_A);

  return 0;
}
