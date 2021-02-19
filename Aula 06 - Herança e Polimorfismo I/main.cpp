#include <iostream>
#include <string.h>
#include "Equipe.h"
#include "EquipeComCapitao.h"
#include "Competicao.h"

using namespace std;

int main()
{
    EquipeComCapitao *e1 = new EquipeComCapitao("Poli", 10, "Mario Covas");
    cout << e1->getNomeCapitao() << endl;

    EquipeComCapitao *e2 = new EquipeComCapitao("FEA", 12, "CapitaoFEA");
    cout << e2->getNomeCapitao() << endl;

    EquipeComCapitao *e3 = new EquipeComCapitao("SanFran", 13, "CapitaoSanFran");
    cout << e3->getNomeCapitao() << endl;


    Competicao *c1 = new Competicao("InterUSP", 2);
    cout << c1->adicionar(e1) << endl;
    cout << c1->adicionar(e1) << endl;
    cout << c1->adicionar(e2) << endl;
    cout << c1->adicionar(e3) << endl;



    cout << c1->getQuantidade() << endl;
    c1->imprimir();

    delete c1;

    delete e1;
    delete e2;
    delete e3;

    return 0;
}
