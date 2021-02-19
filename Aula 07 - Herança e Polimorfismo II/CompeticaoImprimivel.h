#ifndef COMPETICAOIMPRIMIVEL_H
#define COMPETICAOIMPRIMIVEL_H
#include "Competicao.h"

class CompeticaoImprimivel: public Competicao {
public:
    CompeticaoImprimivel(string nome, int maximoValor);
    virtual ~CompeticaoImprimivel();

    void imprimir();
};

#endif // COMPETICAOIMPRIMIVEL_H
