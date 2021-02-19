#ifndef EQUIPE_H
#define EQUIPE_H
#include <string>
#include <iostream>

using namespace std;

class Equipe {
public:
    Equipe(string nome, int membros);
    ~Equipe();

    string getNome();
    int getMembros();

    int getMaximoDeTorcedores();
    void imprimir();

private:
    string nome;
    int membros;
};

#endif // EQUIPE_H
