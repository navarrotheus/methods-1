#include <iostream>
#include <vector>
#include "polinomio.hpp"

void printPoly(vector<double> polynomial);

using namespace std;

double derivateCalculatePxHorner(vector<double> polynomial, double value);
double calculatePxHorner(vector<double> polynomial, double value);

void methodNewton(vector<double> polynomial, double chute, double erro, double maxIteration){
  clock_t start, end;
  start = clock();

  double Px, DerivatePx;
  Px = calculatePxHorner(polynomial, chute);
  double var = chute;
  if (abs(Px) > erro){
    DerivatePx = derivateCalculatePxHorner(polynomial, chute);
    for(int i=0; i<maxIteration; i++){

      cout << "//////////////////////////////////////////////////" << "\n";
      cout << "Passo: " << i << "\n"; 
      cout << "Valor do X: " << var << "\n";
      cout << "Valor do P(x):" << Px << "\n";
      cout << "Valor da derivada: " << DerivatePx << "\n";
      cout << "//////////////////////////////////////////////////" << "\n \n";

      var = var -1*(Px/DerivatePx);
      Px = calculatePxHorner(polynomial, var);
      if(abs(Px) <= erro){
        end = clock();
        cout << " \n" << "Tempo de execução: " << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
        printPoly(polynomial);
        cout << "Deu certo com: " << i+1 << " repetições" << "\n";
        cout << "Valor da Raiz: " << var << "\n";
        cout << "Valor do P(x): " << Px << "\n";
        cout << "Valor da derivadaP(x): " << DerivatePx << "\n";
        return;
      }
      DerivatePx = derivateCalculatePxHorner(polynomial, var);
    }
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
    cout << "Não deu em nada \n";
    cout << "Raiz mais proxima: " << var << "\n";
  }
  else {
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";    
    cout << "Chutou muito bem \n";
    cout << "Raiz: " << chute << "\n";
    cout << Px;
  }
}

double calculatePxHorner(vector<double> polynomial, double value){
  return ( ( (polynomial[8]*value + polynomial[6])*value + polynomial[4])*value + polynomial[2])*value + polynomial[0];
}

double derivateCalculatePxHorner(vector<double> polynomial, double value){
  return ( ( (polynomial[7]*value+polynomial[5])*value + polynomial[3])*value + polynomial[1]);
}