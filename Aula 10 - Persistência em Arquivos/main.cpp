// Inclua aqui as diretivas de compilacao necessarias
#include "Equipe.h"
#include "PersistenciaEquipe.h"
using namespace std;

int main() {
//    Equipe* poli = new Equipe("Poli", 10);
//    Equipe* ifusp = new Equipe("IFUSP ", 15);

    PersistenciaEquipe* arq = new PersistenciaEquipe("equipes.txt");

//    arq->inserir(poli);
//    arq->inserir(ifusp);

    int quantidade;
    quantidade = 0;
    arq->obter(&quantidade);
    cout << "Quantidade de equipes no arquivo: " << quantidade << endl;
    return 0;
}

