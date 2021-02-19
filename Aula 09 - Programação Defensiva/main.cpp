#include <iostream>
#include "Competicao.h"
#include "Modalidade.h"
#include "Equipe.h"
#include "EquipeRepetida.h"

using namespace std;

/** Teste o codigo **/
int main() {

    Competicao *interusp = new Competicao("Interusp", 5);
    Equipe *poli = new Equipe("Poli", 2);
    Equipe *fea = new Equipe("FEA", 2);

    interusp->adicionar(poli);
    interusp->adicionar(fea);

    Modalidade *futebol = new Modalidade("Futebol", 5);
    futebol->adicionar(poli);

     cout << "Quantidade em futebol: " << futebol->getQuantidade() << endl;

    interusp->adicionar(futebol);

    cout << "Quantidade em futebol: " << futebol->getQuantidade() << endl;
}
