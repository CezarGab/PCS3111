#include "EquipeDoCA.h"
#include "Equipe.h"

EquipeDoCA::EquipeDoCA(string nome, string sigla, Pessoa* presidente, int maxValor) : nome(nome), sigla(sigla), presidente(presidente), maxValor(maxValor), Equipe(nome, maxValor), CentroAcademico(presidente, sigla)
{
    //ctor
}

EquipeDoCA::~EquipeDoCA()
{
    //dtor
}
