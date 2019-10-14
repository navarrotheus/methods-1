#include <iostream>
#include "metodoNewton.hpp"
#include "polinomio.hpp"
#include "tabelas.hpp"
#include <vector>

//Printar tabelas
void mountTable(vector<vector<double>> tabela);
//Formar o polinomio e sua derivada
vector<double> formPolynomial();
//Printar tabela comparativa
void mountComparativeTable(vector<double> tabelaPoly, vector<double> tabelaNewton, vector<double> tabelaScante);
//Metodo de Newton para polimonios
vector<vector<double>> methodNewtonPolynomial(vector<double> polynomial, double chute, double erro, double maxIteration);
vector<vector<double>> methodNewtonPolynomialHorner(vector<double> polynomial, double chute, double erro, double maxIteration);
vector<vector<double>> methodNewtonSecant(vector<double> polynomial, double chute1, double chute2, double erro, double maxIteration);
int main(){
  //Entrada: POLINOMIO, CHUTE, ERRO, MAXIMO DE INTERACOES

  vector <double> teste = {3, -9, -9, 0, 0, 3, 1, 0, 0};
 
  cout << "Metodo de Newton usando calculo de polinomico com Horner:";
  vector <vector<double>> tabelaPoly = methodNewtonPolynomialHorner(teste, 0.5, 0.0001, 1000000000000);
  mountTable(tabelaPoly);
  
  cout << "Metodo de Newton:";
  vector <vector<double>> tabelaNewton = methodNewtonPolynomial(teste, 0.5, 0.0001, 1000000000000);
  mountTable(tabelaNewton);
  
  cout << "Metodo de Secante:";
  vector <vector<double>> tabelaSecante = methodNewtonSecant(teste, 0, 1, 0.0001, 1000000000000);
  mountTable(tabelaSecante);

  vector<double> respostaPoly = tabelaPoly[tabelaPoly.size() - 1];
  vector<double> respostaNewton = tabelaNewton[tabelaNewton.size() - 1];
  vector<double> respostaSecante = tabelaSecante[tabelaSecante.size() - 1];

  cout << endl << "Tabela comparativa:" << endl;
  mountComparativeTable(respostaPoly, respostaNewton, respostaSecante);

  return 0;
}