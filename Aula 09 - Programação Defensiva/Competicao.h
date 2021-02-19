#ifndef COMPETICAO_H
#define COMPETICAO_H
#include "Modalidade.h"

class Competicao {
public:
    Competicao(string nome, int maximoValor);
    virtual ~Competicao();

    int getQuantidadeDeEquipes();
    int getQuantidadeDeModalidades();
    Equipe** getEquipes();
    Modalidade** getModalidades();

    bool adicionar(Equipe* e);
    bool adicionar(Modalidade* m);

    virtual void imprimir();
protected:
    string nome;
    int quantidadeDeEquipes;
    int quantidadeDeModalidades;
    int maximoValor;
    Equipe** equipes;
    Modalidade** modalidades;
};

#endif // COMPETICAO_H
