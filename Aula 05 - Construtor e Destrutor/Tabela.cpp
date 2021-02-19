#include "Tabela.h"

using namespace std;

// Implemente o construtor e o destrutor

// NAO altere os demais metodos

Tabela::Tabela(Equipe** participantes, int quantidade){
    int i;
    int *pontos = new int[quantidade];

    this->participantes = participantes;
    this->quantidade = quantidade;

    for(i=0; i<quantidade; i++){
        pontos[i]=0;
    }

    this->pontos = pontos;
}

Tabela::~Tabela(){
    for(int i = 0; i < quantidade; i++){
        delete participantes[i];
    }

    delete pontos;
    cout << "Tabela com " << quantidade << "equipe(s) destruida" << endl;

//     todas as equipes contidas nessa Tabela devem ser destruídas, assim como o vetor de pontos

}


int Tabela::getIndice(Equipe* participante) {
    for (int i = 0; i < this->quantidade; i++) {
        if (this->participantes[i] == participante) {
            return i;
        }
    }
    return -1;
}

Equipe** Tabela::getParticipantes() const {
    return this->participantes;
}

int Tabela::getQuantidade() {
    return this->quantidade;
}

void Tabela::pontuar(Equipe* participante, int pontos) {
    int indice = getIndice(participante);
    if (indice != -1)
        this->pontos[indice] += pontos;
}

int Tabela::getPontos(Equipe* participante) {
    int indice = getIndice(participante);
    if (indice == -1)
        return -1;
    return this->pontos[indice];
}

void Tabela::imprimir() {
    cout << "Tabela com " << this->quantidade << " equipe(s)" << endl;
    for (int i = 0; i < quantidade; i++){
        participantes[i]->imprimir();
    }
}
