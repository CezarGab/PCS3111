#include "Equipe.h"

Equipe::Equipe(string nome, int membros): nome(nome), membros(membros) {
}

Equipe::~Equipe() {

}

string Equipe::getNome() {
    return nome;
}

int Equipe::getMembros() {
    return membros;
}

int Equipe::getMaximoDeTorcedores() {
    return (15 + 25*membros);
}

void Equipe::imprimir() {
    cout << "Equipe "<< nome << endl;
}
