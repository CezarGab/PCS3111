#ifndef PESSOA_H
#define PESSOA_H
#include "Participante.h"


class Pessoa : public Participante{
    public:
        Pessoa(string nome);
        Pessoa(string nome, int nusp);
        virtual ~Pessoa();

        virtual int getNusp();
        static int getNuspAuto();
        string getNome();

    private:
        string nome;
        int nusp;
        static int nuspAuto;
};

#endif // PESSOA_H
