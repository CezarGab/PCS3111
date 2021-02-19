#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include <string>

using namespace std;

class Participante {
public:
    Participante(string nome);
    virtual ~Participante();

    virtual void imprimir();
    virtual string getNome() = 0; // Se eh igual a 0, eh abstrato
    /* Crie os atributos necessarios */
private:
    string nome;
};

#endif // PARTICIPANTE_H
