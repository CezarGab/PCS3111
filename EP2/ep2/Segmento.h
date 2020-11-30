#ifndef SEGMENTO_H
#define SEGMENTO_H

#include <string>
using namespace std;

class Segmento
{
    public:
        Segmento(int portaDeOrigem, int portaDeDestino, string dado);
        virtual ~Segmento();

        virtual int getPortaDeOrigem() { return portaDeOrigem; } // Sera que podemos fazer assim?
        virtual int getPortaDeDestino() { return portaDeDestino; }
        virtual string getDado() { return dado; }

        virtual void imprimir();

    protected:
        int portaDeOrigem;
        int portaDeDestino;
        string dado;
};

#endif // SEGMENTO_H
