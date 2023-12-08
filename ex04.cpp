#include <iostream>
using namespace std;

/*
Este programa calcula a massa molecular de um hidrocarboneto, um composto formado por átomos de carbono e hidrogênio.
O usuário informa a quantidade de átomos de carbono e hidrogênio no composto. Com base na massa molecular do carbono (12) e do
hidrogênio (1), o programa realiza o cálculo e exibe a massa molecular total do hidrocarboneto.
*/

struct hidrocarboneto{
    int C, H;
};

int main(){
    hidrocarboneto* HC = new hidrocarboneto;

    cin >> HC->C >> HC->H;
    cout << HC->C*12+HC->H << endl;

    delete HC;
    return 0;
}