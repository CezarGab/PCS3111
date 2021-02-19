#ifndef PROCESSO_H
#define PROCESSO_H
#include "Roteador.h"
#include "Segmento.h"

#include <iostream>
using namespace std;

class Processo
{
    public:
        Processo(int endereco, int porta, Roteador* gateway);
        virtual ~Processo();

        virtual int getEndereco();
        virtual int getPorta();

        virtual void receber(int origem, Segmento* mensagem) = 0; // Metodo abstato, usado nas classes Navegador e ServidorWeb

        virtual void imprimir();

        static void setTtlPadrao(int padrao);
        static int getTtlPadrao();

    protected:
        int endereco, porta;
        Roteador* gateway;
        static int ttlPadrao;
    private:
};

#endif // PROCESSO_H
