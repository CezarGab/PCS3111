#include "TabelaDeRepasse.h"
#include <iostream>
#include <string>
using namespace std;

TabelaDeRepasse::TabelaDeRepasse(){
//"criar uma tabela em que cabem no máximo MAXIMO_TABELA endereços de destinos e roteadores adjacentes. "
    roteadores = new Roteador*[MAXIMO_TABELA];
    endereco = new int[MAXIMO_TABELA];
    for(int i = 0; i < MAXIMO_TABELA; i++){
        roteadores[i] = NULL;
        endereco[i] = 0; // DÚVIDA: tentei colocar NULL também, mas aparentemente int não aceita
    }

    this->roteadorPadrao = NULL; //"Defina o roteador padrão como NULL."
    this->tamanhoTabela = 0;

}

TabelaDeRepasse::~TabelaDeRepasse(){
//"O destrutor deve destruir os vetores alocados, mas não deve destruir os Roteadores adicionados ao vetor."
    delete[] roteadores;
    delete[] endereco; // DÚVIDA: devo destruir as outras variáveis também?

    cout << "Tabela de Repasse destruida" << endl;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente){
        if(tamanhoTabela < MAXIMO_TABELA){ // Se a tabela ainda aceita valores...
            for(int i = 0; i < tamanhoTabela; i++){ // Este FOR verifica se o endereco já está na tabela
                if(this->endereco[i] == endereco){
                    roteadores[i] = adjacente; // Se estiver, ele associa o roteador ao endereco

                    tamanhoTabela++;
                    return true;
                }
            }
            // Se saiu do FOR, então o endereco nao estava na tabela
            tamanhoTabela = tamanhoTabela + 1; // Aumenta-se o tamanho da tabela
            this->endereco[tamanhoTabela] = endereco; // Associa o endereco
            roteadores[tamanhoTabela] = adjacente; // Associa o roteador ao endereco

            return true;
        }

        else{
            return false; // A tabela já está cheia - OVERFLOW
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
    // Se saiu do FOR, entao o endereco não possui nenhum roteador associado
    return roteadorPadrao; // Retorna o roteador padrão
}

void TabelaDeRepasse::imprimir(){
    cout << "A Tabela esta com " << tamanhoTabela << " roteadores associados" << endl;
}
