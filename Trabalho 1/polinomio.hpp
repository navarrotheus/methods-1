#include <iostream>
#include <vector>

using namespace std;
//Funcoes declaradas nesse arquivo
vector<double> formDerivate(vector<double> polynomial);
void printPoly(vector<double> polynomial);
vector<double> formPolynomial();
//Monta o polinomio de no maximo grau 4
vector<double> formPolynomial(){
  //Cria um vetor de double vazio de 10 posicoes
  std::vector<double> polynomial (9, 0);
  double var;
  //Preenche o vetor com os dados input do usuario
  for(int i=0; i<5; i++){
    //Comeca do menor grau (zero) ate o maior (quatro)
    cout << " \n Coeficiente de grau: " << i << "\n";
    cin >> var;
    //Armazena os valores do polinomio nas posicoes pares
    //de forma que se um elemento tem grau 2 ele fica alocado na
    //posicao 4, se tem grau 3 fica alocado na posicao 6... e assim por diante
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
  cout << "\n Polinomio P(x): ";
  for(int i=0; i<4; i++){
    cout << polynomial[(i+1)*2] << " ";
  }
  cout << "\n Derivado de P(x): ";
  for(int i=0; i< 4; i++){
    cout << polynomial[(i*2)+1] << " ";
  }
  cout << "\n Meu vetor: ";
  for(int i=0; i< int(polynomial.size()); i++){
    cout << polynomial[i] << " ";
  }
  cout << "\n";
}