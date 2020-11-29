#include "No.h"
#include "Fila.h"

No::No(int endereco) : endereco(endereco)
{
    fila = new Fila(TAMANHO_FILA); // criar a Fila com TAMANHO_FILA de tamanho
}

No::~No()
{
    delete fila;
}

Fila* No::getFila(){
    return fila; //  retornar a Fila criada no construtor
}

int No::getEndereco(){
    return endereco; // retornar o endereço informado no construtor
}

void No::receber(Datagrama* d){ // adiciona o Datagrama recebido como parâmetro na Fila do Roteador. Caso a
                                // fila estoure, não adiciona o Datagrama e imprime a mensagem
    try{
        fila->enqueue(d);

    } catch (overflow_error *erro){
        cout << "\tFila em " << endereco << " estourou." << endl; // overflow na fila do roteador
    }
}

void No::imprimir(){

}
