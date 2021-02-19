#ifndef NO_H
#define NO_H
#include "Fila.h"

#include <iostream>
using namespace std;

class No
{
    public:
        No(int endereco);
        virtual ~No();
        virtual Fila* getFila();
        virtual int getEndereco();
        virtual void processar() = 0; // Depende do tipo de No (roteador ou hospedeiro)
        virtual void receber(Datagrama* d);
        virtual void imprimir();
        static const int TAMANHO_FILA = 5;

    protected:
        int endereco;
        Fila* fila;
};

#endif // NO_H
