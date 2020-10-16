#include <iostream>
#include <string>
#include "Fila.h"
#define TAMANHO_FILA 3


using namespace std;

// Construtor
Fila::Fila(int tamanho) :tamanho (tamanho) { // Tamanho recebe tamanho pois o início é em 0
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
            if (fim == tamanho - 1) {
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
        if (fim == tamanho - 1) {
            fila[fim] = d;
            fim = 0;
            return true;

        }
        else {
            fila[fim] = d;
            fim += 1;
            return true;
        }

    }

    /*
    if(inicio == fim) {
        // fila cheia
        if(this->isEmpty() == true) {
            fila[fim] = d;
            fim = fim + 1;
            return true;
        }
        else {
            return false;
        }
        //return false;
    }
    else {
        if(inicio != 0) {
            if(fim + 1 == tamanho) {
                fila[fim] = d;
                fim = 0;
                return true;
            }
            else {
                fila[fim] = d;
                fim = fim + 1;
                return true;
            }
        }
        else {
            if(fim + 1 != tamanho) {
                fila[fim] = d;
                fim = fim + 1;
                return true;
            }
            else {
                return false;
            }
        }


    }
    */
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
    if (inicio + 1 == tamanho) { //   Checa se o início está na última posição da lista,
        inicio = 0;                        // se estiver ele coloca o início na posição 0 [fila circular]
    }
    else {
        inicio += 1; // Se não coloca na próxima posição
    }
    return retirado;

}

void Fila::imprimir() {
    for (int i = 0; i < TAMANHO_FILA; i++){
        if(inicio == i) {
            if (fim == i) {
                cout << "\tItem "<< i + 1 << " " <<fila[i] << " inicio e fim" << endl;
            }
            else{
                cout << "\tItem "<< i + 1 << " " <<fila[i] << " inicio" << endl;
            }

        }
        else if (fim == i){
            cout << "\tItem "<< i + 1 << " " <<fila[i]  << " fim" << endl;
        }
        else {
            cout << "\tItem "<< i + 1 << " " <<fila[i] << endl;
        }

    }
}



