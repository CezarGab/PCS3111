#include "Roteador.h"

Roteador::Roteador(int endereco) : No(endereco)
{
    tabela = new TabelaDeRepasse(); // Na cria��o de um Roteador voc� deve criar a
                                    //  TabelaDeRepasse;
}

Roteador::~Roteador()
{
    delete tabela; // no destrutor deve-se destruir a tabela
}

TabelaDeRepasse* Roteador::getTabela(){
    return tabela; // retornar a TabelaDeRepasse
}

void Roteador::processar() // MESMA COISA DO EP1, mas usa nos ao inves de roteadores
{
    Datagrama* dtgParaProcessar; // Datagrama que ser� processado.

    if(!fila->isEmpty()){
        dtgParaProcessar = this->fila->dequeue(); // Obtem este datagrama dando o dequeue na fila do roteador.

    // Se n�o ha datagrama para ser processado, o roteador nao faz nada

        cout << "No: " << endereco << endl;
        dtgParaProcessar->processar(); // processa o datagrama

        if(dtgParaProcessar->ativo() == false){ // Se ele estiver desativado, deve ser deletado
            cout << "\tDestruido por TTL: ";
            cout << "Origem: " << dtgParaProcessar->getOrigem();
            cout << ", Destino: " << dtgParaProcessar->getDestino();
            cout << ", TTL: " << dtgParaProcessar->getTtl();
            cout << ", " << dtgParaProcessar->getDado() << endl;

            delete dtgParaProcessar;
        }

        else{ // Entao o datagrama esta ativo ainda
            if(dtgParaProcessar->getDestino() == endereco){ // Se o destino do datagrama for este roteador...
                cout << "\tRecebido> "; // Datagrama recebido
                cout << "Origem: " << dtgParaProcessar->getOrigem();
                cout << ", Destino: " << dtgParaProcessar->getDestino();
                cout << ", TTL: " << dtgParaProcessar->getTtl();
                cout << ", " << dtgParaProcessar->getDado() << endl;

                delete dtgParaProcessar;
            }

            else{ // Entao o destino do datagrama eh outro roteador
                No* noParaRepassar = tabela->getDestino(dtgParaProcessar->getDestino()); // Descobre qual deve ser o roteador para repassar atraves da tabela

                if(noParaRepassar == NULL){ // Se a tabela nao sabe...
                    cout << "\tSemProximo: " << endl;
                    cout << "Origem: " << dtgParaProcessar->getOrigem();
                    cout << ", Destino: " << dtgParaProcessar->getDestino();
                    cout << ", TTL: " << dtgParaProcessar->getTtl();
                    cout << ", " << dtgParaProcessar->getDado() << endl;

                    delete dtgParaProcessar; // exclui o datagrama

                }

                else{
                    cout << "\tEnviado para " << noParaRepassar->getEndereco() << ": ";
                    cout << "Origem: " << dtgParaProcessar->getOrigem();
                    cout << ", Destino: " << dtgParaProcessar->getDestino();
                    cout << ", TTL: " << dtgParaProcessar->getTtl();
                    cout << ", " << dtgParaProcessar->getDado() << endl;
                    noParaRepassar->receber(dtgParaProcessar); // O roteador de repasse recebe o datagrama em questao
                }
            }
        }
    }



}
