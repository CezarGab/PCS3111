#include <iostream>
#include <string>
#include "Fila.h"


using namespace std;

// Construtor
Fila::Fila(int tamanho) :tamanho (tamanho) { // Tamanho recebe tamanho - 1 pois o início é em 0
    fila = new Datagrama*[tamanho];
    inicio = 0;
    fim = 0;
    for (int i = 0; i < tamanho; i++) {
        fila[i] = NULL;
    }
}
// Destrutor
Fila::~Fila() {
   cout << "Fila destruida" << endl; // Teste apenas
}

// Enqueue - adiciona um datagrama no fim da lista
bool Fila::enqueue(Datagrama* d) {
    if (inicio == fim) { // Checando se o fim é igual ao começo
        if (this->isEmpty() == true) {  // Checa se a lista está vazia
            fila[fim] = d;
            if (fim == tamanho) {
                fim = 0;
                return true;
            }
            else { // Lista cheia
                fim += 1;
                return true;
            }
        }
        else {
            // Caso overflow
            return false;
        }
    }
    else { // Caso em que o fim é diferente do começo
        fila[fim] = d;
        if (fim == tamanho) {
            fim = 0;
            return true;
        }
        else {
            fim += 1;
            return true;
        }

    }
}

// Checa se a lista está vazia
bool Fila::isEmpty() {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if(fila[i] == NULL) {
            contador ++;
        }
    }
    if(contador == tamanho) {
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
    Datagrama* retirado = fila[inicio]; // Armazena o datagrama em uma variável
    fila[inicio] = NULL;
    if (inicio == tamanho) { //   Checa se o início está na última posição da lista,
        inicio = 0;                        // se estiver ele coloca o início na posição 0 [fila circular]
    }
    else {
        inicio += 1; // Se não coloca na próxima posição
    }
    return retirado;

}



