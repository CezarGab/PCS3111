#include "TabelaDeRepasse.h"
using namespace std;

TabelaDeRepasse::TabelaDeRepasse(){
//"criar uma tabela em que cabem no máximo MAXIMO_TABELA endereços de destinos e nos adjacentes. "
    nos = new No*[MAXIMO_TABELA];
    endereco = new int[MAXIMO_TABELA];
    for(int i = 0; i < MAXIMO_TABELA; i++){
        nos[i] = NULL;
        endereco[i] = 0; // DÚVIDA: tentei colocar NULL também, mas aparentemente int não aceita
    }
    this->noPadrao = NULL; //"Defina o no padrao como NULL."

    this->tamanhoTabela = 0;
}

TabelaDeRepasse::~TabelaDeRepasse(){
//"O destrutor deve destruir os vetores alocados, mas não deve destruir os Nos adicionados ao vetor."
    delete[] nos;
    delete[] endereco;

    cout << "Tabela de Repasse destruida" << endl;
}

void TabelaDeRepasse::mapear(int endereco, No* adjacente){
        noAdicionado = false; // O no recebido ainda nao foi adicionado
        if(tamanhoTabela < MAXIMO_TABELA){ // Se a tabela ainda aceita valores...
            for(int i = 0; i < tamanhoTabela; i++){ // Este FOR verifica se o endereco já está na tabela
                if(this->endereco[i] == endereco){
                    nos[i] = adjacente; // Se estiver, ele associa o no ao endereco
                    tamanhoTabela++; // DÚVIDA: Sera que eh necessaria essa linha aqui?
                    noAdicionado = true;
                }
            }

            if(!noAdicionado){ // Se o endereco nao estava na tabela, deve-se adiciona-lo para adicionar o no.
                this->endereco[tamanhoTabela] = endereco; // Associa o endereco
                nos[tamanhoTabela] = adjacente; // Associa o no ao endereco
                tamanhoTabela++;
            }
        }

        else{
            throw new overflow_error("Tabela de repasse cheia"); // A tabela já está cheia - OVERFLOW
        }
}

No** TabelaDeRepasse::getAdjacentes(){
    return this->nos; // Retorna o vetor de nos adjacentes
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return this->tamanhoTabela; // Retorna o tamanho do vetor de nos/enderecos. Ou seja, a quantidade de adjacentes;
}

void TabelaDeRepasse::setPadrao(No* padrao){
    this->noPadrao = padrao; // Associa um no ao no padrao
}

No* TabelaDeRepasse::getDestino(int endereco){ // Este metodo devolve o no associado/adjacente ao endereco
    for(int i = 0; i < tamanhoTabela; i++){ // Este FOR verifica se o endereco esta associado a algum no
        if(this->endereco[i] == endereco){
            return nos[i];
        }
    }
    // Se saiu do FOR, entao o endereco não possui nenhum no associado
    return noPadrao; // Retorna o no padrão
}

void TabelaDeRepasse::imprimir(){
    cout << "A Tabela esta com " << tamanhoTabela << " nos associados" << endl;
}

