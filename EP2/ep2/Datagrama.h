#ifndef DATAGRAMA_H
#define DATAGRAMA_H
#include "Segmento.h"

class Datagrama
{
    private:
        int origem;
        int destino;
        int ttl;
        Segmento* dado;

    public:
        Datagrama(int origem, int destino, int ttl, Segmento* dado);
        virtual ~Datagrama();
        virtual int getOrigem();
        virtual int getDestino();
        virtual int getTtl();
        virtual Segmento* getDado();

        virtual void processar();
        virtual bool ativo();

        virtual void imprimir();

    protected:

    private:
};

#endif // DATAGRAMA_H
