#include <iostream>
#include <string>
#include "Piloto.h"
#include "Amplificador.h"
#include "Sinal.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#include "Somador.h"

#define vInicial 0;

ModuloRealimentado::ModuloRealimentado(double ganho){
    this -> ganho =  ganho;
}

ModuloRealimentado::~ModuloRealimentado(){

}

 Sinal* ModuloRealimentado::processar(Sinal* sinalIN){
    
    Piloto* piloto = new Piloto(ganho);

    double sequenciaSinalInvertido[sinalIN -> getComprimento()]; 
    sequenciaSinalInvertido[0] = -vInicial;


    double sequenciaDiferenca[1]; 
    sequenciaDiferenca[0] = sinalIN->getSequencia()[0] + sequenciaSinalInvertido[0];
    Sinal* diferenca;
    diferenca = new Sinal(sequenciaDiferenca, 1);

    Sinal* saida = new Sinal(piloto -> processar(diferenca) -> getSequencia(), 1); 
    delete diferenca;

    for (int i; i < sinalIN -> getComprimento(); i++){
        sequenciaSinalInvertido[i] = -(saida -> getSequencia()[i-1]);
        Sinal* saidaInvertida = new Sinal(sequenciaSinalInvertido, i+1);
        Somador* somador = new Somador();
        Sinal* diferenca = new Sinal((somador -> processar(sinalIN, saidaInvertida)) -> getSequencia(), i+1);
        delete saida;
        Sinal* saida = new Sinal(piloto -> processar(diferenca) -> getSequencia(), i+1);
        delete saidaInvertida;
        delete diferenca;
    }
    delete sequenciaSinalInvertido;
    return saida;


    
    
    
    

    return 0;
 }