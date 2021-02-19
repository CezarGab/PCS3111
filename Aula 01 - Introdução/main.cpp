/* Aula 01 - LabOO
Cezar Gabriel */
#include <iostream>

using namespace std;


int calculaPontuacao(int posicao, bool participou){

    /* 1º lugar: 7 pontos
    2º lugar: 5 pontos
    3º lugar: 4 pontos
    4º lugar: 3 pontos
    5º lugar: 1 pontos
    6º lugar em diante: 0 pontos
    */
    if (posicao > 5 || participou == false){
        return 0;
    }
    if (posicao == 1){
        return 7;
    }
    if (posicao == 2){
        return 5;
    }
    if (posicao == 3){
        return 4;
    }
    if (posicao == 4){
        return 3;
    }
    if (posicao == 5){
        return 1;
    }

    return 0;

}

int calculaPontuacaoFinal(int posicoes[], bool participou[], int quantidade){
    int pontuacao_total = 0;
    int i;

    for(i = 0; i < quantidade; i++){
        pontuacao_total += calculaPontuacao(posicoes[i], participou[i]);
    }

    return pontuacao_total;
}

bool nomesIguais(string nomes[], int quantidade){ /* A função retorna true caso exista pelo menos um nome
                                                    repetido no vetor e false caso não existam nomes repetidos. */
    int i, j;

    for(i = 0; i < quantidade; i++){
        for(j = 0; j < quantidade; j++){
            if(i != j){
                if(nomes[i] == nomes[j]){
                    return true;
                }
            }
        }

    }
        return false;

}

/*
int main()
{
    int posicoes[3] = {3, 1, 1};
    bool participou[3] = {true, true, false};
    string nomes[5] = { "Poli", "FEA", "ECA", "FFLCH", "Poli" };
    string nomes2[7] = { "ECA", "Poli", "FEA", "Poli", "FEA", "FFLCH", "FEA" };
    string nomes3[5] = {"Poli", "FEA", "ECA", "FFLCH", "EACH"};
    int quantidade = 5;


    cout << calculaPontuacao(1, true) << endl;
    cout << calculaPontuacao(2, true) << endl;
    cout << calculaPontuacao(3, true) << endl;
    cout << calculaPontuacao(4, true) << endl;
    cout << calculaPontuacao(5, true) << endl;
    cout << calculaPontuacao(6, true) << endl;
    cout << calculaPontuacao(2, false) << endl;



    cout << calculaPontuacaoFinal(posicoes, participou, 3) << endl;



    cout <<  nomesIguais(nomes, quantidade) << endl;
    cout <<  nomesIguais(nomes2, 7) << endl;
    cout <<  nomesIguais(nomes3, 5) << endl;


    return 0;
}
*/
