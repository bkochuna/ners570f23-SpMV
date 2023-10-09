#include <iostream>
#include "SparseMatrix.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  cout << "Hello World!" << endl;

  SpMV::SparseMatrix* ptr_A = new SpMV::SparseMatrix();


  delete(ptr_A);

  return 0;
}
