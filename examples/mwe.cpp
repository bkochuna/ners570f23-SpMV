#include <iostream>
#include "SparseMatrix.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  cout << "Hello World!" << endl;

  SpMV::SparseMatrix* ptr_A = new SpMV::SparseMatrix(1,5);
  
  // New scoping unit. This means variables defined in here, stay here.
  {
    SpMV::SparseMatrix A = SpMV::SparseMatrix(2,2);
  }

  delete(ptr_A);

  return 0;
}
