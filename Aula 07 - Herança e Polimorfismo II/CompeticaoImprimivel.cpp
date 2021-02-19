#include "CompeticaoImprimivel.h"

CompeticaoImprimivel::CompeticaoImprimivel(string nome, int maximoValor):
        Competicao(nome, maximoValor){

}

CompeticaoImprimivel::~CompeticaoImprimivel() {

}

void CompeticaoImprimivel::imprimir(){

    Competicao::imprimir();

    Equipe** equipesDaCompeticao = this->getEquipes();

    for(int i=0; i<this->getQuantidadeDeEquipes(); i++){
       cout << "\t";
       equipesDaCompeticao[i]->imprimir();
    }
}
