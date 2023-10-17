#include <iostream>
#include "Sinal.h"
#include "Grafico.h"
#include <string>
#include "Amplificador.h"
#include "Somador.h"
#include "Derivador.h"
#include "Integrador.h"

int main(){
    int numeroTeste1 = 27;
    int numeroTeste2 = 12;

    double *sequencia = new double[numeroTeste1];
    sequencia[0] = -1;
    sequencia[1] = -2;
    sequencia[2] = -3;
    sequencia[3] = -5;
    sequencia[4] = -8;
    sequencia[5] = -13;
    sequencia[6] = -21;
    sequencia[7] = 2;
    sequencia[8] = 4;
    sequencia[9] = 2;
    sequencia[10] = 5;
    sequencia[11] = 3;
    sequencia[12] = 1;
    sequencia[13] = 2;
    sequencia[14] = -4;
    sequencia[15] = 1;
    sequencia[16] = 2;
    sequencia[17] = 3;
    sequencia[18] = 1;
    sequencia[19] = 3;
    sequencia[20] = -6;
    sequencia[21] = 11;
    sequencia[22] = -4;
    sequencia[23] = 1;
    sequencia[24] = 1;
    sequencia[25] = -1;
    sequencia[26] = 3;

    double *sequencia2 = new double[numeroTeste2];
    sequencia2[0] = 1;
    sequencia2[1] = 2;
    sequencia2[2] = 3;
    sequencia2[3] = 5;
    sequencia2[4] = 1;
    sequencia2[5] = 2;
    sequencia2[6] = 3;
    sequencia2[7] = 5;
    sequencia2[8] = 1;
    sequencia2[9] = 2;
    sequencia2[10] = 3;
    sequencia2[11] = 5;
    sequencia2[12] = 1;

    string nomeDoSinal = "abcd";
    /*int comprimento = numeroTeste1;*/
    int comprimento2 = numeroTeste2;
    /*Sinal *sinal = new Sinal(sequencia, comprimento);
    sinal -> imprimir(nomeDoSinal);*/

    /*Amplificador *amplificador1 =  new Amplificador(2);
    amplificador1 -> processar(sinal) -> imprimir(nomeDoSinal);
    cout << amplificador1 -> processar(sinal) -> getSequencia()[1] << endl;*/

    Sinal *sinal2 = new Sinal(sequencia2, comprimento2);
    sinal2 -> imprimir(nomeDoSinal);
    /*Somador* somador1 = new Somador();
    somador1 -> processar(sinal, sinal2) -> imprimir(nomeDoSinal);*/
    /*Derivador* derivador1 = new Derivador();
    derivador1 -> processar(sinal2) -> imprimir(nomeDoSinal);*/
    Integrador* integrador1 = new Integrador();
    integrador1 -> processar(sinal2) -> imprimir(nomeDoSinal);
    
    return 0;
}
