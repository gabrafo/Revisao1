#include <iostream>
using namespace std;

/*
Programa que lê os dados (nome e data de nascimento) de n pessoas e determina o nome da pessoa mais velha. Em caso de empate, a resposta é a pessoa que apareceu primeiro na entrada dos dados. Cada pessoa é representada por um registro, onde a data de nascimento é um registro separado com dia, mês e ano.

Entrada:
    - A quantidade de pessoas/idades a serem processadas (um número inteiro).
    - O nome e idade de cada pessoa.

Saída:
    - Após uma comparação, exibe o nome da pessoa mais velha.
*/

struct nome{
    string nome;
};

struct birth{
    int dia, mes, ano;
};

int main(){
    int tam;
    cin >> tam;

    nome pessoa[tam];
    birth niver[tam];

    for(int i = 0; i<tam; i++){
    cin >> pessoa[i].nome >> niver[i].dia >> niver[i].mes >> niver[i].ano;
    }

    nome olderName = pessoa[0];
    birth older = niver[0];

    for(int i = 0; i<tam; i++){
    if (niver[i].ano<older.ano){ // Checa se é mais velho por ano
        olderName = pessoa[i];
    } else if (niver[i].ano == older.ano and niver[i].mes < older.mes){ // Checa se é mais velho por mês
        olderName = pessoa[i];
    } else if (niver[i].ano == older.ano and niver[i].mes == older.mes and niver[i].dia>older.dia){
        olderName = pessoa[i];
    } else if (niver[i].ano == older.ano and niver[i].mes == older.mes and niver[i].dia == older.dia){
        pessoa[i] = olderName;
    }
    }

    cout << olderName.nome << endl;

    return 0;
}