#include <iostream>
#include "metodoNewton.hpp"
#include "polinomio.hpp"
#include "tabelas.hpp"
#include "chute.hpp"
#include <vector>

using namespace std;

double calculateKick(vector<double> funcao);
void tabelaFinal(vector<vector<double>> funcoes);
vector<vector<double>> moontarTudo(vector<vector<double>> funcoes);
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
  int qtdFunc;
  vector<vector<double>> funcoes;
  //Entrada: POLINOMIO, CHUTE, ERRO, MAXIMO DE INTERACOES
  cout << "Quantas funções serão resolvidas?\n";
  cin >> qtdFunc;
  for (int i=0; i<qtdFunc; i++){
    cout << "Escreva os valores da função: " << i+1 << "\n"; 
    funcoes.push_back(formPolynomial());
  }
  tabelaFinal(moontarTudo(funcoes));
  return 0;
}

vector<vector<double>> moontarTudo(vector<vector<double>> funcoes){
  vector<vector<double>> respostaCompar;

  int maxInteration = 5;
  double erro = 0.001;

  for(int i=0; i<funcoes.size(); i++){
    double chute = calculateKick(funcoes[i]);

    vector <double> teste = funcoes[i];
    cout << "Função: "; printPoly(teste); cout << "Metodo de Newton usando calculo de polinomico com Horner:";
    vector <vector<double>> tabelaPoly = methodNewtonPolynomialHorner(teste, chute, erro, maxInteration);
    mountTable(tabelaPoly);
    
    cout << "Função: "; printPoly(teste); cout << "Metodo de Newton:";
    vector <vector<double>> tabelaNewton = methodNewtonPolynomial(teste, chute, erro, maxInteration);
    mountTable(tabelaNewton);
    
    cout << "Função: "; printPoly(teste); cout<< "Metodo de Secante:";
    vector <vector<double>> tabelaSecante = methodNewtonSecant(teste, (chute*2), chute, erro, maxInteration);
    mountTable(tabelaSecante);

    respostaCompar.push_back(teste);
    vector<double> respostaPoly = tabelaPoly[tabelaPoly.size() - 1];
    respostaCompar.push_back(respostaPoly);
    vector<double> respostaNewton = tabelaNewton[tabelaNewton.size() - 1];
    respostaCompar.push_back(respostaNewton);    
    vector<double> respostaSecante = tabelaSecante[tabelaSecante.size() - 1];
    respostaCompar.push_back(respostaSecante);
  }
  return respostaCompar;
}

void tabelaFinal(vector<vector<double>> funcoes){
  for (int i=0; i<funcoes.size(); i = i+4){
    printPoly(funcoes[i]);
    mountComparativeTable(funcoes[i+1], funcoes[i+2], funcoes[i+3]);
  }
}
