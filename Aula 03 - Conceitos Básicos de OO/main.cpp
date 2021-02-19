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

Equipe* Modalidade::getMaiorTorcida(){
    if(e1 == NULL){
        return NULL;
    }

    if (e2 == NULL){
        return e1;
    }

    if (e1 -> getMaximoDeTorcedores() > e2 -> getMaximoDeTorcedores()){
        return e1;
    }

    else{
        return e2;
    }

}

bool Modalidade::adicionar(Equipe* e){
   if(e1 == e || e2 == e || e2 != NULL){
   return false;
   }

   if(e1 == NULL){
   e1 = e;
   return true;
   }

   if(e2 == NULL){
   e2 = e;
   return true;
   }
}

void Modalidade::imprimir() {
  cout << this->nome << " - " << this->getMaiorTorcida()->nome << " com maior torcida" << endl;
  cout << e1->nome << " - " << e1->numeroDeMembros << " membros" << endl;
  cout << e2->nome << " - " << e2->numeroDeMembros << " membros" << endl;
}

main(){

  Modalidade *futebol = new Modalidade;
  futebol -> nome = "Futebol";


  Equipe *e1 = new Equipe;
  Equipe *e2 = new Equipe;


  e1 -> nome = "Poli";
  e1 -> numeroDeMembros = 22;
  e2 -> nome = "FEA";
  e2 -> numeroDeMembros = 17;

  futebol -> adicionar(e1);
  futebol -> adicionar(e2);

  futebol -> imprimir();



  return 0;


//  Equipe *e1 = new Equipe;
//  Equipe *e2 = new Equipe;
//  e1 -> nome = "Poli";
//  e1 -> numeroDeMembros = 22;
//
//  e1->getMaximoDeTorcedores();
//
//  e1->imprimir();
}

/** Testar classes no metodo main().

    REMOVER METODO main() ANTES DE ENVIAR AO JUDGE!
**/


