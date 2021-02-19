// Inclua aqui as diretivas de compilacao necessarias

#ifndef COMPETICAO_H
#define COMPETICAO_H
#include "Equipe.h"
#include <iostream>
#include <string.h>

using namespace std;

class Competicao {
  protected:
    Equipe** equipes;
    string nome;
    int qtdEquipes;
    int maximoEquipes;

  public:
    Competicao(string nome, int maximoEquipes);
    ~Competicao();

    Equipe** getEquipes();
    int getQuantidade();
    bool adicionar(Equipe* e);

    void imprimir();
};

#endif // COMPETICAO_H
