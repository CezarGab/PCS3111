#include "Historico.h"

Historico::Historico(int maximoValor) :
maximoValor(maximoValor) {
    quantidade = 0;
    competicoes = new Competicao*[maximoValor];
}

Historico::~Historico() {
}

int Historico::getQuantidade() {
    return quantidade;
}

bool Historico::adicionar(Competicao* c) {
    if(quantidade >= maximoValor) return false;
    for(int i = 0; i < quantidade; i++)
        if(c == competicoes[i]) return false;
    competicoes[quantidade] = c;
    quantidade++;
    return true;
}

Competicao** Historico::getCompeticoes() {
    return competicoes;
}

Competicao** Historico::getCompeticoesImprimiveis(int& tamanho){
    Competicao* competicoesImprimiveis[maximoValor];
    int quantidade = 0;

    for(int i = 0; i < this->getQuantidade() ; i++){

        CompeticaoImprimivel *competicaoEmAnalise = dynamic_cast<CompeticaoImprimivel*>(competicoes[i]);

        if(competicaoEmAnalise != NULL){
            competicoesImprimiveis[quantidade] = competicaoEmAnalise;
            quantidade++;
        }
    }

    if(quantidade == 0){
        tamanho = 0;
        return NULL;
    }

    tamanho = quantidade;
    return competicoesImprimiveis;

    //Caso o Historico não possua CompeticaoImprimivel,
    // deve-se retornar NULL e o tamanho deve ser 0.
}
