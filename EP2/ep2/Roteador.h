#ifndef ROTEADOR_H
#define ROTEADOR_H
#include "TabelaDeRepasse.h"
#include "No.h"

#include <iostream>
#include <stdexcept>

class TabelaDeRepasse; // Por algum motivo, da erro se nao faco isso. Precisamos resolver depois.
using namespace std;

class Roteador: public No {
    public:
        Roteador(int endereco);
        virtual ~Roteador();
        virtual TabelaDeRepasse* getTabela();

        void processar();

    protected:
        TabelaDeRepasse* tabela;
};

#endif // ROTEADOR_H
