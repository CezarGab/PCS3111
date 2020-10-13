#include <iostream>
#include <string>
#include "Fila.h"


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

// Enqueue - adiciona um datagrama no fim da lista
bool Fila::enqueue(Datagrama* d) {
    if (this->inicio == this->fim) { // Checando se o fim é igual ao começo
        if (this->isEmpty() == true) {  // Checa se a lista está vazia
            this->fila[this->fim] = d;
            if (this->fim == this->tamanho) {
                this->fim = 0;
                return true;
            }
            else { // Lista cheia
                this->fim += 1;
                return true;
            }
        }
        else {
            // Caso overflow
            return false;
        }
    }
    else { // Caso em que o fim é diferente do começo
        this->fila[this->fim] = d;
        if (this->fim == this->tamanho) {
            this->fim = 0;
            return true;
        }
        else {
            this->fim += 1;
            return true;
        }

    }
}

// Checa se a lista está vazia
bool Fila::isEmpty() {
    int contador = 0;
    for (int i = 0; i < this->tamanho; i++) {
        if(this->fila[i] == NULL) {
            contador ++;
        }
    }
    if(contador == this->tamanho) {
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
    Datagrama* retirado = this->fila[this->inicio]; // Armazena o datagrama em uma variável
    this->fila[this->inicio] = NULL;
    if (this->inicio == this->tamanho) { //   Checa se o início está na última posição da lista,
        this->inicio = 0;                        // se estiver ele coloca o início na posição 0 [fila circular]
    }
    else {
        this->inicio += 1; // Se não coloca na próxima posição
    }
    return retirado;

}



