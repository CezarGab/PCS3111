#include <iostream>
#include <string>
#include "Fila.h"
#define DELETED

using namespace std;

// Construtor
Fila::Fila(int tamanho) :tamanho (tamanho - 1) { // Tamanho recebe tamanho - 1 pois o início é em 0
    this->fila = new Datagrama*[tamanho];
    this->inicio = 0;
    this->fim = 0;
    for (int i = 0; i < tamanho; i++) {
        this->fila[i] = NULL;
    }
}
// Destrutor
Fila::~Fila() {
   cout << "Fila destruida" << endl; // Teste apenas
}

// Gets
int Fila::getTamanho() { // Recupera o atributo tamanho da fila
    return this->tamanho;
}

int Fila::getInicio() { // Recupera o atributo inicio da fila
    return this->inicio;
}
int Fila::getFim() { // Recupera o atributo fim da fila
    return this->fim;
}

// Sets
void Fila::setFim(int posicao) { // Altera o atributo fim da fila
    this->fim = posicao;
}

void Fila::setInicio(int posicao) {
    this->inicio = posicao;
}

// Enqueue - adiciona um datagrama no fim da lista
bool Fila::enqueue(Datagrama* d) {
    if (this->getInicio() == this->getFim()) { // Checando se o fim é igual ao começo
        if (this->isEmpty() == true) {  // Checa se a lista está vazia
            this->fila[this->getFim()] = d;
            if (this->getFim() == this->getTamanho()) {
                this->setFim(0);
            }
            else { // Lista cheia
                this->setFim(this->getFim() + 1);
                return true;
            }
        }
        else {
            // Caso overflow
            return false;
        }
    }
    else { // Caso em que o fim é diferente do começo
        this->fila[this->getFim()] = d;
        if (this->getFim() == this->getTamanho()) {
            this->setFim(0);
            return true;
        }
        else {
            this->setFim(this->getFim() + 1);
            return true;
        }

    }
}

// Checa se a lista está vazia
bool Fila::isEmpty() {
    int contador = 0;
    for (int i = 0; i < this->getTamanho(); i++) {
        if(this->fila[i] == NULL) { //|| this->fila[i] == DELETED (Pensando em uma maneira de como marcar a posição com excluída)
            contador ++;
        }
    }
    if(contador == this->getTamanho()) {
        // Fila vazia
        return true;
    }
    else {
        // Fila contém algo
        return false;
    }

}

Datagrama* Fila::dequeue() {
    if (this->isEmpty() == true) { // Checa se a fila está vazia (underflow), retorna NULL se estiver
        return NULL;
    }
    Datagrama* retirado = this->fila[this->getInicio()]; // Armazena o datagrama em uma variável
    this->fila[this->getInicio()] = NULL;
    if (this->getInicio() == this->getTamanho()) { //   Checa se o início está na última posição da lista,
        this->setInicio(0);                        // se estiver ele coloca o início na posição 0 [fila circular]
    }
    else {
        this->setInicio(this->getInicio() + 1); // Se não coloca na próxima posição
    }
    return retirado;

}



