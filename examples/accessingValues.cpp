#include <iostream>
#include "SpMV.hpp"

using namespace std;

int main()
{

  SpMV::SparseMatrix<float>* ptr_A = new SpMV::SparseMatrix_ELL<float>(5,5);
  
  ptr_A->setCoefficient(0,3,4.0);
  
  ptr_A->getLongestRow();

  return 0;
}
