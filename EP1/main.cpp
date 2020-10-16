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
    r6->getTabela()->mapear(3, r3);


    // Cria o vetor roteadores e a rede
    Rede* rede = new Rede(roteadores, 6);




    menuPrincipal(rede); // menuPrincipal

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

    rede->enviar(mensagem, rotOrigem, destino, ttl);

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
