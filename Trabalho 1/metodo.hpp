#include <iostream>
#include <vector>

using namespace std;

double derivateCalculatePxHorner(vector<double> polynomial, double value);
double calculatePxHorner(vector<double> polynomial, double value);

void methodNewton(vector<double> polynomial, double chute, double erro, double maxIteration){
  double Px, DerivatePx;
  Px = calculatePxHorner(polynomial, chute);
  double var = chute;
  if (abs(Px) > erro){
    DerivatePx = derivateCalculatePxHorner(polynomial, chute);
    for(int i=0; i<maxIteration; i++){
      cout << "Valor do X: " << var << " //// Valor do P(x):" << Px << "\n";
      var = var -1*(Px/DerivatePx);
      Px = calculatePxHorner(polynomial, var);
      if(abs(Px) <= erro){
        cout << "Deu certo com: " << i+1 << " repetições" << "\n";
        cout << "O valor da raiz é: " << var << "Valor do P(x):" << Px << "\n";
        return;
      }
      DerivatePx = derivateCalculatePxHorner(polynomial, var);
    }
    cout << "Não deu em nada \n";
    cout << "Raiz mais proxima: " << var << "\n";
  }
  else {
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