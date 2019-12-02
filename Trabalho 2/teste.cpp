#include <iostream>
#include <vector>
#include "LUFactorization.hpp"

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
    vector<double> b = {11, -15, 29};
    
    PivotedLU P(A, b, 3);

    vector<vector<double>> L1 = P.getLStep(2);
    vector<vector<double>> U1 = P.getUStep(2);
    vector<double> X1 = P.getResult();

    cout << "Fatoração LU com pivotação:" << endl;

    cout << "Resultado de L:" << endl;

    cout << L1[0][0] << " " << L1[0][1] << " " << L1[0][2] << endl;
    cout << L1[1][0] << " " << L1[1][1] << " " << L1[1][2] << endl;
    cout << L1[2][0] << " " << L1[2][1] << " " << L1[2][2] << endl << endl;

    cout << "Resultado de U:" << endl;

    cout << U1[0][0] << " " << U1[0][1] << " " << U1[0][2] << endl;
    cout << U1[1][0] << " " << U1[1][1] << " " << U1[1][2] << endl;
    cout << U1[2][0] << " " << U1[2][1] << " " << U1[2][2] << endl << endl;

    cout << "Resultado Xi:" <<endl;
    for (int i = 0; i < 3; i++){
        cout << "X" << i << " = " << X1[i] << endl; 
    }

    cout << "Redução Doolittle:" << endl;

    Doolittle D(A, b, 3);

    vector<vector<double>> L2 = D.getLStep(2);
    vector<vector<double>> U2 = D.getUStep(2);
    vector<double> X2 = D.getResult();

    cout << "Resultado de L:" << endl;

    cout << L2[0][0] << " " << L2[0][1] << " " << L2[0][2] << endl;
    cout << L2[1][0] << " " << L2[1][1] << " " << L2[1][2] << endl;
    cout << L2[2][0] << " " << L2[2][1] << " " << L2[2][2] << endl << endl;

    cout << "Resultado de U:" << endl;

    cout << U2[0][0] << " " << U2[0][1] << " " << U2[0][2] << endl;
    cout << U2[1][0] << " " << U2[1][1] << " " << U2[1][2] << endl;
    cout << U2[2][0] << " " << U2[2][1] << " " << U2[2][2] << endl << endl;


    cout << "Resultado Xi:" <<endl;
    for (int i = 0; i < 3; i++){
        cout << "X" << i << " = " << X2[i] << endl; 
    }
    
    return 0;
}