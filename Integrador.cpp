#include <iostream>
#include <string>
#include "Sinal.h"
#include "Grafico.h"
#include "Integrador.h"

Integrador::Integrador(){

}

Integrador::~Integrador(){

}

Sinal* Integrador::processar(Sinal* sinalIN){
    double* sequenciaInt = new double[sinalIN->getComprimento()];
    sequenciaInt[0] = sinalIN->getSequencia()[0];
    double soma = sequenciaInt[0];
    for (int i = 1;  i < sinalIN->getComprimento(); i++){
        soma += (sinalIN->getSequencia()[i]);
        cout << soma << endl;
        sequenciaInt[i] = soma;
    }
    Sinal* sinalIntegral = new Sinal(sequenciaInt, sinalIN -> getComprimento());
    return sinalIntegral;
}