#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "Segmento.h"
#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "No.h"
#include "Roteador.h"
#include "Processo.h"
#include "Navegador.h"
#include "ServidorWeb.h"
#include "Hospedeiro.h"
#include "Rede.h"
#include "PersistenciaDeRede.h"

using namespace std;

void menuPrincipal(Rede* rede);

int main()
{
//    Segmento* s1 = new Segmento(2, 4, "Dado s1");
//    Fila* f1 = new Fila(3);
//    Datagrama* d1 = new Datagrama(2, 5, 3, s1);
//
//    cout << "Deve ser 1 (fila vazia): " << f1->isEmpty() << endl;
//
//    f1->enqueue(d1);
//
//    cout << "Deve ser 0 (fila com segmento): " << f1->isEmpty() << endl;

    string arquivo;
    cout << "Digite o nome do arquivo: ";
//    cin >> arquivo;

    arquivo = "exemplo1.txt"; // APENAS PARA TESTES

    PersistenciaDeRede* persistencia = new PersistenciaDeRede();

    Rede* rede;

    rede = persistencia->carregar(arquivo);

    menuPrincipal(rede);


    return 0;
}


void menuPrincipal(Rede* rede)
{
    int opcao;
    cout << "\nSimulador de Rede" << endl;
    cout << "---" << endl;
    cout << "1) Usar um navegador" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "3) Alterar TTL" << endl;
    cout << "4) Sair" << endl;
    cout << "Escolha uma opcao: ";

    cin >> opcao;
    cout << endl;

    switch ( opcao )
    {
        case 1 : // Usar um navegador


            list<Hospedeiro*>* hospedeiros;

            // LISTAGEM DE HOSPEDEIROS ----------------

            hospedeiros = rede->getHospedeiros();

            Hospedeiro* hospedeiro;
            unsigned int tamanhoHospedeiros;
            tamanhoHospedeiros = hospedeiros->size();

            cout << "Quantidade de hospedeiros: " << tamanhoHospedeiros << endl;

            for(unsigned int i = 0; i < tamanhoHospedeiros; i++) { //
                hospedeiro = hospedeiros->front();
                cout << "Hospedeiro " << hospedeiro->getEndereco() << endl; // Imprima "Hospedeiro <e>"

                vector<Processo*>* processosHospedeiro;
                processosHospedeiro = hospedeiro->getProcessos(); // Pegando os processos do Hospedeiro
                Navegador* testaProcesso;

                for(unsigned int j = 0; j < processosHospedeiro->size(); j++) { // Pega todos os processos do Hospedeiro


                        testaProcesso = dynamic_cast<Navegador*>(processosHospedeiro->at(j));

                        if(testaProcesso != NULL) {// Verifica se a conversão foi bem sucedida. Se for, o processo eh um navegador
                            cout << "\tNavegador " << processosHospedeiro->at(j)->getPorta() << endl;
                        }

                        else{ // Entao o processo eh um serverWeb
                            cout << "\tServidorWeb " << processosHospedeiro->at(j)->getPorta() << endl;
                        }

                }

                hospedeiros->pop_front(); // Descarta o comeco da pilha de hospedeiros
            }
            cout << "\n";

            int enderecoHospedeiro, portaNavegador, enderecoPagina, portaServer;
            cout << "Digite o endereco do hospedeiro: ";
            cin >> enderecoHospedeiro;

            cout << "Digite a porta do navegador: ";
            cin >> portaNavegador;

            cout << "Abrir pagina no endereco ";
            cin >> enderecoPagina;

            cout << "Porta do Servidor Web: ";
            cin >> portaServer;


            menuPrincipal(rede);
            break;

        case 2 : // Passar tempo
            int tempo;
            cout << "Quantidade de tempo: ";
            cin >> tempo;
            for(int i = 0; i < tempo; tempo++){
                rede->passarTempo();
            }

            menuPrincipal(rede);
            break;

        case 3: // Alterar TTL
            int novoTtl;
            cout << "TTL atual: " << Processo::getTtlPadrao() << endl;
            cout << "Novo TTL: ";
            cin >> novoTtl;
            Processo::setTtlPadrao(novoTtl);

            menuPrincipal(rede);
            break;


        case 4: // Sair

            break;

        default :
            cout << " ERRO: Opcao invalida." << endl;
            break;
    }
}


