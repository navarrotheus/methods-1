#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

double calculateKick(vector<double> funcao){
  double res = funcao[0];
  for(int i=0; i<4; i++){
    res = res + funcao[(i+1)*2];
  }
  return res/2;
}
