#include <iostream>
#include <string>
#include "Fila.h"

using namespace std;

// Construtor
Fila::Fila(int tamanho) :tamanho (tamanho) { // Tamanho recebe tamanho pois o in�cio � em 0
    fila = new Datagrama*[tamanho];
    inicio = 0;
    fim = 0;
    for (int i = 0; i < tamanho; i++) {
        fila[i] = NULL;
    }
}
// Destrutor
Fila::~Fila() {
   delete fila;
}

// Enqueue - adiciona um datagrama no fim da lista
void Fila::enqueue(Datagrama* d) { // >>>MESMA COISA DO EP1, mas usa exception

    if (inicio == fim) { // Checando se o fim � igual ao come�o
        if (this->isEmpty() == true) {  // Checa se a lista est� vazia
            fila[fim] = d;
            if (fim == tamanho - 1) {
                fim = 0;
            }
            else { // Lista cheia
                fim += 1;
            }
        }
        else {
            // Caso overflow
            throw new overflow_error("\tOverflow na fila");
        }
    }
    else { // Caso em que o fim � diferente do come�o
        if (fim == tamanho - 1) {
            fila[fim] = d;
            fim = 0;

        }
        else {
            fila[fim] = d;
            fim += 1;
        }

    }
}

// Checa se a lista est� vazia
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
        // Fila cont�m algo
        return false;
    }

}

Datagrama* Fila::dequeue() { //>>>MESMA COISA DO EP1, mas usa exception
    if (this->isEmpty() == true) { // Checa se a fila est� vazia (underflow), retorna NULL se estiver
        throw new underflow_error("\t Fila vazia (underflow)");
    }

    Datagrama* retirado = fila[inicio]; // Armazena o datagrama em uma vari�vel
    fila[inicio] = NULL;
    if (inicio + 1 == tamanho) { //   Checa se o in�cio est� na �ltima posi��o da lista,
        inicio = 0;                        // se estiver ele coloca o in�cio na posi��o 0 [fila circular]
    }
    else {
        inicio += 1; // Se n�o coloca na pr�xima posi��o
    }
    return retirado;

}

void Fila::imprimir() {
    for (int i = 0; i < 5; i++){
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



