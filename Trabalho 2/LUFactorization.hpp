#include <iostream>
#include <vector>

using namespace std;

//Classe para pai para Fatorização LU (Redução de Doolittle e Com pivotação)

//LSteps é um lista de matriz e guarda todos os passos para encontrar L (LSteps[n-1])
//USteps é um lista de matriz e guarda todos os passos para encontrar U (USteps[n-1])
//b guarda vetor com variáveis livres
//A guarda matriz inicial
//result é um vetor com o resultado dos sistema
//n é a ordem da matriz A

//getLStep retorna um passo k na construção de L
//getUStep retorna um passo k na construção de U
//getResult retorna o resultado do sistema do vector result
//findResult calcula o resultado do sistema e guarda no vector result (método a ser chamado junto com constructor)

class LUFactorization {
  public:
    vector<vector<vector<double>>> LSteps;
    vector<vector<vector<double>>> USteps;
    vector<double> b;
    vector<vector<double>> A;
    vector<double> result;
    int n;

    //Método destrutor
    ~LUFactorization(){
      LSteps.erase(LSteps.begin(), LSteps.end());
      USteps.erase(USteps.begin(), USteps.end());
      b.erase(b.begin(), b.end());
      A.erase(A.begin(), A.end());
      result.erase(result.begin(), result.end());
    }

    vector<vector<double>> getLStep(int s){
      return LSteps[s];
    }

    vector<vector<double>> getUStep(int s){
      return USteps[s];
    }

    vector<double> getResult(){
      return result;
    }

  protected:
    void findResult(){
      vector<vector<double>> L = LSteps[n-1];
      vector<vector<double>> U = USteps[n-1];

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

      result = X;
    }
};

//Classe para redução de Doolittle
//Filha da classe LUFactorization

class Doolittle: public LUFactorization {
  public:

    Doolittle(vector<vector<double>> A, vector<double> b, int n){
      this->n = n;
      this->A = A;
      this->b = b;

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

      //Gerando resultado a partir do L e U gerados
      findResult();
    }

};

//Class para fatoração LU com pivotação (adicionar em breve)
//Class filha da class LUFactorization

class PivotedLU: public LUFactorization {
  public:

    PivotedLU(vector<vector<double>> A, vector<double> b, int n){
      this->n = n;
      this->A = A;
      this->b = b;

      //Iniciando vetor nulo que receberá os multiplicadores
      vector<vector<double>> L(n);
      for(int i=0; i<n; i++){
        L[i].resize(n);
      }

      //Adicionando diagonal unitária
      for(int i=0; i<n; i++){
        L[i][i] = 1;
      }

      double pivo; //Substituir por escolhar inteligente
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

      //Gerando resultado a partir do L e U gerados
      findResult();

    };

};