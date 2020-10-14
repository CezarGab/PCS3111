#include "Rede.h"
#include <iostream>
#include <string>

using namespace std;

Rede::Rede(Roteador** roteadores, int quantidadeDeRoteadores) : roteadores(roteadores), quantidadeDeRoteadores(quantidadeDeRoteadores - 1) {
    //ctor                                                                                                      // Vetor começa na posição 0
}

Rede::~Rede() { // DUVIDA: sera que nao tem que fazer nada aqui?
    //dtor
}

Roteador* Rede::getRoteador(int endereco) {
    for(int i = 0; i < quantidadeDeRoteadores; i++) {
        if(roteadores[i]->getEndereco() == endereco) {
            return roteadores[i];
        }
    }
    return NULL;
}

void Rede::enviar(string texto, Roteador* origem, int destino, int ttl) {
    Datagrama* datagrama = new Datagrama(origem->getEndereco(), destino, ttl, texto); // Cria um datagrama
    origem->receber(datagrama);
}

void Rede::passarTempo() {
    for(int i = 0; i < quantidadeDeRoteadores + 1; i++) {
//        cout << "Processando o roteador " << i+1 << endl; // Apagar depois

        if(i==4){   // Apagar depois
            cout << "A fila do roteador 5 esta vazia? " << roteadores[i]->getFila()->isEmpty() << endl;
        }

        roteadores[i]->processar();
    }
}
