#ifndef EQUIPE_H
#define EQUIPE_H
#include <string>
#include <iostream>
#include "Participante.h"
#include "Pessoa.h"

using namespace std;

class Equipe : public Participante {
public:
    Equipe(string nome, int maxValor);
    virtual ~Equipe();

    virtual bool adicionar(Pessoa* p);
    virtual Pessoa** getPessoas();
    string getNome();


private:
    string nome;
    int maxValor;
    int quantidade;
    Pessoa** pessoas;
};

#endif // EQUIPE_H
