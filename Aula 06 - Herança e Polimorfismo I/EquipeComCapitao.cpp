#include "EquipeComCapitao.h"
#include <iostream>
#include <string.h>

using namespace std;

// Implemente aqui os metodos

EquipeComCapitao::EquipeComCapitao(string nome, int membros, string nomeCapitao) : Equipe(nome, membros)
{
    this->nome = nome;
    this->membros = membros;
    this->nomeCapitao = nomeCapitao;
}

EquipeComCapitao::~EquipeComCapitao()
{
    cout << "Equipe com Capitao " << getNomeCapitao() << " destruida" << endl;

}

string EquipeComCapitao::getNomeCapitao(){
    return nomeCapitao;
}
