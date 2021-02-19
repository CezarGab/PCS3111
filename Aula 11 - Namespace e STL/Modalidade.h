#ifndef MODALIDADE_H
#define MODALIDADE_H
#include <iostream>
#include "Equipe.h"

using namespace std;

class Modalidade {
public:
    Modalidade(string nome, int maximoValor);
    virtual ~Modalidade();
    bool adicionar(Equipe* e);

    string getNome();
    int getQuantidade();
    Equipe** getEquipes();
private:
    string nome;
    int maximoValor;
    int quantidade;
    Equipe** equipes;
};

#endif // MODALIDADE_H
