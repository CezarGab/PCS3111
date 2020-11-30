#include "Navegador.h"

Navegador::Navegador(int endereco, int porta, Roteador* gateway) : Processo(endereco, porta, gateway)
{
   conteudo = "";
   esperandoPorResposta = false; // Variavel que diz se este navegador esta aguardando por resposta
}

Navegador::~Navegador() // DÚVIDA: "Nao destrua o gateway", sera que eh pra destruir algo?
{

}

void Navegador::abrir(int endereco, int porta){

//      "o Datagrama e o Segmento criados devem ter como
//      origem o endereço do Hospedeiro e a porta do Processo, ambos definidos no construtor. O destino
//      deve ser o endereço e a porta informados como parâmetros do método "

//      "Em relação ao conteúdo, use sempre o texto “GET”"


        Segmento* segmentoParaEnviar = new Segmento(this->porta, porta, "GET");
        Datagrama* datagramaParaEnviar = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), segmentoParaEnviar);
                                                                                        //  "No TTL, use o que está definido no método getTtlPadrao. "
        esperandoPorResposta = true;   // "o Navegador deve ficar esperando pela resposta"


        // DÚVIDA: O que faco agora para enviar o datagrama ao gateway?

}

void Navegador::abrir(int endereco){ // Igual o metodo acima, mas usa uma porta padrao no segmento

        Segmento* segmentoParaEnviar = new Segmento(this->porta, 80, "GET"); // "– no método que não recebe a
                                                                             //  porta, use como destino a porta 80."
        Datagrama* datagramaParaEnviar = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), segmentoParaEnviar);


        esperandoPorResposta = true;

        // DÚVIDA: O que faco agora para enviar o datagrama ao gateway?
}

void Navegador::receber(int origem, Segmento* mensagem){
    if(esperandoPorResposta){
        conteudo = mensagem->getDado(); // "Caso esteja esperando, o conteúdo do Segmento deve ser armazenado de modo que o método
                                        // getConteudo retorne agora o seu valor. "

        esperandoPorResposta = false; // "ao receber um Segmento esperado o Navegador
                                      // não deve mais ficar esperando por uma resposta"
    }


    // IMPRESSOES DEVEM SER FEITAS EM TELA DEPOIS, CONFORME SECAO 4.1.
}

string Navegador::getConteudo(){
        if(esperandoPorResposta){ // "Caso o Navegador esteja esperando pela resposta (ou seja, o método abrir foi chamado, mas a
                                  // resposta ainda não foi recebida), esse método deve retornar a string vazia (“”)."
            conteudo = "";
        }

        return conteudo;
}
