#include <iostream>
#include <math.h>

using namespace std;

void DecimalBinario ( int x_dec ) { //função de conversão do valor x de decimal para binário
    int bin = 0; // o valor binario (resto da divisao)
    int c = 0; // contador
    int vetor[100]; // vetor para armazenar os valores binarios
    while ( x_dec != 0 ){
        bin = (x_dec % 2);
        x_dec /= 2;
        vetor[c] = bin;
        c++;
    }
    c--;
    while ( c != -1) // printando o vetor invertido
    {
        cout << vetor[c];
        c--;
    }
    
    
}

void BinarioDecimal ( int x_bin ) { //função de conversão do valor x de binário para decimal
    int x_dec = 0;
    int i = 0; //variável contador
    while ( x_bin != 0 ){
        x_dec += ( x_bin % 10 ) * pow(2,i);
        x_bin /= 10;
        i++;
    }
    cout << x_dec << "\n";
}

int main(){
    DecimalBinario(27);
    cout << "\n";
    BinarioDecimal(11011);
    return 0;
}
