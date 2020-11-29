#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H
#include "No.h"
#include "Roteador.h"

#include <iostream>
#include <stdexcept>

using namespace std;

class TabelaDeRepasse
{
    public:
        TabelaDeRepasse();
        virtual ~TabelaDeRepasse();

        virtual void mapear(int endereco, No* adjacente);
        virtual No** getAdjacentes();
        virtual int getQuantidadeDeAdjacentes();

        virtual void setPadrao(No* padrao);

        virtual No* getDestino(int endereco);

        virtual void imprimir();
        static const int MAXIMO_TABELA = 5;

    protected:
        No** nos;
        int *endereco;
        int tamanhoTabela;
        No* noPadrao;

};

#endif // TABELADEREPASSE_H
