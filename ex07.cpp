#include <iostream>
using namespace std;

/*
O código abaixo implementa uma variação do algoritmo de ordenação Selection Sort para ordem decrescente.
*/

void selectionSort(int vetor[], int tam){
    int posMenor, aux;
    for(int i = 0; i<tam-1; i++){
        posMenor = i;
        for (int j = i+1; j<tam; j++){
            if(vetor[j]>vetor[posMenor]){
                posMenor = j;
            }
        }
    aux = vetor[i];
    vetor[i] = vetor[posMenor];
    vetor[posMenor] = aux;
    for (int k = 0; k<tam-1; k++){
        cout << vetor[k] << " ";
    }
    cout << vetor[tam-1] << endl;
    }
}

int main(){
    int tam;
    cin >> tam;
    int vetor[tam];

    for (int i = 0; i<tam; i++){
        cin >> vetor[i];
    }

    selectionSort(vetor, tam);

    return 0;
}