#include <iostream>
#include <vector>
#include "LUFactorization.hpp"
#include "Doolittle.hpp"

using namespace std;

int main(){
    /*
    Teste com matriz (exemplo do slide):

    1 |-3 | 2 || 11
    -2| 8 |-1 ||-15
    4 |-6 | 5 || 29

    Saída L:

    1 | 0 | 0 |
    -2| 1 | 0 |
    4 | 3 | 1 |


    Saída U:

    1 |-3 | 2 ||
    0 | 2 | 3 ||
    0 | 0 |-12||

    Resultado Xi:
    
    X0 = 2
    X1 = -1
    X2 = 3

    */

    vector<vector<double>> A = {{1, -3, 2}, {-2, 8, -1}, {4, -6, 5}};
    
    LUFactorization fatores(A, 3);
    vector<vector<double>> L = fatores.getLStep(2);
    vector<vector<double>> U = fatores.getUStep(2);

    cout << "Fatoração LU:" << endl;

    cout << "Resultado de L:" << endl;

    cout << L[0][0] << " " << L[0][1] << " " << L[0][2] << endl;
    cout << L[1][0] << " " << L[1][1] << " " << L[1][2] << endl;
    cout << L[2][0] << " " << L[2][1] << " " << L[2][2] << endl;

    cout << "Resultado de U:" << endl;

    cout << U[0][0] << " " << U[0][1] << " " << U[0][2] << endl;
    cout << U[1][0] << " " << U[1][1] << " " << U[1][2] << endl;
    cout << U[2][0] << " " << U[2][1] << " " << U[2][2] << endl;

    vector<double> b = {11, -15, 29};

    vector<double> X = fatores.solucaoLU(L, U, b);

    cout << "Resultado Xi:" <<endl;
    for (int i = 0; i < 3; i++){
        cout << "X" << i << " = " << X[i] << endl; 
    }

    cout << "Redução Doolittle:" << endl;

    Doolittle D(A, 3);

    L = D.getLStep(2);
    U = D.getUStep(2);

    cout << "Resultado de L:" << endl;

    cout << L[0][0] << " " << L[0][1] << " " << L[0][2] << endl;
    cout << L[1][0] << " " << L[1][1] << " " << L[1][2] << endl;
    cout << L[2][0] << " " << L[2][1] << " " << L[2][2] << endl;

    cout << "Resultado de U:" << endl;

    cout << U[0][0] << " " << U[0][1] << " " << U[0][2] << endl;
    cout << U[1][0] << " " << U[1][1] << " " << U[1][2] << endl;
    cout << U[2][0] << " " << U[2][1] << " " << U[2][2] << endl;


    X = D.solucaoLU(L, U, b);

    cout << "Resultado Xi:" <<endl;
    for (int i = 0; i < 3; i++){
        cout << "X" << i << " = " << X[i] << endl; 
    }
    
    return 0;
}