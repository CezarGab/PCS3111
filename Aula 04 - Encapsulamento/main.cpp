#include <iostream>
#include <string>
using namespace std;

#include "Equipe.h"
#include "Modalidade.h"


/**
 * Faca os testes necessarios
 **/
int main() {
    /* Ex. 01 */
//    Equipe *Equipe1 =  new Equipe;
//
//    Equipe1 -> setNome("Equipe1");
//    Equipe1 -> setNumeroDeMembros(9);
//
//    Equipe1 -> getNome();
//    Equipe1 -> getNumeroDeMembros();
//
//    Equipe1 -> imprimir();
//
//    Equipe1 -> getMaximoDeTorcedores();
//
//    Equipe1 -> imprimir();
//
//
//    Equipe1 -> imprimir();


/* Ex 02 */
    Equipe *Equipe1 =  new Equipe;

    Equipe1 -> setNome("Poli");
    Equipe1 -> setNumeroDeMembros(10);

    Equipe *Equipe2 =  new Equipe;

    Equipe2 -> setNome("FEA");
    Equipe2 -> setNumeroDeMembros(11);

    Equipe1->imprimir();
    Equipe2 -> imprimir();

    Modalidade *Modalidade1 = new Modalidade;
    Modalidade1 -> setNome("InterUSP");


    if (Modalidade1 -> adicionar(Equipe1) == true){
        cout << "Equipe adicionada com sucesso." << endl;
    }

    if (Modalidade1 -> adicionar(Equipe2) == true){
        cout << "Equipe adicionada com sucesso." << endl;
    }

    if (Modalidade1 -> calculaTotalTorcida() == -1){
        cout << "Equipes insuficientes para calcular torcida." << endl;
    }



    Modalidade1 -> imprimir();



    return 0;
}
