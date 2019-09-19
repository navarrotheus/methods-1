#include<stdio.h>
#include<stdlib.h>
#include <vector>

#include "Bisection.hpp"

int main(void){

  vector<double> polinomio {1, 30, 49, 12, 5, 27};
 
  cout << "Valor aproximado da raiz: " << bisection(-1000000000, 1000000000, 0.0000000000001, 100, polinomio) << "\n";
  return 0;
}