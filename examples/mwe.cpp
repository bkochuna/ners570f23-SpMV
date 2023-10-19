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
    A.setCoefficient(1,1,1.0);

  }
  ptr_A->setCoefficient(0,3,4.0);

  delete(ptr_A);

  std::cout<<std::endl;
  SpMV::SparseMatrix_CSR<float>* ptr_B = new SpMV::SparseMatrix_CSR<float>(4,4);
  ptr_B->setCoefficient(0,0,1.0);
  ptr_B->setCoefficient(1,3,9.0);
  ptr_B->setCoefficient(0,1,7.0);
  ptr_B->setCoefficient(2,1,2.0);
  ptr_B->setCoefficient(2,2,8.0);
  ptr_B->setCoefficient(3,3,6.0);
  ptr_B->setCoefficient(1,0,5.0);
  ptr_B->setCoefficient(1,2,3.0);
  delete(ptr_B);

  return 0;
}
