#include "Competicao.h"
#include <iostream>
#include <string.h>
using namespace std;

Competicao::Competicao(string nome, int maximoEquipes)
{
    qtdEquipes = 0;
    this->nome = nome;
    this->maximoEquipes = maximoEquipes;

    equipes = new Equipe*[maximoEquipes];
}

Competicao::~Competicao()
{
    delete this->equipes;
    cout << "Competicao destruida" << endl;
}

Equipe** Competicao::getEquipes(){
    return this->equipes;

}

int Competicao::getQuantidade(){
    return qtdEquipes;

}

bool Competicao::adicionar(Equipe* e){
     if(qtdEquipes > 0){
        if(qtdEquipes == maximoEquipes){
            return false;
        }

         for(int i=0; i<qtdEquipes; i++){
            if(e == equipes[i]){
                return false;
            }
        }
    }

    equipes[qtdEquipes] = e;
    qtdEquipes++;
    return true;

}

void Competicao::imprimir(){
    cout << "Competicao: " << nome << endl;
}
