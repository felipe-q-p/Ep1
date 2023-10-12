#include <iostream>
#include "Sinal.h"
#include "Grafico.h"
#include <string>

int main(){
    double *sequencia = new double[9];
    sequencia[0] = 1;
    sequencia[1] = 2.3;
    sequencia[2] = 3.14159265;
    sequencia[3] = 1;
    sequencia[4] = 2.3;
    sequencia[5] = 3.14159265;
    sequencia[6] = 1;
    sequencia[7] = 2.3;
    sequencia[8] = 3.14159265;
    string nomeDoSinal = "abcd";
    int comprimento = 9;
    Sinal *sinal = new Sinal(sequencia, comprimento);
    sinal -> imprimir(nomeDoSinal);
    cout << sinal -> getSequencia()[1] << endl;
    return 0;
}
