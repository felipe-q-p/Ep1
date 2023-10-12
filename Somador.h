#ifndef SOMADOR_H
#define SOMADOR_H

#include <iostream>
#include <string>
using namespace std;

class Somador{
    public:
    Somador();
    virtual ~Somador();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);
};


#endif
