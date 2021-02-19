// Implemente os metodos aqui
#include <fstream>
#include "PersistenciaEquipe.h"
#include <iostream>
#include <stdexcept>

using namespace std;

PersistenciaEquipe::PersistenciaEquipe(string arquivo) : arquivo(arquivo) {
}

PersistenciaEquipe::~PersistenciaEquipe(){

}

void PersistenciaEquipe::inserir(Equipe *e){

    ofstream output;

    output.open(arquivo, ios_base::app);

    output << e->getNome() << endl;
    output << e->getMembros() << endl;

    output.close();
}

Equipe** PersistenciaEquipe::obter(int* quantidade){


    ifstream entrada;

    entrada.open(arquivo);


    if (entrada.fail() ) {
        cout << "Arquivo nao encontrado" << endl;
        entrada.close();
        throw new invalid_argument("Arquivo nao encontrado");
        return NULL;
    }


    string nomeEquipe;
    int membrosEquipe;
    Equipe** equipes = new Equipe*[10];

    (*quantidade) = 0;


    while (entrada) {
        entrada >> nomeEquipe;

         if (entrada.fail()){
            if(quantidade != 0){
                break;
            }

            cout << "Erro: nao eh string" << endl;
             throw new logic_error("Erro de leitura");
         }

        entrada >> membrosEquipe;
        if (entrada.fail()){
            cout << "Erro: nao eh int" << endl;
             throw new logic_error("Erro de leitura");
        }

        cout << nomeEquipe << endl;
        equipes[*quantidade] = new Equipe(nomeEquipe, membrosEquipe);

        (*quantidade)++;
    }


    if (!entrada.eof()){
        cout << "Erro de leitura" << endl;
        entrada.close();
        throw new logic_error("Erro de leitura");
    }

    if (*quantidade == 0)  {
        cout << "Arquivo vazio" << endl;
        entrada.close();
        return NULL;
  }

  entrada.close();

  return equipes;
}
