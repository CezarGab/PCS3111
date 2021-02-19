#ifndef NAVEGADOR_H
#define NAVEGADOR_H
#include "Processo.h"

class Navegador : public Processo
{
    public:
        Navegador(int endereco, int porta, Roteador* gateway);
        virtual ~Navegador();

        virtual void abrir(int endereco, int porta);
        virtual void abrir(int endereco);

        virtual string getConteudo();

        void receber(int origem, Segmento* mensagem);

    protected:
        string conteudo;
        bool esperandoPorResposta;
    private:
};

#endif // NAVEGADOR_H
