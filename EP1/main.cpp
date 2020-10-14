#include <iostream>
#include <string>
using namespace std;

#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "Rede.h"
#include "Roteador.h"

void menuPrincipal(Rede* rede);
void enviarDatagrama(Rede* rede);
void passarTempo(Rede* rede);

int main()
{
//    cout << "Teste - Fila" << endl;
//    // Bateria de testes
//    Fila* fila1 = new Fila(3);
//    cout << "Tamanho da fila 1: " << fila1->getTamanho() << endl;
//    Datagrama* teste1 = new Datagrama(1, 3, 4, "mensagem pip popa");
//    Datagrama* teste2 = new Datagrama(1, 3, 4, "mensagem pip pope");
//    Datagrama* teste3 = new Datagrama(1, 3, 4, "mensagem pip popi");
//    Datagrama* teste4 = new Datagrama(1, 3, 4, "mensagem pip popo");
//    Datagrama* teste5 = new Datagrama(1, 3, 4, "mensagem pip popu");
//    cout << "Dado inserido no Datagrama 1: " << teste1->getDado() << endl;
//    cout << "TTL do Datagrama 1: " << teste1->getTtl() << endl;
//    teste1->processar();
//    cout << "Datagrama 1 processado" << endl;
//    cout << "TTL pos processamento: " << teste1->getTtl() << endl;
//    cout << "Fila 1 esta vazia? " << fila1->isEmpty() << endl;
//    cout << "Datagrama 1 inserido na fila. " << fila1->enqueue(teste1) << endl;
//    cout << "Datagrama 2 inserido na fila. " << fila1->enqueue(teste2) << endl;
//    cout << "Datagrama 3 inserido na fila. " << fila1->enqueue(teste3) << endl;
//    cout << "Datagrama 4 inserido na fila. " << fila1->enqueue(teste4) << " espera se 0" << endl;
//    cout << "Datagrama 5 inserido na fila. " << fila1->enqueue(teste5) << " espera se 0" << endl;
//    cout << "Fila 1 esta vazia? " << fila1->isEmpty() << endl;

//      // Testes - Tabela de Repasse
//
//      Roteador* r1 = new Roteador(1);
//      Roteador* r4 = new Roteador(4);
//      Roteador* r2 = new Roteador(2);
//
//      cout << "Eh possivel mapear corretamente? " << r1->getTabela()->mapear(1, r2) << endl;
//
//      cout << "-Quantos enderecos estao mapeados? " << r1->getTabela()->getQuantidadeDeAdjacentes() << endl;
//      cout << "Eh possivel mapear corretamente? " << r1->getTabela()->mapear(2, r2) << endl;
//      cout << "Eh possivel mapear corretamente? " << r1->getTabela()->mapear(3, r2) << endl;
//      cout << "Eh possivel mapear corretamente? " << r1->getTabela()->mapear(4, r4) << endl;
//      cout << "Eh possivel mapear corretamente? " << r1->getTabela()->mapear(5, r2) << endl;
//      cout << "Eh possivel mapear corretamente? Deve dar zero, por overflow: " << r1->getTabela()->mapear(6, r2) << endl;
//      cout << "-Quantos enderecos estao mapeados? Deve dar 5, que eh o limite: " << r1->getTabela()->getQuantidadeDeAdjacentes() << endl;
//
//      r1->getTabela()->setPadrao(r2);
//
//      cout << "__________________________" << endl << endl;
//      cout << "Deve retornar 4: " << r1->getTabela()->getDestino(4)->getEndereco() << endl;
//      cout << "Deve retornar 2, roteador padrao: " << r1->getTabela()->getDestino(8)->getEndereco() << endl;


//    // Testes - Roteadores
//    cout << "Teste - Roteador" << endl;
//    Roteador* rot1 = new Roteador(2);
//
//    Datagrama* data1 = new Datagrama(1, 5, 1, "Oi");
//    Datagrama* data2 = new Datagrama(4, 2, 2, "Alo");
//    rot1->receber(data1);
//    rot1->receber(data2);
//
//    rot1->processar();
//    cout << "Nao deve retornar nada: " << rot1->getUltimoDadoRecebido() << endl;
//
//    rot1->processar();
//    cout << "Deve retornar a mensagem do data 2: " << rot1->getUltimoDadoRecebido() << endl;


    // Main.cpp
    // Cria os roteadores
    Roteador* r1 = new Roteador(1);
    Roteador* r2 = new Roteador(2);
    Roteador* r3 = new Roteador(3);
    Roteador* r4 = new Roteador(4);
    Roteador* r5 = new Roteador(5);
    Roteador* r6 = new Roteador(6);

    Roteador* roteadores[6] = {r1, r2, r3, r4, r5, r6};

    // Define os roteadores padrões
    r1->getTabela()->setPadrao(r2);
    r2->getTabela()->setPadrao(r5);
    r3->getTabela()->setPadrao(r2);
    r4->getTabela()->setPadrao(r5);
    r5->getTabela()->setPadrao(r2);
    r6->getTabela()->setPadrao(r5);

    // Mapeando
    r1->getTabela()->mapear(4, r4);
    r2->getTabela()->mapear(1, r1);
    r2->getTabela()->mapear(3, r3);
    r3->getTabela()->mapear(6, r6);
    r4->getTabela()->mapear(1, r1);
    r5->getTabela()->mapear(6, r6);
    r5->getTabela()->mapear(4, r4);
//    r5->getTabela()->imprimir();
    r6->getTabela()->mapear(3, r3);


    // Cria o vetor roteadores e a rede
    Rede* rede = new Rede(roteadores, 6);




    menuPrincipal(rede);

    // menuPrincipal:



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
            enviarDatagrama(rede);
            break;

        case 2 : // Passar tempo
            passarTempo(rede);
            break;

        case 3: // Sair
            break;

        default :
            cout << " ERRO: Opcao invalida." << endl;
            break;
    }
}

void enviarDatagrama(Rede* rede)
{
    int origem, destino, ttl;
    string mensagem;

    cout << "Endereco do roteador de origem: ";
    cin >> origem;
    cout << "Endereco de destino: ";
    cin >> destino;
    cout << "TTL: ";
    cin >> ttl;
    cout << "Mensagem: ";
    cin >> mensagem;
    cout << endl;

    Roteador* rotOrigem = rede->getRoteador(origem);

    if (rotOrigem == NULL){
        cout << "Erro: origem desconhecida" << endl;
    }

    rede->enviar(mensagem, rotOrigem, destino, ttl); // Inserir tambem as consequencias/erros

    menuPrincipal(rede);
}

void passarTempo(Rede* rede)
{
    int tempo;
    int n;
    cout << "Quantidade de tempo: ";
    cin >> n;
    cout << endl;

    for(tempo = 1; tempo <= n; tempo++){
        cout << "Instante " << tempo << endl;
        cout << "---" << endl;
        rede->passarTempo();
        cout << endl;
    }

    menuPrincipal(rede);

}
