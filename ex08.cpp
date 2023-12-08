#include <iostream>
#include <fstream>
using namespace std;

/*
A Operação Lava Jato investiga corrupção no Brasil. O juiz precisa organizar informações de políticos envolvidos, contidas no arquivo "relacao_desvios.txt", que inclui nome do político, partido e valor desviado dos cofres públicos. O programa lê o arquivo e exibe os nomes dos políticos em ordem decrescente dos valores desviados. Este código utiliza o algoritmo de ordenação Selection-Sort e assume que cada linha do arquivo contém um único político, partido e valor desviado, sem espaços nos nomes ou partidos.
*/

struct dados{
    string nome;
    string partido;
    float din;
};

void selectionSort(dados corrupto[], int tam){
    int posMenor;
    dados aux;
    for(int i = 0; i<tam-1; i++){
        posMenor = i;
        for (int j = i+1; j<tam; j++){
            if(corrupto[j].din>corrupto[posMenor].din){
                posMenor = j;
            }
        }
    aux = corrupto[i];
    corrupto[i] = corrupto[posMenor];
    corrupto[posMenor] = aux;
    }
}


int main(){
    ifstream arq;
    arq.open("relacao_desvios.txt");
    dados corrupto[100];
    int i = 0, size = 0;
    while(arq >> corrupto[i].nome >> corrupto[i].partido >> corrupto[i].din){
        i++;
    }
    size=i;
    selectionSort(corrupto, size);

    for(int i = 0; i<size; i++){
        cout << corrupto[i].nome << endl;
    }

    arq.close();
    return 0;
}