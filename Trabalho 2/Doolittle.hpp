#include <iostream>
#include <vector>


using namespace std;

//Class para redução Doolittle
//Lsteps é uma lista de matrizes contendo todos os passos para encontrar L
//Lsteps[n - 1 é o resultado de L
//Usteps é uma lista de matrizes contendo todos os passos para encontrar U
//Usteps[n - 1] é o resultado de U


//Obs.: Por enquanto está mostrando só o ultimo passo, usar lista de vetores não funciona


class Doolittle {
  public:
    vector<vector<double>> LSteps;
    vector<vector<double>> USteps;

    Doolittle (vector<vector<double>> A, int n){
      sizeSteps(n);

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
          L[i][j] = m * (-1);
          
          //Atualizando linha de A
          //k será um iterador para colunas de A
          for(int k=0; k<n; k++){
            A[i][k] = A[i][k] - (m * A[j][k]);
          }

          //Salvando os passos
          LSteps = L;
          USteps = A;
        }

      }

    };

    vector<vector<double>> getLStep(int s){
      return LSteps;
    }

    vector<vector<double>> getUStep(int s){
      return USteps;
    }

    //Configurando tamanhos dos vetores de passos
    void sizeSteps(int n){
      //Configurando tamanhos das listas de passos
      LSteps.resize(n);
      USteps.resize(n);
      
      for(int i = 0; i < n; i++){
        //Dandos n linhas parra cada elemento da lista
        LSteps[i].resize(n);
        USteps[i].resize(n);

        
      } 
    }  
};