#include "CentroAcademico.h"

CentroAcademico::CentroAcademico(Pessoa* presidente, string sigla) : presidente(presidente), sigla(sigla)
{
    //ctor
}

CentroAcademico::~CentroAcademico()
{
    //dtor
}

string CentroAcademico::getSigla(){
    return sigla;
}

Pessoa* CentroAcademico::getPresidente(){
    return presidente;
}
