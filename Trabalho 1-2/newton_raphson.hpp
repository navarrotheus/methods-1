#include <cmath>
#include <vector>
using namespace std;

//metodo geral newton raphson, entradas -> erro, chute, numero maximo de iteracoes e multiplicidade p
double newton_raphson(double e, double xk, double nMax, double p){
    double x; //raiz
    while (abs(Fx) > e)
    {
        x = xk - f(xk)/
    }
    
}

//calculo de x na fx, entradas -> vetor com os coeficientes do polinomio, o valor a ser aplicado na funcao e o grau da funcao
double normal_Fx(vector<double> coeficientesFx, double x, int grau){
    double res = 0; //resultado
    for (int i = 0; i < grau; i++)
    {
        res += coeficientesFx[i]*pow(x, i);
    }
    return res;  
}