#include <iostream>
#include <vector>
#include "LUFactorization.hpp"

using namespace std;

int main(){

int grauA;

cout << "Qual o grau da Matriz A?" << endl;
cin >> grauA;

vector<vector<double>> A(grauA);
for(int i=0; i<grauA; i++){
  A[i].resize(grauA);
}

vector<double>B(grauA);

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
  B.push_back(var);
}

}