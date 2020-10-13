#include "Datagrama.h"

#ifndef FILA_H
#define FILA_H


class Fila
{
    private:
        int tamanho;
        int inicio;
        int fim;
        Datagrama** fila;
    public:
        Fila(int tamanho);
        ~Fila();

        bool enqueue(Datagrama* d);
        Datagrama* dequeue();
        bool isEmpty();

        void imprimir();


};

#endif // FILA_H
