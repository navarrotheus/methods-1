
#include "metodo.hpp"

// O polinomio é um vetor no qual os numeros dos indices pares representa
// p(x) e nos indices impares a derivada de p(x).
// O indice de cada número representa o grau i/2 no polinomio p(x)
// O indice de cada número representa o grau i-1 na derivada p(x)
//formPolynomial();
vector<double> formPolynomial();

//Metodo de Newton para polimonios
void methodNewton(vector<double> polynomial, double chute, double erro, double maxIteration);

int main(){

  methodNewton(formPolynomial(), 1000, 0.00000000001, 1000000000000);

  return 0;
}