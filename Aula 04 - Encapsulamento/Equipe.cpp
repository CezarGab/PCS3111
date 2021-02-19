#include "Equipe.h"
#include <iostream>

string Equipe::getNome() {
    return nome;
}

int Equipe::getNumeroDeMembros() {
    return numeroDeMembros;
}

void Equipe::setNome(string nome) {
    this->nome = nome;
}

void Equipe::setNumeroDeMembros(int membros) {
    numeroDeMembros = membros;
}

int Equipe::getMaximoDeTorcedores() {
    return (15 + 25 * numeroDeMembros);
}

void Equipe::imprimir() {
    cout << nome << " - " << numeroDeMembros << " membros" << endl;
}

