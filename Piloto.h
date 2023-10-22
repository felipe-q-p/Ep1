#ifndef PILOTO_H
#define PILOTO_H

#include <iostream>
#include <string>
#include "Sinal.h"
using namespace std;

class Piloto{
    public:
    Piloto(double ganho);
    virtual ~Piloto();
    Sinal* processar(Sinal* sinalIN);

    private:
    double ganho;
};


#endif