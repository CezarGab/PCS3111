#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H
#include "No.h"
#include "Roteador.h"
#include "Processo.h"
#include "ServidorWeb.h"
#include "Navegador.h"
#include <vector>

class Hospedeiro : public No
{
    public:
        Hospedeiro(int endereco, Roteador* gateway);
        virtual ~Hospedeiro ();
        virtual void adicionarServidorWeb(int porta, string conteudo);
        virtual void adicionarNavegador(int porta);
        virtual Processo* getProcesso(int porta);
        virtual vector<Processo*>* getProcessos();

        void processar();

    protected:
        Roteador* gateway;
        vector<Processo*>* processosHospedeiro;
        int quantidadeDeProcessos;
};

#endif // HOSPEDEIRO_H
