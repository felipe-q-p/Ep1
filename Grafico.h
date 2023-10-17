#ifndef GRAFICO_H
#define GRAFICO_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Grafico {
private:
  static const int rows;
  static const int maxY;
  static const int maxX;
  static const int bordaEsquerda;
  static const int bordaDireita;
  static const char pontoSuperior;
  static const char pontoInferior;
  static const int gapX;
  static const int gapY;
  static const double escalaY;

  string titulo;
  double *sequencia;
  int comprimento;
  int columns = 0;

  void impressaoDaPrimeiraLinha();
  void impressaoDoCorpo();
  void impressaoDasUltimasLinhas();
  
  string* getInicioDaLinhaDoCorpo(); 
  string* getMeioDaLinhaDoCorpo(); 
  string* getFinalDaLinhaDoCorpo();

public:
  Grafico(string titulo, double *sequencia, int comprimento);
  virtual ~Grafico();
  void plot();
  
};

#endif // GRAFICO_H