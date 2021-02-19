#ifndef COMPETICAO_H
#define COMPETICAO_H
#include "Modalidade.h"
#include <stdexcept>
#include <vector>
#include <list>

// Faca os includes necessarios

using namespace std;

// Modifique SOMENTE a classe Competicao

class Competicao {
public:

    Competicao(string nome);
    ~Competicao();
    vector<Equipe*>* getEquipes();
    list<Modalidade*>* getModalidades();
    void adicionar(Equipe* e);
    void adicionar(Modalidade* m);

protected:
    string nome;
    vector<Equipe*>* equipesVetor;
    list<Modalidade*>* modalidades;
    int quantidadeDeEquipes;
};

#endif // COMPETICAO_H
