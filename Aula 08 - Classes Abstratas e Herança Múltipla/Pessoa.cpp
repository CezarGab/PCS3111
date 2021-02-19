#include "Pessoa.h"

int Pessoa::nuspAuto = 12345678;

Pessoa::Pessoa(string nome, int nusp) : Participante(nome), nusp(nusp)
{
    this->nome = nome;
    this->nusp = nusp;

    //ctor
}

Pessoa::Pessoa(string nome) : Participante(nome)
{
   this->nome = nome;
   this->nusp = getNuspAuto();
   Pessoa::nuspAuto++;
}


Pessoa::~Pessoa()
{
    //dtor
}

int Pessoa::getNusp(){
    return nusp;

}
string Pessoa::getNome(){
    return nome;
}

int Pessoa::getNuspAuto(){
    return Pessoa::nuspAuto;
}
