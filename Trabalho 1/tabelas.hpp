#include <iostream>
#include <vector>
#include<cmath>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
void alinhar(string nome, double max);
void bonito(double nome, int max);
void alinharPasso(string nome, double max);
void linha(double max);

void mountTable (vector<vector<double>> tabela){
// valor do X  //// valor Px //// valor da derivada
  double valorK = tabela[tabela.size()-1][0];
  int max;
  int pontilhado = to_string(tabela[0][1]).size() + to_string(tabela[0][2]).size() + to_string(tabela[0][3]).size() + 8 + to_string(valorK).size();
  linha(pontilhado);
  alinharPasso("K", valorK);
  cout << " |";
  alinhar("X", tabela[0][1]);
  alinhar("Px", tabela[0][2]);
  alinhar("Px'", tabela[0][3]);  
  for(int i=0; i < tabela.size(); i++){
    linha(pontilhado);
    for(int l=0; l < tabela[i].size(); l++){
      if (l==0){
        alinharPasso(to_string((int)round(tabela[i][l])), valorK);
      }
      else{
        max = to_string(tabela[0][l]).size() + 1;
        bonito(tabela[i][l], max);
      }
      cout << " | ";
    }
  }
  linha(pontilhado);
}

void bonito(double nome, int max){
  string novo = to_string(nome);
  int tam = novo.size();
  while(tam<max){
    novo = novo + " ";
    tam += 1;
  }
  cout << novo;
}

void alinharPasso(string nome, double max){
  int tam = nome.size();
  string novo;
  while(novo.size()+tam<to_string(max).size()-7){
    novo = novo + " ";
  }
  cout << nome << novo << "|";
}
void alinhar(string nome, double max){
  int tam = nome.size();
  string novo;
  while(novo.size()+tam<to_string(max).size()+2){
    novo = novo + " ";
  }

  cout << " " << nome << novo << "|";
}

void linha(double max){
  cout << "\n";
  for(int i=0; i<max; i++){
    cout <<"-";
  }
  cout << "\n";
}