#include "Competicao.h"
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
// Implemente as alteracoes

Competicao::Competicao(string nome) :
nome(nome) {
    quantidadeDeEquipes = 0;
    equipesVetor = new vector<Equipe*>();
    modalidades = new list<Modalidade*>();

}

Competicao::~Competicao() {
	delete equipesVetor;
	delete[] modalidades;
}

vector<Equipe*>* Competicao::getEquipes() {
    return equipesVetor;
}

list<Modalidade*>* Competicao::getModalidades() {
    return modalidades;
}

void Competicao::adicionar(Equipe* e) {
//    if(quantidadeDeEquipes >= maxValor){
//            cout << "Vetor cheio" << endl;
//            throw new overflow_error("Equipes esta cheio"); /* Por que não é mais necessario verificar? */
//
//    }

    for(int i = 0; i < quantidadeDeEquipes; i++) {
        if((this->equipesVetor->at(i)) == e){
            throw new invalid_argument("Equipe ja adicionada");
        }
    }
    equipesVetor->push_back(e);

    quantidadeDeEquipes++;
}

void Competicao::adicionar(Modalidade* m) {

    list<Modalidade*>::iterator it = modalidades->begin();

    it = find(modalidades->begin(), modalidades->end(), m);

	if (it != modalidades->end() ){
        throw new invalid_argument("Modalidade ja adicionada");
	}

    modalidades->push_back(m);


//    quantidadeDeModalidades++;
}
