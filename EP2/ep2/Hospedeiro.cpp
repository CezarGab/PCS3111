#include "Hospedeiro.h"
#include <vector>
#include <stdexcept>

using namespace std;

Hospedeiro:: Hospedeiro(int endereco, Roteador* gateway) : No(endereco), gateway(gateway)
{
    processosHospedeiro = new vector<Processo*>();
    quantidadeDeProcessos = 0;
}

Hospedeiro::~Hospedeiro()
{
     for(int i = 0; i < quantidadeDeProcessos; i++) { // "No destrutor destrua todos os Processos adcionados ao Hospedeiro."
            delete processosHospedeiro->at(i);
    }

//    delete processosHospedeiro;
}

void Hospedeiro::adicionarServidorWeb(int porta, string conteudo){ // "Em adicionarServidorWeb deve-se receber a porta e o conte�do do ServidorWeb"

    if(getProcesso(porta) != NULL){ //  Caso ja exista um Processo na porta informada, o m�todo deve jogar um logic_error (da biblioteca padr�o).
        throw new logic_error("\tErro: tentativa de adicionar um servidor em uma porta ja ocupada");
    }

    ServidorWeb* serverParaAdicionar = new ServidorWeb(this->endereco, porta, this->gateway, conteudo);
    processosHospedeiro->push_back(serverParaAdicionar); // Se n�o existe, eu crio e adiciono no vetor de processos.
    quantidadeDeProcessos++;

}

void Hospedeiro::adicionarNavegador(int porta){ // em adicionarNavegador deve-se apenas receber a porta.

    if(getProcesso(porta) != NULL){ //  Caso ja exista um Processo na porta informada, o m�todo deve jogar um logic_error (da biblioteca padr�o).
        throw new logic_error("\tErro: tentativa de adicionar um navegador em uma porta ja ocupada");
    }

    Navegador* navegadorParaAdicionar = new Navegador(this->endereco, porta, this->gateway); // Se n�o existe, eu crio e adiciono no vetor de processos.
    processosHospedeiro->push_back(navegadorParaAdicionar);
    quantidadeDeProcessos++;

}

Processo* Hospedeiro::getProcesso(int porta){
        for(int i = 0; i < quantidadeDeProcessos; i++) {
            if((processosHospedeiro->at(i)->getPorta()) == porta){ // Procura o processo no vector

                return (processosHospedeiro->at(i)); // Retorna se encontrar
            }
        }

        return NULL; // Retorna NULL se nao encontrar
}

vector<Processo*>* Hospedeiro::getProcessos(){
    return processosHospedeiro; // Retorna o vector
}

void Hospedeiro::processar(){

    Datagrama* dtgParaProcessar; // Datagrama que ser� processado.

    dtgParaProcessar = fila->dequeue(); // Obtem este datagrama dando o dequeue na fila do roteador.

    Segmento* segmentoParaRepassar; // Segmento que sera repassado.
    segmentoParaRepassar = dtgParaProcessar->getDado(); // Obtem este segmento pegando o dado do dtg (que eh um segmento)

    Processo* processoParaReceber; // Processo que recebera o segmento.
    processoParaReceber = getProcesso(segmentoParaRepassar->getPortaDeDestino()); // Obtem este processo pegando a porta de destino do segmento.

    if(processoParaReceber != NULL){
        processoParaReceber->receber(segmentoParaRepassar->getPortaDeOrigem(), segmentoParaRepassar); // D�VIDA: N�o tenho certeza se o
                                                                                                    // primeiro parametro desse metodo eh isso mesmo (a origem do segmento) ou se
                                                                                                    // eh o endereco deste hospedeiro.
    }

    delete dtgParaProcessar; // Mesmo que nao haja um processo na porta informada, deve-se destruir o Datagrama.

     // IMPRESSOES DEVEM SER FEITAS EM TELA DEPOIS, CONFORME SECAO 4.1.
}
