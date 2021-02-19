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

}

void Hospedeiro::adicionarServidorWeb(int porta, string conteudo){ // "Em adicionarServidorWeb deve-se receber a porta e o conteúdo do ServidorWeb"

    if(getProcesso(porta) != NULL){ //  Caso ja exista um Processo na porta informada, o método deve jogar um logic_error (da biblioteca padrão).
        throw new logic_error("\tErro: tentativa de adicionar um servidor em uma porta ja ocupada");
    }

    ServidorWeb* serverParaAdicionar = new ServidorWeb(this->endereco, porta, this->gateway, conteudo);
    processosHospedeiro->push_back(serverParaAdicionar); // Se não existe, eu crio e adiciono no vetor de processos.
    quantidadeDeProcessos++;

}

void Hospedeiro::adicionarNavegador(int porta){ // em adicionarNavegador deve-se apenas receber a porta.

    if(getProcesso(porta) != NULL){ //  Caso ja exista um Processo na porta informada, o método deve jogar um logic_error (da biblioteca padrão).
        throw new logic_error("\tErro: tentativa de adicionar um navegador em uma porta ja ocupada");
    }

    Navegador* navegadorParaAdicionar = new Navegador(this->endereco, porta, this->gateway); // Se não existe, eu crio e adiciono no vetor de processos.
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
//    cout << "Entrei aqui. O endereco eh " << this->getEndereco() << endl;
//    cout << "Entrei aqui. A fila ta vazia? " << getFila()->isEmpty() << endl;

    if(!this->fila->isEmpty()){
//        cout << "Entrei no isEmpty" << endl;

        Datagrama* dtgParaProcessar; // Datagrama que será processado.

        dtgParaProcessar = fila->dequeue(); // Obtem este datagrama dando o dequeue na fila do roteador.

        if(dtgParaProcessar != NULL){
            getProcesso(dtgParaProcessar->getDado()->getPortaDeDestino())->receber(dtgParaProcessar->getOrigem(),dtgParaProcessar->getDado());

        }

        else{
            cout << "\tSem destino";
            cout << "Origem: " << dtgParaProcessar->getOrigem();
            cout << ", Destino: " << dtgParaProcessar->getDestino();
            cout << ", TTL: " << dtgParaProcessar->getTtl();
            cout << ", " << dtgParaProcessar->getDado() << endl;
        }
//
//        Segmento* segmentoParaRepassar; // Segmento que sera repassado.
//        segmentoParaRepassar = dtgParaProcessar->getDado(); // Obtem este segmento pegando o dado do dtg (que eh um segmento)
//
//        Processo* processoParaReceber; // Processo que recebera o segmento.
//        processoParaReceber = getProcesso(segmentoParaRepassar->getPortaDeDestino()); // Obtem este processo pegando a porta de destino do segmento.
//
//        if(processoParaReceber != NULL){
//            processoParaReceber->receber(segmentoParaRepassar->getPortaDeOrigem(), segmentoParaRepassar); // DÚVIDA: Não tenho certeza se o
                                                                                                    // primeiro parametro desse metodo eh isso mesmo (a origem do segmento) ou se
                                                                                                        // eh o endereco deste hospedeiro.


        delete dtgParaProcessar; // Mesmo que nao haja um processo na porta informada, deve-se destruir o Datagrama.
    }

}
