#include <iostream>
#include <string.h>
#include "Equipe.h"
#include "Tabela.h"
using namespace std;

int main()
{
//    /* Exercício 01 */
//    Equipe *e1 =  new Equipe("Poli", 10);
//
//    e1->imprimir();
//
//    Equipe *e2 =  new Equipe("FEA", 12);
//    e2->imprimir();
//

    /* Exercício 02 */
    Equipe **tab = new Equipe*[2];
    Equipe *e1 =  new Equipe("Poli", 10);

    e1->imprimir();

    Equipe *e2 =  new Equipe("FEA", 12);
    e2->imprimir();

    tab[0] = e1;
    tab[1] = e2;

    Tabela *t1 = new Tabela(tab, 2);
    t1->imprimir();

    return 0;

}
