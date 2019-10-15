#include <iostream>
#include <vector>

// O polinomio é um vetor no qual os numeros dos indices pares representa
// p(x) e nos indices impares a derivada de p(x).
// O indice de cada número representa o grau i/2 no polinomio p(x)
// O indice de cada número representa o grau i-1 na derivada p(x)
//formPolynomial();

using namespace std;
//Funcoes declaradas nesse arquivo
vector<double> formDerivate(vector<double> polynomial);
void printPoly(vector<double> polynomial);
vector<double> formPolynomial();
//Monta o polinomio de no maximo grau 4
vector<double> formPolynomial(){
  //Cria um vetor de double vazio de 10 posicoes
  vector<double> polynomial (10, 0);
  //Preenche o vetor com os dados input do usuario
  double var;
  for(int i=0; i<5; i++){
    //Comeca do menor grau (zero) ate o maior (quatro)
    cout << "\nCoeficiente de grau: " << i << "\n";
    cin >> var;
    polynomial[i*2] = var;
  }
  //Preenche as posicoes impares do vetor com o valor da derivada de cada grau
  
  polynomial = formDerivate(polynomial);
  return polynomial;
}
//Constroi a derivada do polinomio e aloca ela na posicao adequada
//O coeficiente de grau 3 esta alocado na posicao 
vector<double> formDerivate(vector<double> polynomial){
  int var;
  for(int i=0; i<5; i++){
    polynomial[(i*2) + 1] = (i+1)*polynomial[((i+1)*2)];
  }
  return polynomial;
}

void printPoly(vector<double> polynomial){
  cout << "\nPolinomio P(x): ";
  cout << polynomial[0] << " ";
  for(int i=0; i<4; i++){
    cout << polynomial[(i+1)*2] << "x^" << i+1 << " ";
  }
  cout << "\n";
  //cout << "\nDerivado de P(x): ";
  //for(int i=0; i< 4; i++){
    //cout << polynomial[(i*2)+1] << " ";
  //}
  //cout << "\nMeu vetor: ";
  //for(int i=0; i< int(polynomial.size()); i++){
    //cout << polynomial[i] << " ";
  //}
  //cout << "\n"; 
}
