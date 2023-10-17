#include <iostream>
#include <string>
#include "Piloto.h"
#include "Amplificador.h"
#include "Sinal.h"
#include "Integrador.h"

Piloto::Piloto(double ganho){
    this -> ganho =  ganho;
}

Piloto::~Piloto(){

}

Sinal* Piloto::processar(Sinal* SinalIN){
    Amplificador* amp_interno = new Amplificador(ganho);
    Integrador* int_interno = new Integrador();
    Sinal* SinalOUT = new Sinal(SinalIN -> getSequencia(), SinalIN->getComprimento());
    SinalOUT = amp_interno -> processar(SinalIN);
    SinalOUT = int_interno -> processar(SinalIN);
    return SinalOUT;

}