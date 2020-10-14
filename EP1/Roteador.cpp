#include "Roteador.h"
#include <iostream>
#include <string>
using namespace std;

Roteador::Roteador(int endereco)
{
    this->endereco=endereco;

    tabela = new TabelaDeRepasse();
    fila = new Fila(TAMANHO_FILA);

    ultimoDadoRecebido = ""; // Como o roteador est� sendo construido agora, n�o h� ultimo dado recebido.
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

    Datagrama* dtgParaProcessar; // Datagrama que ser� processado.

    dtgParaProcessar = fila->dequeue(); // Obtem este datagrama dando o dequeue na fila do roteador.

//    cout << "\tDatagrama em processamento: " << dtgParaProcessar->getDado() << endl;

    if(dtgParaProcessar != NULL){ // Se n�o ha datagrama para ser processado, o roteador nao faz nada

        cout << "Roteador " << endereco << endl;
        dtgParaProcessar->processar(); // processa o datagrama

        if(dtgParaProcessar->ativo() == false){ // Se ele estiver desativado, deve ser deletado
            delete dtgParaProcessar;
            cout << "\tDestruido por TTL: ";
            cout << "Origem: " << dtgParaProcessar->getOrigem();
            cout << ", Destino: " << dtgParaProcessar->getDestino();
            cout << ", TTL: " << dtgParaProcessar->getTtl();
            cout << ", " << dtgParaProcessar->getDado() << endl;
        }

        if(dtgParaProcessar->getDestino() == endereco){ // Se o destino do datagrama for este roteador...
            ultimoDadoRecebido = dtgParaProcessar->getDado(); // Ele guarda o dado.
            cout << "\tRecebido: " << dtgParaProcessar->getDado() << endl;
        }

        else{ // Entao o destino do datagrama eh outro roteador
            Roteador* roteadorParaRepassar = tabela->getDestino(endereco); // Descobre qual deve ser o roteador para repassar atraves da tabela

            if(roteadorParaRepassar == NULL){ // Se a tabela nao sabe...
                delete dtgParaProcessar; // exclui o datagrama
            }

            else{
            roteadorParaRepassar->receber(dtgParaProcessar); // O roteador de repasse recebe o datagrama em questao
            cout << "\tEnviado para " << endereco << ": ";
            cout << "Origem: " << dtgParaProcessar->getOrigem();
            cout << ", Destino: " << dtgParaProcessar->getDestino();
            cout << ", TTL: " << dtgParaProcessar->getTtl();
            cout << ", " << dtgParaProcessar->getDado() << endl;
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
