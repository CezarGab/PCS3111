#include <iostream>
#include <string>

using namespace std;

// Faca os includes necessarios

class Equipe {
public:
    string nome;
    int numeroDeMembros = 0;

    int getMaximoDeTorcedores();
    void imprimir();
};

/** Implementar metodos da classe Equipe **/

int Equipe::getMaximoDeTorcedores() {
    int numeroDeMembros = this->numeroDeMembros;
    int nmax = 15+(25*numeroDeMembros);

    return nmax;
}

void Equipe::imprimir() {
  cout << this->nome << " - " << this->numeroDeMembros << " membros " << endl;
}


//main(){
//  Equipe *e1 = new Equipe;
//  Equipe *e2 = new Equipe;
//  e1 -> nome = "Poli";
//  e1 -> numeroDeMembros = 22;
//
//  e1->getMaximoDeTorcedores();
//
//  e1->imprimir();
//
//
//
//  return 0;
//
//}


class Modalidade {
public:
    string nome;
    Equipe* e1 = NULL;
    Equipe* e2 = NULL;

    Equipe* getMaiorTorcida();
    bool adicionar(Equipe *e);

    void imprimir();
};

/** Implementar metodos da classe Modalidade **/

/** Testar classes no metodo main().

    REMOVER METODO main() ANTES DE ENVIAR AO JUDGE!
**/
/*
int main() {

}
*/

