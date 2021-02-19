#include <iostream>
#include <string>

using namespace std;


// FACA OS INCLUDES NECESSARIOS

string* encontrarOponente(string nomes[], int membros[], int quantidade, string nomeEquipe, int membrosEquipe) {
    // IMPLEMENTE A FUNCAO
    int i;
    int j = 0;


    for (i = 0; i < quantidade; i++){
        if (nomeEquipe != nomes[i] && membrosEquipe == membros[i]){
            j = i;
        }
    }

    if (nomeEquipe != nomes[j] && membrosEquipe == membros[j]){
            return &nomes[j];
        }

    return NULL;

}


int calcularEstatisticas (int membros[], int quantidade, int* minimo, int& maximo) {
    // IMPLEMENTE A FUNCAO
    *minimo = 0;
    maximo = 0;
    int i;
    int soma;

    if (quantidade > 0){
        *minimo = membros[0];
    }
    for (i = 0; i < quantidade; i++){
        if (membros[i] < *minimo){
            *minimo = membros[i];
        }

        if (membros[i] > maximo){
            maximo = membros[i];
        }
    }

    soma = *minimo + maximo;
    return soma;

}


/* COMENTE A MAIN PARA SUBMETER */
//int main() {
//    /* string *p = &s; */ //aponta para o endereco
//    // FACA TESTES NA MAIN
//    string* saida;
//    int minimo = 0;
//    int maximo = 0;
//    int s;
//
//    string nomes[3] = { "Poli", "FEA", "ESALQ" };
//    int numeros[3] = { 10, 9, 10 };
//    // nomes = {“Poli”, “FEA”, “ESALQ”}, membros = {10, 9, 10}
//
//
//    saida = encontrarOponente(nomes, numeros, 3, "Poli", 10);
//
//    cout << saida << endl;
//
//
//    s = calcularEstatisticas(nomes, 3, minimo, maximo);
//
//    cout << s << endl;
//    cout << &minimo << endl;
//    cout << maximo << endl;
//
//    return 0;
//}

//*/
