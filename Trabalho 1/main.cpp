#include "polinomio.hpp"
#include "metodo.hpp"

vector<double> formPolynomial();
void methodNewton(vector<double> polynomial, double chute, double erro, double maxIteration);

int main(){
  // O polinomio é um vetor no qual os numeros dos indices pares representa
  // p(x) e nos indices impares a derivada de p(x).
  // O indice de cada número representa o grau i/2 no polinomio p(x)
  // O indice de cada número representa o grau i-1 na derivada p(x)
  //formPolynomial();

  methodNewton(formPolynomial(), 0.5, 0.0001, 5);

  return 0;
}