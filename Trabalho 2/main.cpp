#include <iostream>
#include <vector>
#include <cmath>
#include "LUFactorization.hpp"
#include "table.hpp"
using namespace std;

//Função auxiliar para calculo de determinante
vector<vector<double>> subMatriz(vector<vector<double>> M, int ordem,  int j);

//Função recursiva para calculo de determinante
double det(vector<vector<double>> M, int ordem);

int main(){

  cout << "============================================= \n" ;
  cout << "              CÁLCULO DE CO2                  \n";
  cout << "============================================= \n" ;

  int grauA;

  cout << "Qual a ordem da Matriz A?" << endl;
  cin >> grauA;

  vector<vector<double>> A(grauA);

  for(int i=0; i<grauA; i++){
    A[i].resize(grauA);
  }

  vector<double>b(grauA);

  double var;

  for(int i=0; i<grauA; i++){
    for(int j=0; j<grauA; j++){
      cout << "Entre o valor de a" << i+1 << j+1 << ": ";
      cin >> var;
      A[i][j] = var;
    }
  }

  for(int i=0; i<grauA; i++){
    cout << "Entre o valor de d" << i+1 << ": ";
    cin >> var;
    b[i] = var;
  }

  cout << det(A, grauA) << endl;

  if(det(A, grauA) == 0){
    cout << "Esta matriz é singular e não possui resultados..." << endl;
    return 0;

  } else {

  PivotedLU P(A, b, grauA);

  vector<vector<double>> L1 = P.getLStep(grauA - 1);
  vector<vector<double>> U1 = P.getUStep(grauA - 1);
  vector<double> X1 = P.getResult();
  vector<double> Perm = P.getPStep(grauA - 1);

  Doolittle D(A, b, grauA);

  vector<vector<double>> L2 = D.getLStep(grauA - 1);
  vector<vector<double>> U2 = D.getUStep(grauA - 1);
  vector<double> X2 = D.getResult();

  cout << "+++++++++++++++++++++++++++++++++++++++++++++ \n" ;
  cout << "                Fatoração LU                  \n";
  cout << "+++++++++++++++++++++++++++++++++++++++++++++ \n" ;
  cout << "============================================= \n" ;
  cout << "                MATRIZ A                      \n";
  cout << "============================================= \n" ;
  table(A);
  cout << "============================================= \n" ;
  cout << "                VETOR {d}                     \n";
  cout << "============================================= \n" ;
  unionTable(b);
  cout << "============================================= \n" ;
  cout << "                MATRIZ L                      \n";
  cout << "============================================= \n" ;
  table(L1);
  cout << "============================================= \n" ;
  cout << "                MATRIZ U                      \n";
  cout << "============================================= \n" ;
  table(U1);
  cout << "============================================= \n" ;
  cout << "           VETOR DE PERMUTAÇÃO                \n";
  cout << "============================================= \n" ;
  unionTable(Perm);
  cout << "============================================= \n" ;
  cout << "              QUANTIDADES {c}                 \n";
  cout << "============================================= \n" ;
  unionTable(X1);
  cout << endl;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++ \n" ;
  cout << "           Redução de Doolittle               \n";
  cout << "+++++++++++++++++++++++++++++++++++++++++++++ \n" ;
  cout << "============================================= \n" ;
  cout << "                MATRIZ A                      \n";
  cout << "============================================= \n" ;
  table(A);
  cout << "============================================= \n" ;
  cout << "                VETOR {d}                     \n";
  cout << "============================================= \n" ;
  unionTable(b);
  cout << "============================================= \n" ;
  cout << "                MATRIZ L                      \n";
  cout << "============================================= \n" ;
  table(L2);
  cout << "============================================= \n" ;
  cout << "                MATRIZ U                      \n";
  cout << "============================================= \n" ;
  table(U2);
  cout << "============================================= \n" ;
  cout << "              QUANTIDADES {c}                 \n";
  cout << "============================================= \n" ;
  unionTable(X2);
  cout << endl;  
  
  return 0;

  }
}

double det(vector<vector<double>> M, int ordem){
  if(ordem == 1){
    return M[ordem - 1][ordem - 1];
  } else {
    double detSum = 0;

    for(int i = 0; i < ordem; i++){
      vector<vector<double>> SubM = subMatriz(M, ordem, i);
      detSum = detSum + ((M[0][i] * det(SubM, ordem - 1)) * pow(-1, i));
    }
    return detSum;
  }
}

vector<vector<double>> subMatriz(vector<vector<double>> M, int ordem,  int j){
  vector<vector<double>> SubM(ordem - 1);

  for(int i = 1; i < ordem; i++){
    for(int k = 0; k < ordem; k++){
      if(k != j){
        SubM[i - 1].push_back(M[i][k]);
      }
    }
  }

  return SubM;
}