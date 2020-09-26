#include "TabelaDeRepasse.h"
#include <iostream>
#include <string>
using namespace std;

TabelaDeRepasse::TabelaDeRepasse(){
//"criar uma tabela em que cabem no m�ximo MAXIMO_TABELA endere�os de destinos e roteadores adjacentes. "

    for(int i = 0; i < MAXIMO_TABELA; i++){
        roteadores[i] = NULL;
        endereco[i] = 0; // D�VIDA: tentei colocar NULL tamb�m, mas aparentemente int n�o aceita
    }

    this->roteadorPadrao = NULL; //"Defina o roteador padr�o como NULL."
    this->tamanhoTabela = 0;

}

TabelaDeRepasse::~TabelaDeRepasse(){
//"O destrutor deve destruir os vetores alocados, mas n�o deve destruir os Roteadores adicionados ao vetor."
    delete this->roteadores;
    delete this->endereco; // D�VIDA: devo destruir as outras vari�veis tamb�m?

    cout << "Tabela de Repasse destru�da" << endl;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente){
        if(tamanhoTabela < MAXIMO_TABELA){ // Se a tabela ainda aceita valores...
            for(int i = 0; i < tamanhoTabela; i++){ // Este FOR verifica se o endereco j� est� na tabela
                if(this->endereco[i] == endereco){
                    roteadores[i] = adjacente; // Se estiver, ele associa o roteador ao endereco
                    return true;
                }
            }
            // Se saiu do FOR, ent�o o endereco nao estava na tabela
            tamanhoTabela = tamanhoTabela + 1; // Aumenta-se o tamanho da tabela
            this->endereco[tamanhoTabela] = endereco; // Associa o endereco
            roteadores[tamanhoTabela] = adjacente; // Associa o roteador ao endereco
            return true;
        }

        else{
            return false; // A tabela j� est� cheia
        }

}

Roteador** TabelaDeRepasse::getAdjacentes(){
    return this->roteadores; // Retorna o vetor de roteadores adjacentes
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return this->tamanhoTabela; // Retorna o tamanho do vetor de roteadores/enderecos. Ou seja, a quantidade de adjacentes;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao){
    this->roteadorPadrao = padrao; // Asocia um roteador ao roteador padrao
}

Roteador* TabelaDeRepasse::getDestino(int endereco){ // Este metodo devolve o roteador associado/adjacente ao endereco
    for(int i = 0; i < tamanhoTabela; i++){ // Este FOR verifica se o endereco esta associado a algum roteador
        if(this->endereco[i] == endereco){
            return roteadores[i];
        }
    }
    // Se saiu do FOR, entao o endereco n�o possui nenhum roteador associado
    return roteadorPadrao; // Retorna o roteador padr�o
}

void TabelaDeRepasse::imprimir(){
    cout << "A Tabela esta com " << tamanhoTabela << " roteadores associados" << endl;
}
