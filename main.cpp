#include <iostream>
#include "Sinal.h"
#include "Grafico.h"
#include <string>
#include "Amplificador.h"
#include "Somador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "Piloto.h"
#include "ModuloRealimentado.h"

void menu();

int main(){
    /*double *seqEntrada = new double[20];
    for (int i; i < 20; i++){
        seqEntrada[i] = 8;
    }
    Amplificador* amplificador = new Amplificador(0.3);
    Piloto* piloto = new Piloto(0.3);
    Sinal* sinalEntrada = new Sinal(seqEntrada, 60);
    sinalEntrada -> imprimir("sinal entrada");
    amplificador -> processar(sinalEntrada) -> imprimir("amplificador");*/
    /*piloto -> processar(sinalEntrada) -> imprimir("piloto");*/
    /*ModuloRealimentado* pilotoAutomatico = new ModuloRealimentado(0.3);
    pilotoAutomatico -> processar(sinalEntrada) -> imprimir("Nome do Sinal");*/

    /*menu();*/
    int numeroTeste1 = 27;
    int numeroTeste2 = 12;

    double *sequencia = new double[numeroTeste1];
    for (int i = 0; i < 27; i++){
        sequencia[i] = 5;
    }

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
    int comprimento = numeroTeste1;
    int comprimento2 = numeroTeste2;
    Sinal *sinal = new Sinal(sequencia, comprimento);
    sinal -> imprimir(nomeDoSinal);

    /*Amplificador *amplificador1 =  new Amplificador(0.3);
    amplificador1 -> processar(sinal) -> imprimir(nomeDoSinal);
    cout << amplificador1 -> processar(sinal) -> getSequencia()[1] << endl;*/

    Piloto* piloto = new Piloto(0.3);
    piloto -> processar(sinal) -> imprimir(nomeDoSinal);

   /* ModuloRealimentado* pilotoAutomatico = new ModuloRealimentado(0.3);
    pilotoAutomatico -> processar(sinal) -> imprimir("Nome do Sinal");*/


   /* Sinal *sinal2 = new Sinal(sequencia2, comprimento2);
    sinal2 -> imprimir(nomeDoSinal);
    Somador* somador1 = new Somador();
    somador1 -> processar(sinal, sinal2) -> imprimir(nomeDoSinal);
    Derivador* derivador1 = new Derivador();
    derivador1 -> processar(sinal2) -> imprimir(nomeDoSinal);
    Integrador* integrador1 = new Integrador();
    integrador1 -> processar(sinal2) -> imprimir(nomeDoSinal);
    */

    return 0;
}
