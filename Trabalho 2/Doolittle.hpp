#include <iostream>
#include <vector>

using namespace std;

//Classe para redução de Doolittle
//LSteps é um lista de matriz e guarda todos os passos para encontrar L (LSteps[n-1])
//USteps é um lista de matriz e guarda todos os passos para encontrar U (USteps[n-1])
//result é um vetor com o resultado dos sistema
//n é a ordem da matriz

class Doolittle {
  public:
    vector<vector<vector<double>>> LSteps;
    vector<vector<vector<double>>> USteps;
    vector<double> result;
    int n;

    Doolittle(vector<vector<double>> A, int n){
      this->n = n;

      //Iniciando vetor nulo para matriz L
      vector<vector<double>> L(n);
      for(int i=0; i<n; i++){
        L[i].resize(n);
      }

      //Adicionando diagonal unitária
      for(int i=0; i<n; i++){
        L[i][i] = 1;
      }

      //Iniciando vetor nulo para matriz U
      vector<vector<double>> U(n);
      for(int i=0; i<n; i++){
        U[i].resize(n);
      }

      //Passo inicial:
      for(int i = 0; i < n; i++){
        U[0][i] = A[0][i];
      }

      for(int i = 1; i < n; i++){
        L[i][0] = A[i][0]/U[0][0];
      }

      USteps.push_back(U);
      LSteps.push_back(L);

      //Passo iterativo:

      for(int k = 1; k < n; k++){
          for(int j = k; j < n; j++){

          // Lei de formação para elemento U
          double sum = 0;
          for(int r = 0; r < k; r ++){
            sum = sum + (L[k][r] * U[r][j]);
          }

          U[k][j] = A[k][j] - sum;

          //Lei de formação para elementos L
          if(j + 1 < n){
            sum = 0;
            for(int r = 0; r < k; r ++){
              sum = sum + (L[j+1][r] * U[r][k]);
            }

            L[j+1][k] = (A[j+1][k] - sum)/U[k][k];
          }
        }

        //Salvando passo
        USteps.push_back(U);
        LSteps.push_back(L);
      }

    }

    vector<vector<double>> getLStep(int s){
      return LSteps[s];
    }

    vector<vector<double>> getUStep(int s){
      return USteps[s];
    }

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


  private:
    void reduce(vector<vector<double>> A, vector<vector<double>> M, int n, int step){
      if(step < n){
        for(int j = step; j < n; j++){

          // Lei de formação para elemento U (triagulo superior de M)
          double sum = 0;
          for(int r = 0; r < step; r ++){
            sum = sum + (M[step][r] * M[r][j]);
          }

          M[step][j] = A[step][j] - sum;

          //Lei de formação para elementos L (triangulo inferior de M)
          if(j + 1 < n){
            sum = 0;
            for(int r = 0; r < step; r ++){
              sum = sum + (M[j+1][r] * M[r][step]);
            }

            M[j+1][step] = (A[j+1][step] - sum)/M[step][step];
          }
        }

        reduce(A, M, n, step + 1);

      } else {
        //this->M = M;
      }
    } 

};