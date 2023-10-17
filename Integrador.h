#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include <iostream>
#include <string>
using namespace std;

class Integrador{
    public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN1);
};


#endif