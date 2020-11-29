#include "Roteador.h"

Roteador::Roteador(int endereco) : No(endereco)
{
    tabela = new TabelaDeRepasse(); // Na criação de um Roteador você deve criar a
                                    //  TabelaDeRepasse;
}

Roteador::~Roteador()
{
    delete tabela; // no destrutor deve-se destruir a tabela
}

TabelaDeRepasse* Roteador::getTabela(){
    return tabela; // retornar a TabelaDeRepasse
}

void Roteador::processar() // >>MESMA COISA DO EP1<<, mas usa nos ao inves de roteadores e
{
    Datagrama* dtgParaProcessar; // Datagrama que será processado.

    dtgParaProcessar = fila->dequeue(); // Obtem este datagrama dando o dequeue na fila do roteador.

    if(dtgParaProcessar != NULL){ // Se não ha datagrama para ser processado, o roteador nao faz nada

//        cout << "\t\t\tDatagrama em processamento: " << dtgParaProcessar->getDado() << endl; // Apagar depois
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
                delete dtgParaProcessar;
            }

            else{ // Entao o destino do datagrama eh outro roteador
                No* noParaRepassar = tabela->getDestino(dtgParaProcessar->getDestino()); // Descobre qual deve ser o roteador para repassar atraves da tabela

                if(noParaRepassar == NULL){ // Se a tabela nao sabe...
                    delete dtgParaProcessar; // exclui o datagrama
                    cout << "\tNao ha pra quem repassar." << endl; // APAGAR ESSA LINHA DEPOIS (acho que nao precisa)
                }

                else{
                    /*
                    cout << "Estado inicial de " << roteadorParaRepassar->getEndereco() << endl;
                    roteadorParaRepassar->getFila()->imprimir();
                    */
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
