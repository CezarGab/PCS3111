#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H
#define MAXIMO_TABELA 5
#include "Roteador.h"

class Roteador;

class TabelaDeRepasse
{
    private:
        Roteador** roteadores;
        int *endereco;
        int tamanhoTabela;
        Roteador* roteadorPadrao;

    public:
        TabelaDeRepasse();
        ~TabelaDeRepasse();
        bool mapear(int endereco, Roteador* adjacente);
        Roteador** getAdjacentes();
        int getQuantidadeDeAdjacentes();
        void setPadrao(Roteador* padrao);
        Roteador* getDestino(int endereco);
        void imprimir();

};

#endif // TABELADEREPASSE_H
