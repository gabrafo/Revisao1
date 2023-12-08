    #include <iostream>
    #include <fstream>
    #include <iomanip>
    using namespace std;

    /*
    Programa que lê informações de um arquivo texto "entrada.txt" sobre um carro (marca, ano, distância percorrida e consumo de combustível na última viagem). Com base nesses dados, calcula e grava em "saida.txt" a marca, ano, consumo e o desempenho em quilômetros por litro do carro.

    Entradas (conteúdo do arquivo "entrada.txt"):
        - Marca do carro (string sem espaços).
        - Ano de fabricação (int).
        - Distância percorrida na última viagem (float).
        - Consumo de combustível na última viagem (float).

    Saída (conteúdo do arquivo "saida.txt"):
        - Marca do carro.
        - Ano de fabricação do carro.
        - Consumo de combustível na última viagem.
        - Desempenho em quilômetros por litro.

    Obs.: Assume-se que o carro sempre consumiu alguma quantidade de combustível.
    */

    struct info{
        string nome;
        int ano;
        float dist, consumo; // KM e L respectivamente
    };

    void kmPorL(info*& carro, ofstream &arqOUT, int i){
        arqOUT << carro[i].nome << endl << carro[i].ano << endl << carro[i].consumo << endl << fixed << setprecision(2) << carro[i].dist/carro[i].consumo << endl;
    }

    void realocaVetor(info*& carro, int &cap, int size){
    cap+=1;
    info* novoCarro = new info[cap];
    for (int i = 0; i<size; i++){
        novoCarro[i] = carro[i];
    }
    delete[] carro;
    carro = novoCarro;
    }

    int main(){
        ifstream arqIN;
        ofstream arqOUT;
        arqIN.open("entrada.txt");
        arqOUT.open("saida.txt");
        int cap = 1;
        info* carro = new info[cap];
        int i = 0;
        while(arqIN >> carro[i].nome >> carro[i].ano >> carro[i].dist >> carro[i].consumo){
        if (i==cap-1){
            realocaVetor(carro, cap, i+1);
        }
        kmPorL(carro, arqOUT, i);
        i++;
        }
        arqIN.close();
        arqOUT.close();
        delete[] carro;
        return 0;
    }