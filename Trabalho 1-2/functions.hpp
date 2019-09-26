#include <iostream>
#include <vector>

using namespace std;

//vetor com os coeficientes -> entradas: grau da funcao
vector<double> coeficientesFx (int grau){
    vector<double> Fx (grau, 0);
    for (int i = 0; i < grau; i++){
        double valor;
        cout << "Entre os coeficientes do menor para o maior:" << "\n";
        cout << "Coeficiente " << i << ": \n";
        cin >> valor;
        Fx[i] = valor;
    }
    return Fx;
}

//vetor com os coeficientes da funcao derivada -> entradas: funcao f a ser derivada e seu grau
vector<double> coeficientesDerivadaFx (vector<double> Fx, int grau){
    vector<double> DerivadaFx (grau-1, 0);
    for (int i = 1; i < grau; i++)
    {
        DerivadaFx[i-1] = Fx[i]*i;
    }
    return DerivadaFx;
}

//metodo geral newton raphson, entradas -> ,erro, chute, numero maximo de iteracoes e multiplicidade p
double newton_raphson(vector<double> coeficientesFx, double e, double xk, double nMax, double p){
    double x; //raiz
    double c; //contador 
    while (abs(normal_Fx(xk)) > e || c <= nMax)
    {
        x = xk - f(xk)/
    }
    return x;
    
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

