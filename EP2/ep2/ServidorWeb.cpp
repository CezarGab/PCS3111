#include "ServidorWeb.h"
#include "Segmento.h"

ServidorWeb::ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo) : Processo(endereco, porta, gateway)
{
    this->conteudo = conteudo;
}

ServidorWeb::~ServidorWeb()
{
    //dtor
}

void ServidorWeb::receber(int origem, Segmento* mensagem){
//     retornar à origem do
//    Segmento (mesmo endereço e porta) um novo Datagrama cujo dado do Segmento é o conteúdo
//    informado no construtor. Naturalmente o Datagrama e o Segmento devem possuir como origem o
//    endereço e porta do ServidorWeb. Para retornar o pacote à origem, o ServidorWeb deve usar o
//    Roteador gateway.

    Segmento* segmentoParaEnviar = new Segmento(this->porta, mensagem->getPortaDeDestino(), this->conteudo);
    Datagrama* datagramaParaRetornar = new Datagrama(this->endereco, origem, this->getTtlPadrao(), segmentoParaEnviar);

    // E agora pra enviar esse datagrama?

     // IMPRESSOES DEVEM SER FEITAS EM TELA DEPOIS, CONFORME SECAO 4.1.
}
