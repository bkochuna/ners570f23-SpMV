#include <iostream>
#include "SpMV.hpp"

using namespace std;

// Traditionally, main takes two arguments: argc and argv.
// These are the number of command line arguments and the arguments themselves.
// int main(int argc, char* argv[])
// However, we don't need them for this example.
int main()
{
  cout << "Hello World!" << endl;

  SpMV::SparseMatrix<float>* ptr_A = new SpMV::SparseMatrix_COO<float>(1,5);
  
  // New scoping unit. This means variables defined in here, stay here.
  {
    SpMV::SparseMatrix_COO<double> A = SpMV::SparseMatrix_COO<double>(2,2);
    // std::cout << A.getState() << std::endl;
    A.setCoefficient(1,1,1.0);
    // std::cout << A.getState() << std::endl;
    // A.assembleStorage();
    // std::cout << A.getState() << std::endl;
    // A.disassembleStorage();
    // std::cout << A.getState() << std::endl;
  }
  ptr_A->setCoefficient(0,3,4.0);

  delete(ptr_A);

  return 0;
}
