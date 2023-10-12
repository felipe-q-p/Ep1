#include <iostream>
#include <string>
#include "Sinal.h"
#include "Grafico.h"
#include "Amplificador.h"

Amplificador::Amplificador(double ganho){
    setGanho(ganho);
}

void Amplificador::setGanho(double ganho){
    this -> ganho = ganho;
}

double Amplificador::getGanho(){
    return ganho;
}

Amplificador::~Amplificador(){
}

Sinal* Amplificador::processar(Sinal* sinalIN){
    int comprimentoOUT = sinalIN->getComprimento();
    double *sequenciaOUT = new double[comprimentoOUT];
    for (int i  = 0; i < comprimentoOUT; i++){
        sequenciaOUT[i] = (sinalIN -> getSequencia())[i]*ganho;
        /*cout <<  sequenciaOUT[i] << endl;*/
    }
    Sinal* sinalOUT = new Sinal(sequenciaOUT, comprimentoOUT);
    return sinalOUT;
}
