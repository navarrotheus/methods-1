#include <iostream>
#include <vector>

using namespace std;

//Class para redução Doolittle
//Lsteps é uma lista de matrizes contendo todos os passos para encontrar L
//Lsteps[n - 1 é o resultado de L
//Usteps é uma lista de matrizes contendo todos os passos para encontrar U
//Usteps[n - 1] é o resultado de U

class Doolittle {
  public:
    vector<vector<vector<double>>> LSteps;
    vector<vector<vector<double>>> USteps;

    Doolittle (vector<vector<double>> A, int n){
      
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

    vector<vector<double>> getLStep(int s){
      return LSteps[s];
    }

    vector<vector<double>> getUStep(int s){
      return USteps[s];
    }

    ~Doolittle(){
        LSteps.erase(LSteps.begin(), LSteps.end());
        USteps.erase(USteps.begin(), USteps.end());
    } 
};