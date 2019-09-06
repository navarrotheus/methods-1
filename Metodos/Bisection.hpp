#include<cmath>
#include<iostream>
#include <vector>

using namespace std;

vector<double> criarPoli(){
  vector<double> polinomio;
  int tamanho;

  cout << "Qual o grau do polinomio? Escreva do menor ao maior ";
  cin >> tamanho;

  int var;
  for(int i=0; i<tamanho+1; i++){
    cout << "Coeficiente de grau: " << i << "\n";
    cin >> var;
    polinomio.push_back(var);
    cout << "\n";
  }
  return polinomio;
}

double fx(double x, int tamanho, vector<double> poli){
  double resultado = 0;
  for(int i=0; i<tamanho; i++){
    resultado += poli[i]*(pow(x, i));
  };
  return resultado;
}

double bisection(double interA, double interB, double erro, int maxIteration, vector<double> polino){
  clock_t start, end;
  start = clock();
  int tamPoli = polino.size();

  double xMedio = (interA + interB)/2;
  double fa = fx( interA, tamPoli, polino);
  double fb = fx( interB, tamPoli, polino);
  double fm = fx( xMedio, tamPoli, polino);

  for (int i=0; i<maxIteration; i++){
    (fa > 0 && fm < 0) || (fa < 0 && fm > 0) ? interB = xMedio : interA = xMedio;

    fa = fx( interA, tamPoli, polino);
    fb = fx( interB, tamPoli, polino);
    xMedio = (interA + interB)/2;
    fm = fx( xMedio, tamPoli, polino);

    if (abs(fm) <= erro){
      end = clock();
      cout << " \n tempo de execuçao: " << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
      return xMedio;
    }
  }
  cout << "Maximo de comparações atingidas: " << maxIteration; 
  return -1;
}