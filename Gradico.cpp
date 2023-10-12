#include "Grafico.h"

const int Grafico::rows = 16;
const int Grafico::maxY = 10;
const int Grafico::maxX = 61;
const int Grafico::bordaEsquerda = 10;
const int Grafico::bordaDireita = 5;
const char Grafico::pontoSuperior = '\'';
const char Grafico::pontoInferior = '.';
const int Grafico::gapX = 6; // a cada quantas colunas há um valor do eixo X
const int Grafico::gapY = 5; // a cada quantas linhas há um valor do eixo Y
constexpr double Grafico::escalaY = double(maxY)/(rows-1);

Grafico::Grafico(string titulo, double *sequencia, int comprimento): titulo(titulo), sequencia(sequencia), comprimento(comprimento) {
  if (comprimento <= 0) {
    throw new invalid_argument("Comprimento deve ser maior que zero");
  }
  columns = min<int>(comprimento, this->maxX);
}

Grafico::~Grafico() {
}

void Grafico::impressaoDaPrimeiraLinha() {
  // ***********Primeira Linha***************
  string iniciodaPrimeiraLinha = string(bordaEsquerda, ' ');
  string meioDaPrimeiraLinha("^     ");
  // Impressão da primeira linha
  cout << iniciodaPrimeiraLinha << meioDaPrimeiraLinha << titulo << endl;
}

void Grafico::impressaoDoCorpo() {
  string *inicioDaLinha = getInicioDaLinhaDoCorpo();
  string *meioDaLinha = getMeioDaLinhaDoCorpo();
  string *finalDaLinha = getFinalDaLinhaDoCorpo();
  for (int i = rows - 1; i >= 0 ; i--) {
      cout << inicioDaLinha[i] << meioDaLinha[i] << finalDaLinha[i] << endl;
  }
  delete[] inicioDaLinha;
  delete[] meioDaLinha;
  delete[] finalDaLinha;
}

void Grafico::impressaoDasUltimasLinhas() {
  string inicioDasUltimasLinhas[3];
  // Inicialização
  inicioDasUltimasLinhas[0] = string(bordaEsquerda, ' ');
  inicioDasUltimasLinhas[1] = string(bordaEsquerda, ' ');
  string meioDasUltimasLinhas[2];
  for (int i = 0; i < 2; i++) {
      meioDasUltimasLinhas[i] = string(columns+1, ' ');
  }
  // Preechimento com os índices
  for (int j = 0; j < columns; j+=gapX) {
      char buffer[3];
      sprintf(buffer, "%.2d", j);
      string bufferStr(buffer);
      meioDasUltimasLinhas[0].replace(j, 2, bufferStr.substr(0,2));
      meioDasUltimasLinhas[1].replace(j, 1, "|");
  }
  // Impressao das ultimas linhas
  cout << inicioDasUltimasLinhas[1] << meioDasUltimasLinhas[1] << endl;
  cout << inicioDasUltimasLinhas[0] << meioDasUltimasLinhas[0] << endl;
}

string* Grafico::getInicioDaLinhaDoCorpo() {
  // Inicializacao
  string *inicioDaLinha = new string[rows];
  for (int i = 0; i < rows; i++) {
      inicioDaLinha[i] = string(bordaEsquerda, ' ');
  }
  // Preechimento com os índices
  for (int i = 0; i < rows; i+=gapY) {
      ostringstream buffer;
      buffer << setprecision(1) << setw(5) << fixed << right << i*escalaY << "_";
      inicioDaLinha[i].replace(bordaEsquerda-6, 6, buffer.str());
  }
  return inicioDaLinha;
}

string* Grafico::getMeioDaLinhaDoCorpo() {
  // **********Matriz do Grafico*************
  string *meioDoCorpo = new string[rows];
  // Inicializacao
  for (int i = 0; i < rows; i++) {
      meioDoCorpo[i] = string(columns, ' ');
  }
  for (int i = 0; i < rows; i++) {
      meioDoCorpo[i].replace(0, 1, "|");
  }
  for (int j = 0; j < columns; j++) {
      meioDoCorpo[0].replace(j, 1, "_");
  }
  // Preenchimento com os valores
  for (int j = 0; j < columns; j++) {
      if (this->sequencia[j] <= 0) {
          meioDoCorpo[0].replace(j, 1, string({pontoInferior}));       
      } else if (this->sequencia[j] >= escalaY * (rows-1)) {
          meioDoCorpo[rows-1].replace(j, 1, string({pontoSuperior}));       
      } else {
          int coordenadaAbaixo = int(this->sequencia[j] / escalaY);
          int coordenadaAcima = int(this->sequencia[j] / escalaY + 0.5);
          if (coordenadaAcima==coordenadaAbaixo) {
              meioDoCorpo[coordenadaAbaixo].replace(j, 1, string({pontoInferior}));
          } else {
              meioDoCorpo[coordenadaAbaixo].replace(j, 1, string({pontoSuperior}));
          }
      } 
  }
  return meioDoCorpo;

}

string* Grafico::getFinalDaLinhaDoCorpo() {
  // Inicializacao
  string *finalDaLinha = new string[rows];
  for (int i = 0; i < rows; i++) {
      finalDaLinha[i] = string(bordaDireita, ' ');
  }
  // Preechimento com o relevante
  finalDaLinha[0].replace(0,4,"___>");
  return finalDaLinha;
}

void Grafico::plot() {
  impressaoDaPrimeiraLinha();
  impressaoDoCorpo();
  impressaoDasUltimasLinhas();
}
