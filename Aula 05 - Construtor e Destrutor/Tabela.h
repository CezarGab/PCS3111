#include "Equipe.h"
#ifndef TABELA_H
#define TABELA_H

using namespace std;

class Tabela {
private:
    Equipe** participantes;
    int* pontos;
    int quantidade;

    int getIndice(Equipe* participante); // DUVIDA: por quê isso esse get tá aqui?
public:
	// Declare o construtor e o destrutor

	Tabela(Equipe** participantes, int quantidade);
    ~Tabela();

    Equipe** getParticipantes() const;
    int getQuantidade();

    void pontuar(Equipe* participante, int pontos);
    int getPontos(Equipe* participante);

    void imprimir();

};
#endif // TABELA_H
