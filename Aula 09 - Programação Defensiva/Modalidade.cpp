#include "Modalidade.h"
#include "EquipeRepetida.h"

Modalidade::Modalidade(string nome, int maximoEquipes) :
        nome(nome), maximoEquipes(maximoEquipes) {
    if(maximoEquipes <= 1 || nome == "") throw new invalid_argument("Nome vazio ou maximo de equipes incompativel");
    quantidade = 0;
    equipes = new Equipe*[maximoEquipes];
}

Modalidade::~Modalidade() {
    delete[] equipes;
}

void Modalidade::adicionar(Equipe* e) {
    if(quantidade >= maximoEquipes)
        throw new overflow_error("Vetor equipes cheio");

    for(int i = 0; i < quantidade; i++){
        if(equipes[i] == e){
            throw new EquipeRepetida("equipe repetida");
        }
    }

    equipes[quantidade] = e;
    quantidade++;
}


string Modalidade::getNome() {
    return nome;
}

int Modalidade::getQuantidade() {
    return quantidade;
}

void Modalidade::imprimir() {
    for(int i = 0; i < quantidade; i++) {
        equipes[i]->imprimir();
    }
}
