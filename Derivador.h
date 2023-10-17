#ifndef DERIVADOR_H
#define DERIVADOR_H

#include <iostream>
#include <string>
using namespace std;

class Derivador{
    public:
    Derivador();
    virtual ~Derivador();
    Sinal* processar(Sinal* sinalIN1);
};


#endif