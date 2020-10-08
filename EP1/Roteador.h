#ifndef ROTEADOR_H
#define ROTEADOR_H
#define TAMANHO_FILA 3
#include "TabelaDeRepasse.h"
#include "Fila.h"

class TabelaDeRepasse;
class Roteador
{
    private:
        int endereco;
        TabelaDeRepasse* tabela;
        Fila* fila;
        string ultimoDadoRecebido;
    public:
        Roteador(int endereco);
        virtual ~Roteador();

        TabelaDeRepasse* getTabela();
        Fila* getFila();
        int getEndereco();
        void receber(Datagrama* d);
        void processar();
        string getUltimoDadoRecebido();
        void imprimir();


};

#endif // ROTEADOR_H
