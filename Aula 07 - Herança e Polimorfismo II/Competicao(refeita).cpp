#include "Competicao.h"

Competicao::Competicao(string nome, int maximoValor) :
nome(nome), maximoValor(maximoValor) {
    quantidadeDeEquipes = 0;
    quantidadeDeModalidades = 0;
    equipes = new Equipe*[maximoValor];


    modalidades = new Modalidade*[maximoValor];
}

Competicao::~Competicao() {
    delete[] equipes;
}

int Competicao::getQuantidadeDeEquipes() {
    return quantidadeDeEquipes;
}

int Competicao::getQuantidadeDeModalidades() {
    // Implemente o metodo
    return quantidadeDeModalidades;
}

Equipe** Competicao::getEquipes() {
    return equipes;
}

Modalidade** Competicao::getModalidades() {
    // Implemente o metodo
    return modalidades;
}

bool Competicao::adicionar(Equipe* e) {
    if(quantidadeDeEquipes >= maximoValor) return false;
    for(int i = 0; i < quantidadeDeEquipes; i++) {
        if(equipes[i] == e) return false;
    }
    equipes[quantidadeDeEquipes] = e;
    quantidadeDeEquipes++;
    return true;
}

bool Competicao::adicionar(Modalidade* m) {
    if(quantidadeDeModalidades >= maximoValor) return false;

    for(int i = 0; i < quantidadeDeModalidades; i++) {
        if(modalidades[i] == m) return false;


        Equipe** equipesDaModalidade = modalidades[i]->getEquipes();
        Equipe** equipesDaCompeticao = this->getEquipes();

        bool equipeJaCadastrada;

        for(int j = 0; j < modalidades[i]->getQuantidade(); i++){
            equipeJaCadastrada = false;
            for(int z = 0; z < this->getQuantidadeDeEquipes(); z++){
                if(equipesDaModalidade[j] == equipesDaCompeticao[z]){
                    bool equipesJaCadastrada = true;
                }

                if(equipeJaCadastrada == false){
                    return false;
                }
            }

        }
    }

    modalidades[quantidadeDeModalidades] = m;
    quantidadeDeModalidades++;
    return true;


}

void Competicao::imprimir() {
    cout << "Competicao " << nome << endl;
}
