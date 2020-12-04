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
    cin >> arquivo;

    PersistenciaDeRede* persistencia = new PersistenciaDeRede();

    Rede* rede;

    rede = persistencia->carregar(arquivo);

    menuPrincipal(rede);


    return 0;
}


void menuPrincipal(Rede* rede)
{
    int opcao;
    cout << "Simulador de Rede" << endl;
    cout << "---" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "3) Sair" << endl;
    cout << "Escolha uma opcao: ";

    cin >> opcao;
    cout << endl;

    switch ( opcao )
    {
        case 1 : // Enviar um datagrama


            list<Hospedeiro*>* hospedeiros;

            hospedeiros = rede->getHospedeiro();

            Hospedeiro* hospedeiro;

            for(unsigned int i = 0; i < hospedeiros->size(); i++) { //
                hospedeiro = hospedeiros->front();
                cout << "Hospedeiro " << hospedeiro->getEndereco(); // Imprima "Hospedeiro <e>"

                vector<Processo*>* processosHospedeiro;
                processosHospedeiro = hospedeiro->getProcessos(); // Pegando os processos do Hospedeiro

                for(unsigned int j = 0; j < processosHospedeiro->size(); j++) { // Pega todos os processos do Hospedeiro
                        cout << "\t";
                        Navegador* testaProcesso = dynamic_cast<Navegador*>(processosHospedeiro->at(j));

                        if(testaProcesso != NULL) {// Verifica se a conversão foi bem sucedida. Se for, o processo eh um navegador
                            cout << "Navegador" << processosHospedeiro->at(j)->getPorta() << endl;
                        }

                        else{ // Entao o processo eh um serverWeb
                            cout << "ServidorWeb" << processosHospedeiro->at(j)->getPorta() << endl;
                        }
                hospedeiros->pop_front(); // Descarta o comeco da pilha de hospedeiros
                }
            }

            break;

        case 2 : // Passar tempo
            int tempo;
            cout << "Quantidade de tempo: ";
            cin >> tempo;
            for(int i = 0; i < tempo; tempo++){
                rede->passarTempo();
            }
            break;

        case 3: // Alterar TTL
//
//            cout << "TTL atual: " << processo->getTtlPadrao();
            cout << "Novo TTL: ";
//            cin >> processo->setTtlPadrao();

            break;


        case 4: // Sair

            break;

        default :
            cout << " ERRO: Opcao invalida." << endl;
            break;
    }
}
