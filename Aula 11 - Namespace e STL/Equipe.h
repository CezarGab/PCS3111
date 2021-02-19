#ifndef EQUIPE_H
#define EQUIPE_H
#include <string>

using namespace std;

class Equipe {
public:
    Equipe(string nome);
    virtual ~Equipe();

    string getNome();
private:
    string nome;
};

#endif // EQUIPE_H
