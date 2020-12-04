#include "Rede.h"

Rede::Rede()
{
    nosDaRede = new vector<No*>();
    hospedeiroDaRede = new list<Hospedeiro*>();
    //ctor
}

Rede::~Rede()
{
    for(unsigned int i = 0; i < nosDaRede->size(); i++) { // "No destrutor destrua todos os Processos adcionados ao Hospedeiro."
            delete nosDaRede->at(i);
    }
    delete nosDaRede;
    //dtor
}

void Rede::adicionar(No* no) {

    for(unsigned int i = 0; i < nosDaRede->size(); i++) { // Percorre o vector de nós

        if(nosDaRede->at(i)->getEndereco() == no->getEndereco()) { // Compara o endereço dos nós do vector com o do que se deseja adicionar
            throw new logic_error("\tErro: tentativa de adicionar um no com endereco igual ao de outro ja adicionado");
        }

    }

    nosDaRede->push_back(no); // Adiciona o nós no fim do vetor

}

No* Rede::getNo(int endereco) {

    for(unsigned int i = 0; i < nosDaRede->size(); i++) { // Percorre o vector de nós

        if(nosDaRede->at(i)->getEndereco() == endereco) { // Compara o endereço dos nós do vector com endereco
            return nosDaRede->at(i);
        }

    }
    return NULL; // Se saiu do for, então não encontrou o nó

}

list<Hospedeiro*>* Rede::getHospedeiros() {

    for(unsigned int i = 0; i < nosDaRede->size(); i++) { // Percorre o vector de nós

        Hospedeiro* testaHospedeiro = dynamic_cast<Hospedeiro*>(nosDaRede->at(i));

        if(testaHospedeiro != NULL) {// Verifica se a conversão foi bem sucedida
            hospedeiroDaRede->push_back(testaHospedeiro); // Adiciona ao fim da lista o nos hospedeiro, caso seja
        }
    }
    return hospedeiroDaRede;
}

void Rede::passarTempo() {

    for(unsigned int i = 0; i < nosDaRede->size(); i++) { // Percorre o vector de nós
        nosDaRede->at(i)->processar(); // Chama o processar de cada nó
    }

}

void Rede::imprimir(){

}
