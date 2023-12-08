#include <iostream>
using namespace std;

/*
O programa organiza os dados de um bolão da Copa, armazenando registros de times com seu número, nome e gols marcados. Ele oferece três módulos: um para ler os valores preenchendo um vetor de registros, outro para ordenar os elementos desse vetor por número do time (usando Shell sort), e o último para procurar um elemento no vetor usando busca sequencial e retornar sua posição, nome e gols marcados.
*/

struct info{
    int num;
    string nome;
    int gols;
};

void leTime(info time[], int tam){
    for(int i = 0; i<tam; i++){
        cin >> time[i].num >> time[i].nome >> time[i].gols;
    }
}

void shellSort(info time[], int tam){
    const int ciuraGaps[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int pos_gap = 8;

    while (ciuraGaps[pos_gap] > tam) {
    pos_gap--;
    }

    while (pos_gap >= 0) {
    int gap = ciuraGaps[pos_gap];

    for (int i = gap; i < tam; i++) {
      info temp = time[i];
      int j = i;
      while (j >= gap and time[j - gap].num > temp.num) {
        swap(time[j], time[j - gap]);
        j -= gap;
      }
      time[j] = temp;
    }

    pos_gap--;
    }
}

void buscaSequencial(info time[], int tam, int wanted){
    bool achou = false;
    for(int i = 0; i<tam; i++){
        if(time[i].num==wanted){
            cout << i << endl;
            cout << time[i].nome << " " << time[i].gols << endl;
            achou = true;
        }
    }
    if(not achou){
        cout << -1 << endl;
    }
}

int main(){
    int tam, wanted;
    cin >> tam;
    info time[tam];
    leTime(time, tam);
    shellSort(time, tam);
    cin >> wanted;
    buscaSequencial(time, tam, wanted);

    return 0;
}