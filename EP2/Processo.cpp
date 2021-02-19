#include "Processo.h"

int Processo::ttlPadrao = 5; // Atributo estatico, que comeca com 5

Processo::Processo(int endereco, int porta, Roteador* gateway) : endereco(endereco),
                                                                porta(porta), gateway(gateway)
{
}

Processo::~Processo()
{
  // "nao destrua o gateway"
}


int Processo::getEndereco(){
    return endereco; // Retorna o valor do endereco
}


int Processo::getPorta(){
    return porta; // Retorna a porta
}

void Processo::setTtlPadrao(int padrao){
    Processo::ttlPadrao = padrao; // Muda o padrao, que eh estatico
}

int Processo::getTtlPadrao(){
    return Processo::ttlPadrao; // Retorna o padrao atual que esta sendo utilizado
}

void Processo::imprimir(){

}
