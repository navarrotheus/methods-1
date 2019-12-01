#include <iostream>
#include <vector>
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
    
    
    */

    vector<vector<double>> A = {{1, -3, 2}, {-2, 8, -1}, {4, -6, 5}};

    Doolittle fatores(A, 3);
    vector<vector<double>> L = fatores.getLStep(2);
    vector<vector<double>> U = fatores.getUStep(2);

    cout << "Resultado de L:" << endl;

    cout << L[0][0] << " " << L[0][1] << " " << L[0][2] << endl;
    cout << L[1][0] << " " << L[1][1] << " " << L[1][2] << endl;
    cout << L[2][0] << " " << L[2][1] << " " << L[2][2] << endl; 

    cout << "Resultado de U:" << endl;

    cout << U[0][0] << " " << U[0][1] << " " << U[0][2] << endl;
    cout << U[1][0] << " " << U[1][1] << " " << U[1][2] << endl;
    cout << U[2][0] << " " << U[2][1] << " " << U[2][2] << endl; 

    return 0;

}