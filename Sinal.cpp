#include <iostream>
#include <string>
#include "Sinal.h"
#include "Grafico.h"

Sinal::Sinal(double *sequencia, int comprimento){
    this -> sequencia = new double[comprimento];
    this -> sequencia = sequencia;
    this -> comprimento = comprimento;
}

Sinal::~Sinal(){

}

double* Sinal::getSequencia(){
    return sequencia;
}

int Sinal::getComprimento(){
    return comprimento;
}

void Sinal::imprimir(string nomeDoSinal){
    Grafico *grafico = new Grafico(nomeDoSinal, sequencia, comprimento);
    grafico -> plot();
}

