#ifndef HISTORICO_H
#define HISTORICO_H
#include "Competicao.h"
#include "CompeticaoImprimivel.h"

class Historico {
public:
    Historico(int maximoValor);
    ~Historico();

    int getQuantidade();
    bool adicionar(Competicao* c);
    Competicao** getCompeticoes();
    Competicao** getCompeticoesImprimiveis(int& tamanho);
private:
    Competicao** competicoes;
    int quantidade;
    int maximoValor;
};

#endif // HISTORICO_H
