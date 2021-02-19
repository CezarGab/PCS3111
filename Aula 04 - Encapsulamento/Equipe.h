#include <string>
using namespace std;

#ifndef EQUIPE_H
#define EQUIPE_H

class Equipe {
    private:
        string nome;
        int numeroDeMembros = 0;

    public:
        string getNome();
        int getNumeroDeMembros();
        void setNome(string nome);
        void setNumeroDeMembros(int membros);

        int getMaximoDeTorcedores();
        void imprimir();
};

#endif // EQUIPE_H


