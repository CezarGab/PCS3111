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
//     retornar � origem do
//    Segmento (mesmo endere�o e porta) um novo Datagrama cujo dado do Segmento � o conte�do
//    informado no construtor. Naturalmente o Datagrama e o Segmento devem possuir como origem o
//    endere�o e porta do ServidorWeb. Para retornar o pacote � origem, o ServidorWeb deve usar o
//    Roteador gateway.

    Segmento* segmentoParaEnviar = new Segmento(this->porta, mensagem->getPortaDeDestino(), this->conteudo);
    Datagrama* datagramaParaRetornar = new Datagrama(this->endereco, origem, this->getTtlPadrao(), segmentoParaEnviar);

    // E agora pra enviar esse datagrama?

     // IMPRESSOES DEVEM SER FEITAS EM TELA DEPOIS, CONFORME SECAO 4.1.
}
