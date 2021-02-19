#include <iostream>
#include "Participante.h"
#include "Equipe.h"
#include "Pessoa.h"
using namespace std;

int main() {
    /* Faca os testes necessarios */
//    Equipe* poli = new Equipe("Poli", 2);
//    Pessoa* cezar = new Pessoa("cezar", 123);
//    Pessoa* gabriel = new Pessoa("gabriel", 124);
//    Pessoa* igor = new Pessoa("igor", 125);
//    poli->adicionar(cezar);
//    poli->adicionar(gabriel);
//    poli->adicionar(igor);
//
//    Pessoa** jogadoresDaPoli = poli->getPessoas();
//    cout << poli->getNome() << endl;


    Pessoa* professor = new Pessoa("professor");
    cout << professor->getNome() << " tem o NUSP " << professor->getNusp() << endl;
    cout << professor->getNome() << " tem o NUSP " << professor->getNusp() << endl;

    Pessoa* professor2 = new Pessoa("professor2");
    cout << professor2->getNome() << " tem o NUSP " << professor2->getNusp() << endl;
    return 0;
}
