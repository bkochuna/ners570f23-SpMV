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
  cout << "UDF=" << SpMV::UDF << endl;
  cout << "DEN=" << SpMV::DEN << endl;
  cout << "COO=" << SpMV::COO << endl;
  cout << "CSR=" << SpMV::CSR << endl;
  cout << "undefined=" << SpMV::undefined << endl;


  SpMV::SparseMatrix<float>* ptr_A = new SpMV::SparseMatrix_COO<float>(1,5);
  SpMV::SparseMatrix<double>* ptr_b = new SpMV::SparseMatrix_CSR<double>(5,5);

  cout << "ptr_A is format=" << ptr_A->getFormat() << endl;
  cout << "ptr_b is format=" << ptr_b->getFormat() << endl;
  
  // New scoping unit. This means variables defined in here, stay here.
  {
    SpMV::SparseMatrix_COO<double> A = SpMV::SparseMatrix_COO<double>(2,2);
    A.setCoefficient(0,0,1.0);
    A.setCoefficient(0,1,2.0);
    A.setCoefficient(1,0,3.0);
    A.setCoefficient(1,1,4.0);
    A.view();
    cout << endl;
    A.assembleStorage();
    A.view();
    cout << endl;
    cout << A.getCoefficient(1,1) << endl;
    A.setCoefficient(1,1,5.0);
    cout << A.getCoefficient(1,1) << endl;

  }
  cout << ptr_A->getCoefficient(0,3) << endl;
  ptr_A->setCoefficient(0,3,4.0);
  cout << ptr_A->getCoefficient(0,3) << endl;
  cout << ptr_A->getCoefficient(0,2) << endl;

  delete(ptr_A);
  delete(ptr_b);

  return 0;
}
