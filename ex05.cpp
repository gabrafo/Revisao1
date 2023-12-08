#include <iostream>
#include <fstream>
using namespace std;

/*
O código em questão trata-se de um programa em C++ que lê um arquivo chamado "fases.txt" contendo informações sobre diferentes
fases da Operação Lava Jato, que são representadas por um número e um nome. Em seguida, o programa recebe um número K da entrada
padrão e exibe na saída padrão os nomes das K primeiras operações presentes no arquivo, ordenadas de forma decrescente pelo
número da operação, e as demais em ordem crescente.
O programa utiliza o método Insertion Sort para ordenar as fases lidas do arquivo, sem fazer uso de vetores auxiliares. As
entradas são o arquivo "fases.txt" e um número K, e as saídas são os nomes das fases organizadas de acordo com o critério
mencionado.
*/

struct fases{
    int num;
    string nome;
};

void insertionSortD(fases* lavaJato, int size){
    int valorPivo, j;
    string nomePivo;
    for(int i = 1; i<size; i++){ // Checa da segunda até a última posição do vetor
        valorPivo = lavaJato[i].num; // O valor do pivô é o valor contido no elemento de posição I
        nomePivo = lavaJato[i].nome;
        j = i-1; // J começa em zero
        while((j>=0) and (valorPivo>lavaJato[j].num)){
            lavaJato[j+1] = lavaJato[j];
            j--;
        }
        lavaJato[j+1].num = valorPivo;
        lavaJato[j+1].nome = nomePivo;
    }
}

void insertionSortC(fases* lavaJato, int size, int k){
    int valorPivo, j;
    string nomePivo;
    for(int i = k; i<size; i++){
        valorPivo = lavaJato[i].num;
        nomePivo = lavaJato[i].nome;
        j = i-1;
        while((j>=0) and (valorPivo<lavaJato[j].num)){
            lavaJato[j+1] = lavaJato[j];
            j--;
        }
        lavaJato[j+1].num = valorPivo;
        lavaJato[j+1].nome = nomePivo;
    }
}

void realocaVet(fases*& lavaJato, int& cap){
    cap*=2;
    fases* novaLavaJato = new fases[cap];
    for(int i = 0; i<cap/2; i++){
        novaLavaJato[i] = lavaJato[i];
    }
    delete[] lavaJato;
    lavaJato = novaLavaJato;
}

int main(){
    ifstream arq;
    arq.open("fases.txt");

    int cap = 1, i = 0, size = 0;

    fases* lavaJato = new fases[cap];

    while(arq >> lavaJato[i].num >> lavaJato[i].nome){
        if(i==cap-1){
            realocaVet(lavaJato, cap);
        }
        i++;
    }
    size=i;

    int k;

    cin >> k;

    if(k>size){
        k = size;
    }else if (k<0){
        k = 0;
    }

    insertionSortD(lavaJato, k);
    insertionSortC(lavaJato, size, k);

    for (int i = 0; i<size; i++){
        cout << lavaJato[i].nome << endl;
    }

    arq.close();
    delete[] lavaJato;
    return 0;
}