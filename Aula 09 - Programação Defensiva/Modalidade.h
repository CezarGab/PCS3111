#ifndef MODALIDADE_H
#define MODALIDADE_H
#include <iostream>
#include <stdexcept>
#include "Equipe.h"

using namespace std;

class Modalidade {
public:
    Modalidade(string nome, int maximoEquipes);
    virtual ~Modalidade();
    void adicionar(Equipe* e);

    string getNome();
    int getQuantidade();

    void imprimir();
private:
    string nome;
    int maximoEquipes;
    int quantidade;
    Equipe** equipes;
};

#endif // MODALIDADE_H
