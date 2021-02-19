#include "Equipe.h"
#include <iostream>
#include <string.h>
using namespace std;


Equipe::Equipe(string nome, int membros){
    this->nome = nome;
    this->membros = membros;
}

Equipe::~Equipe(){
    cout << "Equipe " << nome << " destruida" << endl;
}

string Equipe::getNome() {
    return this->nome;
}

int Equipe::getMembros() {
    return this->membros;
}

void Equipe::imprimir() {
    cout << "Equipe " << this->nome << endl;
}
