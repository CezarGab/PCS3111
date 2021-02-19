#include "Modalidade.h"
#include <iostream>

int Modalidade::calculaTotalTorcida(){
    int i;
    int totalDeTorcedores = 0;

    if (this->qtd_equipe == 0){
        return -1;
    }

    for(i = 0; i < this->qtd_equipe; i++){
        totalDeTorcedores = totalDeTorcedores + this->equipes[i] -> getMaximoDeTorcedores();
    }

    return totalDeTorcedores;

}

bool Modalidade::adicionar(Equipe* e){

    if(qtd_equipe == NUMERO_MAXIMO_VALORES){
        return false;
    }

    equipes[qtd_equipe] = e;

    this->qtd_equipe++;

    return true;

}

string Modalidade::getNome(){
    return this->nome;
}



int Modalidade::getQuantidade(){
    return qtd_equipe;
}

void Modalidade::setNome(string nome){
    this->nome = nome;

}

/* DUVIDA: esse método deve imprimir para todas as modalidades??? */
void Modalidade::imprimir(){
    int i;

    cout << nome << " - " << this->calculaTotalTorcida() << " torcedores no maximo" << endl;

    for(i = 0; i<this->qtd_equipe; i++){
        this->equipes[i] -> imprimir();
    }


}


/*
 * Faca os includes e coloque a implementacao dos metodos aqui!
 */
