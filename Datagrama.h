#include <string>
using namespace std;

#ifndef DATAGRAMA_H
#define DATAGRAMA_H


class Datagrama
{
    private:
        int origem;
        int destino;
        int ttl = 0;

    public:
        Datagrama(int origem, int destino, int ttl, string dado);
        ~Datagrama();
        int getOrigem();
        int getDestino();
        int getTtl();
        string getDado();
        void processar();
        bool ativo();
        void imprimir();


};

#endif // DATAGRAMA_H
