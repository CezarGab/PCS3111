#include "Equipe.h"

Equipe::Equipe(string nome) :
    nome(nome){
}

Equipe::~Equipe() {
}

string Equipe::getNome() {
    return nome;
}
