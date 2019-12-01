#include <iostream>
#include <vector>

using namespace std;

//Class para fatoração L U
//LSteps é uma lista de matrizes contendo todos os passos para encontrar L
//LSteps[n - 1 é o resultado de L
//USteps é uma lista de matrizes contendo todos os passos para encontrar U
//USteps[n - 1] é o resultado de U

class LUFactorization {
  public:
    vector<vector<vector<double>>> LSteps;
    vector<vector<vector<double>>> USteps;

    int n;

    LUFactorization (vector<vector<double>> A, int n){

      this->n = n;

      //Iniciando vetor nulo que receberá os multiplicadores
      vector<vector<double>> L(n);
      for(int i=0; i<n; i++){
        L[i].resize(n);
      }

      //Adicionando diagonal unitária
      for(int i=0; i<n; i++){
        L[i][i] = 1;
      }

      double pivo;
      double m;
      for(int j=0; j<n; j++){
        //Pegando diagonal como pivo;
        pivo = A[j][j];
        //Eliminação de Gauss nas linhas abaixo da diagonal
        for(int i = j + 1; i < n; i++){
          //Salvando multiplicador;
          m = A[i][j]/pivo;
          L[i][j] = m;

          //Atualizando linha de A
          //k será um iterador para colunas de A
          for(int k=0; k<n; k++){
            A[i][k] = A[i][k] - (m * A[j][k]);
          }

          //Salvando os passos
          LSteps.push_back(L);
          USteps.push_back(A);
        }

      }

    };

    //solução do sistema linear L(Ux) = b
    vector<double> solucaoLU(vector<vector<double>> L, vector<vector<double>> U, vector<double> B){

      vector<double> b = B;

      //Ly = b por substituições sucessivas:
      vector<double> Y;
      for (int i = 0; i < n; i++){ // calculando Y
        double soma = 0;
        for (int j = 0; j < i; j++){
          soma = soma + L[i][j] * Y[j];
        }
        Y.push_back((b[i] - soma)/L[i][i]);
      }

      //Ux = y por substituições retroativas:
      vector<double> X(n); //double X[n];
      X[n-1] = Y[n-1] / U[n-1][n-1];
      for (int i = n-2; i >= 0 ; i--){ //calculando X
        double soma = 0;
        for (int j = i + 1; j < n; j++){
          soma = soma + U[i][j] * X[j];
        }
        X[i] = (Y[i] - soma)/U[i][i]; 
      }
      
      return X;
    }

    vector<vector<double>> getLStep(int s){
      return LSteps[s];
    }

    vector<vector<double>> getUStep(int s){
      return USteps[s];
    }

    ~LUFactorization(){
        LSteps.erase(LSteps.begin(), LSteps.end());
        USteps.erase(USteps.begin(), USteps.end());
    }
};
