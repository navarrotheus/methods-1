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


// Struct para pivô
// pv é valor do pivô
// l é a posicao(linha) onde se encontra o pivô

struct InfoPivot{
    double pv;
    int l;
};

//Class para fatoração LU com pivotação
//Class filha da class LUFactorization
//PVteps guarda uma lista de vetores de permutação

class PivotedLU: public LUFactorization {
  public:
    vector<vector<int>> PSteps;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       

    PivotedLU(vector<vector<double>> A, vector<double> b, int n){
      this->n = n;
      this->A = A;
      this->b = b;

      //Iniciando matriz nula que receberá os multiplicadores e vector de permutação;
      vector<vector<double>> L(n);
      vector<int> P;

      for(int i=0; i<n; i++){
        L[i].resize(n);
      }

      //Adicionando diagonal unitária a L e iniciando vetorr de perutação (1, 2, 3,..., n)
      for(int i=0; i<n; i++){
        L[i][i] = 1;
        P.push_back(i+1);
      }

      InfoPivot pivo; //Substituir por escolhar inteligente
      double m;
      for(int j=0; j<n; j++){
        //Pegando maior valor absoluto como pivo;
        InfoPivot pivo = findPivot(A, j, n);
        cout << pivo.pv << endl;

        //Efetuando permutação
        permutation(P, A, j, pivo.l, n);

        //Eliminação de Gauss nas linhas abaixo da diagonal
        for(int i = j + 1; i < n; i++){
          //Salvando multiplicador;
          m = A[i][j]/pivo.pv;
          L[i][j] = m;

          //Atualizando linha de A
          //k será um iterador para colunas de A
          for(int k=0; k<n; k++){
            A[i][k] = A[i][k] - (m * A[j][k]);
          }
        }

        //Salvando os passos
        LSteps.push_back(L);
        USteps.push_back(A);
        PSteps.push_back(P);

      }

      //Gerando resultado a partir do L e U gerados
      findResult();

    };

  private:
    //Recebe a Matriz, o índice da linha, e n(dimensao) das linhas da matriz. Retorna pv(pivo) e l (linha onde está o pivo)
    InfoPivot findPivot(vector<vector<double>> matriz, int k, int n){
      InfoPivot pivo;
      pivo.pv = abs(matriz[k][k]);
      pivo.l = k;

      for(int i = k + 1; i < n; i++){
        if(abs(matriz[i][k]) > pivo.pv){
          pivo.pv = abs(matriz[i][k]);
          pivo.l = i;
        }
      }

      return pivo;
    }

    void permutation(vector<int> &P, vector<vector<double>> &matriz, int k, int r, int n){
      int aux1 = P[k];
      P[k] = P[r];
      P[r] = aux1;

      double aux = this->b[k];
      this->b[k] = this->b[r];
      this->b[r] = aux;

      for(int j = 0; j < n; j++){
        aux = matriz[k][j];
        matriz[k][j] = matriz[r][j];
        matriz[r][j] = aux;
      }
    }

};