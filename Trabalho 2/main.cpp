#include <iostream>
#include <vector>
#include "LUFactorization.hpp"
#include "table.hpp"
using namespace std;

int main(){

int grauA;

cout << "Qual o grau da Matriz A?" << endl;
cin >> grauA;

vector<vector<double>> A(grauA);
for(int i=0; i<grauA; i++){
  A[i].resize(grauA);
}

vector<double>b(grauA);

double var;

for(int i=0; i<grauA; i++){
  for(int j=0; j<grauA; j++){
    cout << "Entre o valor do a" << i << j << ": ";
    cin >> var;
    A[i][j] = var;
  }
}

for(int i=0; i<grauA; i++){
  cout << "Entre o valor do b" << i << ": ";
  cin >> var;
  b[i] = var;
}

PivotedLU P(A, b, 3);

  vector<vector<double>> L1 = P.getLStep(2);
  vector<vector<double>> U1 = P.getUStep(2);
  vector<double> X1 = P.getResult();

  cout << "Fatoração LU com pivotação:" << endl;

  cout << "Resultado de L:" << endl;

  cout << L1[0][0] << " " << L1[0][1] << " " << L1[0][2] << endl;
  cout << L1[1][0] << " " << L1[1][1] << " " << L1[1][2] << endl;
  cout << L1[2][0] << " " << L1[2][1] << " " << L1[2][2] << endl << endl;

  cout << "Resultado de U:" << endl;

  cout << U1[0][0] << " " << U1[0][1] << " " << U1[0][2] << endl;
  cout << U1[1][0] << " " << U1[1][1] << " " << U1[1][2] << endl;
  cout << U1[2][0] << " " << U1[2][1] << " " << U1[2][2] << endl << endl;

  cout << "Resultado Xi:" <<endl;
  for (int i = 0; i < 3; i++){
      cout << "X" << i << " = " << X1[i] << endl; 
  }

  cout << "Redução Doolittle:" << endl;

  Doolittle D(A, b, 3);

  vector<vector<double>> L2 = D.getLStep(2);
  vector<vector<double>> U2 = D.getUStep(2);
  vector<double> X2 = D.getResult();

  cout << "Resultado de L:" << endl;

  cout << L2[0][0] << " " << L2[0][1] << " " << L2[0][2] << endl;
  cout << L2[1][0] << " " << L2[1][1] << " " << L2[1][2] << endl;
  cout << L2[2][0] << " " << L2[2][1] << " " << L2[2][2] << endl << endl;

  cout << "Resultado de U:" << endl;

  cout << U2[0][0] << " " << U2[0][1] << " " << U2[0][2] << endl;
  cout << U2[1][0] << " " << U2[1][1] << " " << U2[1][2] << endl;
  cout << U2[2][0] << " " << U2[2][1] << " " << U2[2][2] << endl << endl;


  cout << "Resultado Xi:" <<endl;
  for (int i = 0; i < 3; i++){
      cout << "X" << i << " = " << X2[i] << endl; 
  }
  cout << "+++++++++++++++++++++++++++++++++++++++++++++ \n" ;
  cout << "                Fatoração LU                  \n";
  cout << "+++++++++++++++++++++++++++++++++++++++++++++ \n" ;
  cout << "============================================= \n" ;
  cout << "                MATRIZ: A                     \n";
  cout << "============================================= \n" ;
  table(A);
  cout << "============================================= \n" ;
  cout << "                MATRIZ: b                     \n";
  cout << "============================================= \n" ;
  unionTable(b);
  cout << "============================================= \n" ;
  cout << "                MATRIZ: L                     \n";
  cout << "============================================= \n" ;
  table(L1);
  cout << "============================================= \n" ;
  cout << "                MATRIZ: U                     \n";
  cout << "============================================= \n" ;
  table(U1);
  cout << "============================================= \n" ;
  cout << "                MATRIZ: X                     \n";
  cout << "============================================= \n" ;
  unionTable(X1);
  cout << endl;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++ \n" ;
  cout << "           Redução de Doolittle               \n";
  cout << "+++++++++++++++++++++++++++++++++++++++++++++ \n" ;
  cout << "============================================= \n" ;
  cout << "                MATRIZ: A                     \n";
  cout << "============================================= \n" ;
  table(A);
  cout << "============================================= \n" ;
  cout << "                MATRIZ: b                     \n";
  cout << "============================================= \n" ;
  unionTable(b);
  cout << "============================================= \n" ;
  cout << "                MATRIZ: L                     \n";
  cout << "============================================= \n" ;
  table(L2);
  cout << "============================================= \n" ;
  cout << "                MATRIZ: U                     \n";
  cout << "============================================= \n" ;
  table(U2);
  cout << "============================================= \n" ;
  cout << "                MATRIZ: X                     \n";
  cout << "============================================= \n" ;
  unionTable(X2);

  return 0;

}