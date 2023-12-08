#include <iostream>
using namespace std;

/*
No algoritmo original, foi feita uma implementação do algoritmo Selection Sort para ordenação em ordem crescente. O seu objetivo é adaptar esse algoritmo para ordenar parcialmente o vetor em ordem decrescente até uma posição específica.

for (int i=0; i < tam-1; ++i) {
    posMenor = i;
    for (int j=i+1; j < tam; ++j) {
        if (vetor[j] < vetor[posMenor])
            posMenor = j;
    }
    aux = vetor[i];
    vetor[i] = vetor[posMenor];
    vetor[posMenor] = aux;
}
*/

void selectionSort(int vetor[], int tam, int posMax){
    int posMenor, aux;
    for (int i=0; i < posMax; ++i) {
    posMenor = i; 
    cout << "i: " << i << endl;
    cout << "posMenor: " << posMenor << endl;
    for (int j=i+1; j < tam; ++j) { 
        if (vetor[j] > vetor[posMenor]){
            cout << "j: " << j << endl;
            posMenor = j;
            cout << "posMenor trocada: " << posMenor << endl;
            cout << "vetor[posMenor]: " << vetor[posMenor] << endl;
        }
    }
    aux = vetor[i];
    vetor[i] = vetor[posMenor];
    vetor[posMenor] = aux;
    cout << "vetor[i]: " << vetor[i] << endl;
    cout << "vetor[posMenor]: " << vetor[posMenor] << endl;

    for(int i = 0; i < tam; i++){
    cout << vetor[i] << " ";
    }
    cout << endl;
}
}

int main(){
    int tam;
    cin >> tam;
    int vetor[tam], posMax;
    for(int i = 0; i < tam; i++){
        cin >> vetor[i];
    }
    cin >> posMax;
    selectionSort(vetor, tam, posMax);

    return 0;
}

/*

for (int i=0; i < tam-1; ++i) {
    posMenor = i;
    for (int j=i+1; j < tam; ++j) {
        if (vetor[j] < vetor[posMenor])
            posMenor = j;
    }
    aux = vetor[i];
    vetor[i] = vetor[posMenor];
    vetor[posMenor] = aux;
}

5 
1 3 4 5 2
2

i: 0
posMenor: 0
j: 1
posMenor trocada: 1
vetor[posMenor]: 3
j: 2
posMenor trocada: 2
vetor[posMenor]: 4
j: 3
posMenor trocada: 3
vetor[posMenor]: 5
vetor[i]: 5
vetor[posMenor]: 1
5 3 4 1 2 

i: 1
posMenor: 1
j: 2
posMenor trocada: 2
vetor[posMenor]: 4
vetor[i]: 4
vetor[posMenor]: 3
5 4 3 1 2 

*/