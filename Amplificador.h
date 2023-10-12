#include <iostream>
#include <string>
using namespace std;

class Amplificador{
    public: 
    Amplificador(double ganho);
    virtual ~Amplificador();
    Sinal* processar(Sinal* sinalIN);
    void setGanho(double ganho);
    double getGanho();

    private:
    double ganho;
};
