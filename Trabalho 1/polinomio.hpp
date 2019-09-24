#include <iostream>
#include <vector>

using namespace std;

vector<double> formDerivate(vector<double> polynomial);
void printPoly(vector<double> polynomial);

vector<double> formPolynomial(){
  
  std::vector<double> polynomial (9, 0);
  double var;
  cout << "teste" << "\n";  
  for(int i=0; i<5; i++){
    cout << "Coeficiente de grau: " << i << "\n";
    cin >> var;
    polynomial[i*2] = var;
    cout << "\n";
  }
  polynomial = formDerivate(polynomial);
  return polynomial;
}

vector<double> formDerivate(vector<double> polynomial){
  int var;
  for(int i=0; i<5; i++){
    polynomial[(i*2) + 1] = (i+1)*polynomial[((i+1)*2)];
  }
  return polynomial;
}

void printPoly(vector<double> polynomial){
  for(auto i = polynomial.begin(); i != polynomial.end();i++){
    cout << *i << " ";
  }
  cout << "\n";
}