#ifndef SERVIDORWEB_H
#define SERVIDORWEB_H
#include "Processo.h"

class ServidorWeb : public Processo
{
    public:
       ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo);
        virtual ~ServidorWeb();

        void receber(int origem, Segmento* mensagem);

    protected:
        string conteudo;
};

#endif // SERVIDORWEB_H
