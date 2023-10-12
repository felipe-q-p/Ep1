#ifndef SINAL_H
#define SINAL_H
#include <iostream>
#include <string>
using namespace std;

class Sinal{
    private:
    double *sequencia;
    int comprimento;

    
    public:
    Sinal(double *sequencia, int comprimento);
    virtual ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
};

#endif
