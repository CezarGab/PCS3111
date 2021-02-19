#ifndef REDE_H
#define REDE_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#include "No.h"
#include "Roteador.h"
#include "Processo.h"
#include "Hospedeiro.h"


class Rede
{
    public:
        Rede();
        virtual ~Rede();
        virtual void adicionar(No* no);

        virtual No* getNo(int endereco);
        virtual list<Hospedeiro*>* getHospedeiros();

        virtual void passarTempo();

        virtual void imprimir();

    protected:

    private:
        vector<No*>* nosDaRede;
        list<Hospedeiro*>* hospedeiroDaRede;
};

#endif // REDE_H
