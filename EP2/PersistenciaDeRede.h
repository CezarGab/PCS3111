#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H
#include "Rede.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

#include "stdio.h"

using namespace std;


class PersistenciaDeRede
{
    public:
        PersistenciaDeRede();
        virtual ~PersistenciaDeRede();
        virtual Rede* carregar(string arquivo);

    protected:

    private:
};

#endif // PERSISTENCIADEREDE_H
