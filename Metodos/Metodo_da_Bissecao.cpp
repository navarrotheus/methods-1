#include<stdio.h>
#include<stdlib.h>
#include <vector>

#include "Bisection.hpp"


double fx(double x, int tamanho, vector<double> poli);
double bisection(double interA, double interB, double erro, int maxIteration);

int main(void){

  vector<double> polinomio = criarPoli();

  cout << "Valor aproximado da raiz: " << bisection(-1000000000, 1000000000, 0.0000000000001, 100, polinomio) << "\n";
  return 0;
}