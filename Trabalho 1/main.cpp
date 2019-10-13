#include "metodoNewton.hpp"
#include "polinomio.hpp"
#include "tabelas.hpp"

//Printar tabelas
void mountTable(vector<vector<double>> tabela);
//Formar o polinomio e sua derivada
vector<double> formPolynomial();
//Metodo de Newton para polimonios
vector<vector<double>> methodNewtonPolynomial(vector<double> polynomial, double chute, double erro, double maxIteration);
vector<vector<double>> methodNewtonPolynomialHorner(vector<double> polynomial, double chute, double erro, double maxIteration);
vector<vector<double>> methodNewtonSecant(vector<double> polynomial, double chute1, double chute2, double erro, double maxIteration);
int main(){
  //Entrada: POLINOMIO, CHUTE, ERRO, MAXIMO DE INTERACOES

  vector <double> teste = {3, -9, -9, 0, 0, 3, 1, 0, 0};
  cout << "Metodo de Newton usando calculo de polinomico com Horner:";
  mountTable(methodNewtonPolynomialHorner(teste, 0.5, 0.0001, 1000000000000));
  cout << "Metodo de Newton:";
  mountTable(methodNewtonPolynomial(teste, 0.5, 0.0001, 1000000000000));
  cout << "Metodo de Secante:";
  mountTable(methodNewtonSecant(teste, 0, 1, 0.0001, 1000000000000));

  return 0;
}