#include <iostream>
using namespace std;

/*
Programa que calcula a pontuação de um país nas Olimpíadas com base em uma tabela de pontuação proposta pelo Comitê Olímpico Internacional (COI). O usuário informa a quantidade de pontos atribuídos para cada tipo de medalha (ouro, prata e bronze) e a quantidade de medalhas conquistadas por um país (ouro, prata e bronze, respectivamente). O programa calcula a pontuação total do país conforme a tabela de pontuação do COI.

Entradas:
    - Três números inteiros representando a pontuação de ouro, prata e bronze, respectivamente.
    - Três números inteiros representando a quantidade de medalhas de ouro, prata e bronze conquistadas pelo país.

Saídas:
    - A pontuação total do país de acordo com a tabela proposta pelo COI.
*/

struct lista{
    int ouro, prata, bronze;
};

int main(){
    int* pontuacao = new int[3];
    lista* medalhas = new lista;

    cin >> medalhas->ouro >> medalhas->prata >> medalhas->bronze;

    cin >> pontuacao[0] >> pontuacao[1] >> pontuacao[2];

    int resultado = pontuacao[0]*medalhas->ouro + pontuacao[1]*medalhas->prata + pontuacao[2]*medalhas->bronze;
    cout << resultado << endl;

    delete medalhas;
    delete[] pontuacao;
    return 0;
}