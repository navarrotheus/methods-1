//METODO DE NEWTON PARA POLINOMIOS

#include <iostream>
#include <vector>
#include "polinomio.hpp"

using namespace std;

//Funcao declarada em polinomio.hpp
void printPoly(vector<double> polynomial);
//Funcoes declaradas nesse arquivo
void methodNewton(vector<double> polynomial, double chute, double erro, double maxIteration);
double derivateCalculatePxHorner(vector<double> polynomial, double value);
double calculatePxHorner(vector<double> polynomial, double value);
//Metodo de Newton para polinomios
void methodNewton(vector<double> polynomial, double chute, double erro, double maxIteration){
  //Calcula o tempo de execucao
  clock_t start, end;
  start = clock();
  //Variaveis para armazenar os calulos
  double Px, DerivatePx, var = chute;
  Px = calculatePxHorner(polynomial, var);
  //Verifica se o chute foi muito bom
  if (abs(Px) > erro){ //Se for maior
    DerivatePx = derivateCalculatePxHorner(polynomial, chute);
    //Comeco dos passos ate o numero maximo de interacoes
    for(int i=0; i<maxIteration; i++){
      //Prints do passo atual
      cout << "//////////////////////////////////////////////////" << "\n";
      cout << "Passo: " << i << "\n"; 
      cout << "Valor do X: " << var << "\n";
      cout << "Valor do P(x):" << Px << "\n";
      cout << "Valor da derivada: " << DerivatePx << "\n";
      cout << "//////////////////////////////////////////////////" << "\n \n";
      //Realiza o calculo do Metodo
      var = var -1*(Px/DerivatePx);
      Px = calculatePxHorner(polynomial, var);
      //Verifica a condicao de parada
      if(abs(Px) <= erro){ //Se estiver menor do que o erro
        //Calculo do tempo de execucao
        end = clock();
        cout << " \n" << "Tempo de execução: " << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
        //Prits das informacoes obtidas
        printPoly(polynomial);
        cout << "Deu certo com: " << i+1 << " repetições" << "\n";
        cout << "Valor da Raiz: " << var << "\n";
        cout << "Valor do P(x): " << Px << "\n";
        cout << "Valor da derivadaP(x): " << DerivatePx << "\n";
        return;
      }
      //Realiza o passo do metodo 
      DerivatePx = derivateCalculatePxHorner(polynomial, var);
    }
    //Calculo do tempo de execucao
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
    //Caso atinja o maximo de passos estabelecidos e nao foi possivel atingir uma raiz com um erro aceitavel
    cout << "Não deu em nada \n";
    cout << "Raiz mais proxima: " << var << "\n";
  }
  else {
    //Calculo do tempo de execucao
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";    
    //Caso o chute seja muito certeiro
    cout << "Chutou muito bem \n";
    cout << "Raiz: " << chute << "\n";
    cout << "Valor do P(x): " << Px;
  }
  return;
}
//Utiliza o metodo de Horner para estruturar as multiplicacoes
double calculatePxHorner(vector<double> polynomial, double value){
  return ( ( (polynomial[8]*value + polynomial[6])*value + polynomial[4])*value + polynomial[2])*value + polynomial[0];
}
//Utiliza o metodo de Horner para estruturar as multiplicacoes
double derivateCalculatePxHorner(vector<double> polynomial, double value){
  return ( ( (polynomial[7]*value+polynomial[5])*value + polynomial[3])*value + polynomial[1]);
}