#include "Modalidade.h"

Modalidade::Modalidade(string nome, int maximoValor) :
nome(nome), maximoValor(maximoValor) {
    quantidade = 0;
    equipes = new Equipe*[maximoValor];
}

Modalidade::~Modalidade() {
    delete[] equipes;
}

bool Modalidade::adicionar(Equipe* e) {
    if (quantidade >= maximoValor) return false;
    else {
        for(int i = 0; i < quantidade; i++) {
            if(e == equipes[i]) return false;
        }
        equipes[quantidade] = e;
        quantidade++;
        return true;
    }
    return false;
}


string Modalidade::getNome() {
    return nome;
}

int Modalidade::getQuantidade() {
    return quantidade;
}

Equipe** Modalidade::getEquipes() {
    return equipes;
}
