#ifndef REDE_H
#define REDE_H


#include "Roteador.h"
#include "TabelaDeRepasse.h"
//#include "Fila.h"
//#include "Datagrama.h"

//class TabelaDeRepasse;
class Roteador;

class Rede {
    private:
        Roteador** roteadores;
        int quantidadeDeRoteadores;

    public:
        Rede(Roteador** roteadores, int quantidadeDeRoteadores);
        ~Rede();

        Roteador* getRoteador(int endereco);
        void enviar(string texto, Roteador* origem, int destino, int ttl);
        void passarTempo();

        void imprimir();
};

#endif // REDE_H
