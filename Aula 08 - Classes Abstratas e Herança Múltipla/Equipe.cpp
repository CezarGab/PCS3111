#include "Equipe.h"

Equipe::Equipe(string nome, int maxValor) :
Participante(nome), nome(nome), maxValor(maxValor) {
    pessoas = new Pessoa*[maxValor];
}

Equipe::~Equipe() {
	delete[] pessoas;
}

bool Equipe::adicionar(Pessoa* p) {
    if(quantidade >= maxValor) return false;
    for(int i = 0; i < quantidade; i++) {
        if(pessoas[i] == p) return false;
    }
    pessoas[quantidade] = p;
    quantidade++;
    return true;
}

Pessoa** Equipe::getPessoas() {
    return pessoas;
}

string Equipe::getNome(){
    return nome;
}
