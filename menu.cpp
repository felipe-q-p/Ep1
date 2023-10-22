#include "Piloto.h"
#include "Amplificador.h"
#include "Sinal.h"
#include "Integrador.h"
#include "Somador.h"
#include "Derivador.h"
#include "ModuloRealimentado.h"
#include "math.h"

#include <string>
using namespace std;
#include <iostream>


int Simulink();
int qualEntrada();
double qualGanho();
int qualOperacao();
int oQueFazer();
Sinal* novoSinal();
void novaOperacao(Sinal *sinalIN);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



void menu() {

    int i; // retorno do simulink
    double a; // ganho

    i = Simulink(); // faz a primeira pergunta



    // PRIMEIRA OPCAO DO SIMULINK (quando escolhe o piloto automatico)
    if (i == 1){

        Sinal* sinalIN = novoSinal(); //cria um sinal de acordo com a preferencia (constante ou rampa etc)
        a = qualGanho();
        ModuloRealimentado* pilotoAutomatico = new ModuloRealimentado(a);
        pilotoAutomatico->processar(sinalIN); 
        sinalIN->imprimir("Velocidade do Carro"); // acionou o piloto automatico
        delete(sinalIN);
    }


    // SEGUNDA OPCAO DO SIMULINK (quando escolhe as proprias opcoes)
    if (i == 2){

        /*
        cout<< endl;
        cout << "entrou certo"<< endl;
        */
        
        Sinal* sinalIN = novoSinal(); //cria um sinal de acordo com a preferencia (constante ou rampa etc) 
        novaOperacao(sinalIN);
        delete(sinalIN);
    }

}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////




int Simulink(){
    int i; // inteiro para opçoes de simulação
    cout << "Simulink em C++" << endl;
    cout << "Qual simulacao voce gostaria de fazer?" << endl;
    cout << "1) Piloto Automatico" << endl;
    cout << "2) Sua propria sequencia de operacoes" << endl;

    cin >> i;
    return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int qualEntrada(){
    int j; // inteiro para opcoes de entrada
    

    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl;
    cout << "1) 5+3*cos(n*pi/8)" << endl;
    cout << "2) constante" << endl;
    cout << "3) rampa" << endl;

    cin >> j;
    return j;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

double qualGanho(){
    double a; // double para ganho

    cout << "Qual o ganho do acelerador?" << endl;
    cin >> a;
    return a;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int qualOperacao(){

    int operacao; 
    cout << "Qual operacao voce gostaria de fazer?" << endl;
    cout << "1) Amplificar" << endl;
    cout << "2) Somar" << endl;
    cout << "3) Derivar" << endl;
    cout << "4) Integrar" << endl;
    
    cin >> operacao;
    return operacao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int oQueFazer(){

    int oQueFazer;
    cout << "O que voce quer fazer agora?" << endl;
    cout<< "1) Realizar mais uma operacao no resultado" << endl;
    cout << "2) Imprimir o resultado para terminar" << endl;
    
    cin >> oQueFazer;
    return oQueFazer;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Sinal* novoSinal(){
    int i, j; // retornos do simulink e da entrada
    double a; // ganho

    j = qualEntrada();

        if (j == 1){
            
            double n = 0; // se necessario seu n
            cin >> n;

            double* sequencia = new double[60];
            for (int t=0; t<60; t++){
                sequencia[t] = 5+(3*cos(n*t*M_PI/8));
            }
            Sinal* sinalIN = new Sinal(sequencia,60);
            // criou o sinal da forma pedida

           return  sinalIN;
        }



        if (j == 2){
            double C = 0; // se necessario é a contante 
            cout << "Qual o valor dessa constante?" << endl;
            cin >> C;
            // guardou a contante
            
            double* sequencia = new double[60];
            for (int t=0; t<60; t++){
                sequencia[t] = C;
            }
            Sinal* sinalIN = new Sinal(sequencia,60);
            // criou o sinal da forma pedida

           return  sinalIN;
        }



        if (j == 3){
            double inc = 0; // se necessario é a inclinação
            cout << "Qual a inclinacao dessa rampa?" << endl;
            cin >> inc;
            // guardou a inclinacao

            double *sequencia = new double[60];
            for (int i = 0; i < 60; i++){
            sequencia[i] = sequencia[i-1] + inc;
        }
    
            Sinal* sinalIN = new Sinal(sequencia,60);
            // criou o sinal da forma pedida

            return sinalIN;
        } 

        double* sequencia = new double[60]; // so pra ele nao dar warning (ele retorna um sinal zerado se nao escolherem nenhuma das 3 opcoes)
        for (int t=0; t<60; t++){
            sequencia[t] = 0;
        }
        Sinal* sinalIN = new Sinal(sequencia,60);
        return sinalIN;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void novaOperacao(Sinal *sinalIN){
    int operacao; // qual operacao na simulacao do tipo 2
    double a; // ganho
    int Fazer; // como prosseguir depois de uma operacao efetuada

    operacao = qualOperacao();

    if (operacao == 1){
        a = qualGanho();
        Amplificador* amp = new Amplificador(a); // cria um aplificador para dazer a operacao
        sinalIN = amp->processar(sinalIN);
        delete(amp);
    }

    if (operacao == 2){
        Sinal* sinalIN2;
        cout << "Informe mais um sinal para ser somado." << endl; // cria um novo sinal para ser somado
        sinalIN2 = novoSinal();
        Somador* som = new Somador();
        sinalIN = som->processar(sinalIN, sinalIN2);  
        delete(som);
        delete(sinalIN2);
    }

    if (operacao == 3){
        Derivador* d = new Derivador();
        sinalIN = d->processar(sinalIN);
        delete(d);
    }

    if (operacao == 4){
        Integrador* i = new Integrador();
        sinalIN = i->processar(sinalIN);
        delete(i);
    }

    Fazer = oQueFazer(); // funcao para a pergunta final (fazer dnv ou terminar)

    if (Fazer == 1){
        novaOperacao(sinalIN);
    }

    if (Fazer == 2){
        sinalIN->imprimir("Resultado Final");
    }
}
