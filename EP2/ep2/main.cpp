#include <iostream>
#include "Segmento.h"
#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "No.h"
#include "Roteador.h"
#include "Processo.h"

using namespace std;

int main()
{
    Segmento* s1 = new Segmento(2, 4, "Dado s1");
    Fila* f1 = new Fila(3);
    Datagrama* d1 = new Datagrama(2, 5, 3, s1);

    cout << "Deve ser 1 (fila vazia): " << f1->isEmpty() << endl;

    f1->enqueue(d1);

    cout << "Deve ser 0 (fila com segmento): " << f1->isEmpty() << endl;

    return 0;
}
