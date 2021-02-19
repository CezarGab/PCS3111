#ifndef EQUIPEREPETIDA_H
#define EQUIPEREPETIDA_H
#include <iostream>
#include <stdexcept>

using namespace std;

class EquipeRepetida : public invalid_argument
{
    public:
        EquipeRepetida(string mensagem);
        ~EquipeRepetida();
    private:
        string mensagem;
};

#endif // EQUIPEREPETIDA_H
