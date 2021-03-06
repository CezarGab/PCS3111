#include "Navegador.h"

Navegador::Navegador(int endereco, int porta, Roteador* gateway) : Processo(endereco, porta, gateway)
{
   conteudo = "";
   esperandoPorResposta = false; // Variavel que diz se este navegador esta aguardando por resposta
}

Navegador::~Navegador()
{

}

void Navegador::abrir(int endereco, int porta){

//      "o Datagrama e o Segmento criados devem ter como
//      origem o endere�o do Hospedeiro e a porta do Processo, ambos definidos no construtor. O destino
//      deve ser o endere�o e a porta informados como par�metros do m�todo "

//      "Em rela��o ao conte�do, use sempre o texto �GET�"

        Segmento* segmentoParaEnviar = new Segmento(this->porta, porta, "GET");
        Datagrama* datagramaParaEnviar = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), segmentoParaEnviar);
                                                                                        //  "No TTL, use o que est� definido no m�todo getTtlPadrao. "
        esperandoPorResposta = true;   // "o Navegador deve ficar esperando pela resposta"

//        cout << "Enviando para o roteador gateway" << endl;
        gateway->receber(datagramaParaEnviar);
        conteudo = "";

}

void Navegador::abrir(int endereco){ // Igual o metodo acima, mas usa uma porta padrao no segmento

        Segmento* segmentoParaEnviar = new Segmento(this->porta, 80, "GET"); // "� no m�todo que n�o recebe a
                                                                             //  porta, use como destino a porta 80."
        Datagrama* datagramaParaEnviar = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), segmentoParaEnviar);


        esperandoPorResposta = true;

//        cout << "Enviando para o roteador gateway" << endl;
        gateway->receber(datagramaParaEnviar);
        conteudo = "";
}

void Navegador::receber(int origem, Segmento* mensagem){
    if(esperandoPorResposta){
        conteudo = mensagem->getDado(); // "Caso esteja esperando, o conte�do do Segmento deve ser armazenado de modo que o m�todo
                                        // getConteudo retorne agora o seu valor. "

        cout << "Navegador" << this->porta << endl;
        cout << "\tRecebido de " << origem << ":" << mensagem->getPortaDeOrigem() << ": " << conteudo << endl; // D�VIDA: REVISAR ISSO AQUI (IMPORTANTE DEMAIS, nao entendi se eh isso mesmo)

        esperandoPorResposta = false; // "ao receber um Segmento esperado o Navegador
                                      // n�o deve mais ficar esperando por uma resposta"
    }

    cout << "Navegador" << this->porta << endl;
    cout << "\tMensagem ignorada " << origem << ":" << mensagem->getPortaDeOrigem() << ": " << conteudo << endl; // D�VIDA: REVISAR ISSO AQUI (IMPORTANTE DEMAIS, nao entendi se eh isso mesmo)



}

string Navegador::getConteudo(){
        if(esperandoPorResposta){ // "Caso o Navegador esteja esperando pela resposta (ou seja, o m�todo abrir foi chamado, mas a
                                  // resposta ainda n�o foi recebida), esse m�todo deve retornar a string vazia (��)."
            conteudo = "";
        }

        return conteudo;
}
