#ifndef FILA_H
#define FILA_H
#include "Datagrama.h"
#include <stdexcept>

using namespace std;

class Fila
{
    private:
        int tamanho;
        int inicio;
        int fim;
        Datagrama** fila;
    public:
        Fila(int tamanho);
        virtual ~Fila();
        virtual void enqueue(Datagrama* d);
        virtual Datagrama* dequeue();
        virtual bool isEmpty();
        virtual void imprimir();
};

#endif // FILA_H
