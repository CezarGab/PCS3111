#include <iostream>
#include <string.h>
#ifndef EQUIPE_H
#define EQUIPE_H

using namespace std;

class Equipe {
private:


protected:
    string nome;
    int membros;

public:
    string getNome();
    int getMembros();
    Equipe(string nome, int membros);
    virtual ~Equipe();

    void imprimir();


};

#endif
