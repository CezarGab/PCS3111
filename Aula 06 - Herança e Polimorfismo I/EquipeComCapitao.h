// Adicione aqui as diretivas de compilacao necessarias

#ifndef EQUIPECOMCAPITAO_H
#define EQUIPECOMCAPITAO_H
#include "Equipe.h"
#include <iostream>
#include <string.h>
using namespace std;

class EquipeComCapitao : public Equipe {
private:
    string nome;
    int membros;
    string nomeCapitao;

public:
    EquipeComCapitao(string nome, int membros, string nomeCapitao);
    ~EquipeComCapitao();

    string getNomeCapitao();
};

#endif // EQUIPECOMCAPITAO_H
