#include "Datagrama.h"
#include <iostream>

int Datagrama::getOrigem(){ // Retorna o valor do endere�o de origem

    return origem;

}

int Datagrama::getDestino(){ // Retorna o valor de destino

    return destino;
}

int Datagrama::getTtl(){ // Retorna o TTL
    return ttl;
}

string Datagrama::getDado(){ // Retorna o valor no Construtor

}

void Datagrama::processar(){ // Decrementa o valor do TTL em uma unidade

    ttl = ttl - 1;

}

bool Datagrama::ativo(){ // Enquanto o TTL for maior que zero, o m�todo ativo deve retornar true.
    if(ttl =< 0){
        return false;
    }

    else{
        return true;
    }
}

void Datagrama::imprimir(){ // Implementa��o livre (n�o h� regras no enunciado)


}

