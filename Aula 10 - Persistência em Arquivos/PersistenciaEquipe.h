#ifndef PERSISTENCIAEQUIPE_H
#define PERSISTENCIAEQUIPE_H
#include "Equipe.h"

// inclua aqui as diretivas de compilacao necessarias

using namespace std;

class PersistenciaEquipe {
private:
    string arquivo;

public:
    PersistenciaEquipe(string arquivo);
    virtual ~PersistenciaEquipe();

    void inserir(Equipe *e);
    Equipe** obter(int* quantidade);
};
#endif // PERSISTENCIAEQUIPE_H
