#include "Roteador.h"
#include <iostream>
#include <string>
using namespace std;

Roteador::Roteador(int endereco)
{
    this->endereco=endereco;

    tabela = new TabelaDeRepasse();
    fila = new Fila(TAMANHO_FILA);

    ultimoDadoRecebido = ""; // Como o roteador está sendo construido agora, não há ultimo dado recebido.
}

Roteador::~Roteador()
{
    delete fila;
    delete tabela;
}

TabelaDeRepasse* Roteador::getTabela()
{
    return tabela; // retorna a TabelaDeRepasse do roteador.
}

Fila* Roteador::getFila()
{
    return fila; // retorna a Fila do roteador.
}

int Roteador::getEndereco()
{
    return endereco; // retorna o endereco do roteador.
}

void Roteador::receber(Datagrama* d)
{
    if(fila->enqueue(d) == false){ // se der true, o enqueue funcionou
        cout << "\tFila em " << endereco << "estourou." << endl; // overflow na fila do roteador
    }
}

void Roteador::processar()
{
//    cout << "\tIniciando o processamento" << endl;

    Datagrama* dtgParaProcessar; // Datagrama que será processado.

    dtgParaProcessar = fila->dequeue(); // Obtem este datagrama dando o dequeue na fila do roteador.



    if((!fila->isEmpty()) || dtgParaProcessar != NULL){ // Se não ha datagrama para ser processado, o roteador nao faz nada

//        cout << "\t\t\tDatagrama em processamento: " << dtgParaProcessar->getDado() << endl; // Apagar depois
        cout << "Roteador " << endereco << endl;
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
                ultimoDadoRecebido = dtgParaProcessar->getDado(); // Ele guarda o dado.
                cout << "\tRecebido: " << ultimoDadoRecebido << endl;
            }

            else{ // Entao o destino do datagrama eh outro roteador
                Roteador* roteadorParaRepassar = tabela->getDestino(dtgParaProcessar->getDestino()); // Descobre qual deve ser o roteador para repassar atraves da tabela

                if(roteadorParaRepassar == NULL){ // Se a tabela nao sabe...
                    delete dtgParaProcessar; // exclui o datagrama
                    cout << "\tNao ha pra quem repassar." << endl; // APAGAR ESSA LINHA DEPOIS (acho que nao precisa)
                }

                else{
                roteadorParaRepassar->receber(dtgParaProcessar); // O roteador de repasse recebe o datagrama em questao
                cout << "\tEnviado para " << roteadorParaRepassar->getEndereco() << ": ";
                cout << "Origem: " << dtgParaProcessar->getOrigem();
                cout << ", Destino: " << dtgParaProcessar->getDestino();
                cout << ", TTL: " << dtgParaProcessar->getTtl();
                cout << ", " << dtgParaProcessar->getDado() << endl;
                }
            }
        }
    }
}

string Roteador::getUltimoDadoRecebido()
{
    return ultimoDadoRecebido;
}

void Roteador::imprimir()
{

}
