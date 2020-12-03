#include "PersistenciaDeRede.h"

#include "No.h"
#include "ServidorWeb.h"
#include "Roteador.h"
#include "Navegador.h"
#include "TabelaDeRepasse.h"

PersistenciaDeRede::PersistenciaDeRede()
{
    //ctor
}

PersistenciaDeRede::~PersistenciaDeRede()
{
    //dtor
}

Rede* PersistenciaDeRede::carregar(string arquivo){

    ifstream entrada;

    entrada.open(arquivo);

    if (entrada.fail() ) { // Se o arquivo nao for encontrado
        cout << "Arquivo nao encontrado" << endl;
        entrada.close();
        throw new invalid_argument("Arquivo nao encontrado");
        return NULL; // Sera que devo deixar sem? Ele nao fala pra retornar nada
    }

    Rede* rede = new Rede();

    while (entrada) { // Enquanto tiver texto no arquivo


        // Leitura dos roteadores

        int qtdDeRoteadores;
        entrada >> qtdDeRoteadores; // Primeira linha do texto

        Roteador** roteadores = new Roteador*[qtdDeRoteadores]; // Cria um vetor de roteadores (nao sei se precisa, mas implementei assim)

        int enderecoDoRoteador;

        for(int i = 0; i < qtdDeRoteadores; i++){ // Le os enderecos dos roteadores
            entrada >> enderecoDoRoteador;
            roteadores[i] = new Roteador(enderecoDoRoteador);
            rede->adicionar(roteadores[i]); // Adiciona na rede este roteador com este endereco
        }
        //---------------------------------------------------------------------------------------

        // Leitura dos Hospedeiros
        int qtdDeHospedeiros;
        entrada >> qtdDeHospedeiros; // Le a quantidade de hospedeiros

        int endereco, gateway, qtdDeProcessos;

        Hospedeiro** hospedeiros = new Hospedeiro*[qtdDeHospedeiros]; // Vetor (tambem nao sei se precisa)

        for(int i = 0; i < qtdDeHospedeiros; i++){ // Le as informacoes dos Hospedeiros
            entrada >> endereco;
            entrada >> gateway;
            entrada >> qtdDeProcessos;

            Roteador* rotGateway = new Roteador(endereco);

            hospedeiros[i] = new Hospedeiro(endereco, rotGateway);

            for(int j = 0; j < qtdDeProcessos; j++){ // Le os processos contidos em cada hospedeiro

                string tipoDeProcesso;
                entrada >> tipoDeProcesso; // Pode ser um servidor ou um navegador

                int porta;
                string conteudoServer;

                if(tipoDeProcesso == "w"){ // eh um serverWeb
                    entrada >> porta;
                    entrada >> conteudoServer;
                    hospedeiros[i]->adicionarServidorWeb(porta, conteudoServer); // Adiciona o servidor no hospedeiro
                }

                if(tipoDeProcesso == "n"){ // eh um navegador
                    entrada >> porta;
                    hospedeiros[i]->adicionarNavegador(porta); // Adiciona o navegador no hospedeiro

                }

            }

          rede->adicionar(hospedeiros[i]); // Adiciona o hospedeiro, com seus processos, na rede

        }
        //---------------------------------------------------------------------------------------

        // Leitura da Tabela de Repasse:

        int roteadorLido, roteadorPadrao, qtdDeMap;

        Roteador* rotParaMapear;

        while(1){ //Nao sei se como que verifica a linha vazia


            entrada >> roteadorLido;
            entrada >> roteadorPadrao;
            entrada >> qtdDeMap;


            for(int i = 0; i < qtdDeRoteadores; i++){ // Busca pelo roteador que iremos mapear
                if(roteadores[i]->getEndereco() == roteadorLido){ // Atraves do endereco
                    rotParaMapear = roteadores[i]; // Encontrou, obtem o ponteiro
                    i = qtdDeRoteadores; // Sai do for

                     Roteador* rotPadrao = new Roteador(roteadorPadrao);
                     rotParaMapear->getTabela()->setPadrao(rotPadrao); // Seta o padrao da tabela de repasse do roteador
                }
            }


            int enderecoDoNo, destino;

            for(int i = 0; i < qtdDeMap; i++){ // Le os mapeamentos do roteador lido
                entrada >> enderecoDoNo;
                entrada >> destino;

                rotParaMapear->getTabela()->mapear(enderecoDoNo, rede->getNo(destino));
            }
        }

        //---------------------------------------------------------------------------------------

        // Nao sei se a ultima linha do arquivo precisa ser lida, ou se tudo bem se nao for.

    }

    entrada.close();

    return rede;
}
