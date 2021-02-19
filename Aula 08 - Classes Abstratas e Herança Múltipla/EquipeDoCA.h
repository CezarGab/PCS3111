#ifndef EQUIPEDOCA_H
#define EQUIPEDOCA_H
#include "Equipe.h"
#include "CentroAcademico.h"

class EquipeDoCA : public Equipe, public CentroAcademico
{
    public:
        EquipeDoCA(string nome, string sigla, Pessoa* presidente, int maxValor);

        virtual ~EquipeDoCA();

    private:
        string nome;
        string sigla;
        Pessoa* presidente;
        int maxValor;
};

#endif // EQUIPEDOCA_H
