#ifndef MODULO_H
#define MODULO_H

#include <iostream>
#include <string>
#include "Sinal.h"

using namespace std;


class ModuloRealimentado {
    public:
        ModuloRealimentado(double ganho);
        virtual ~ModuloRealimentado();
        Sinal* processar(Sinal* sinalIN);

    private:
       double ganho;
};

#endif