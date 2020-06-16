#include "Rsa.h"

using namespace std;

int main()
{
    RSA Receptor;
    RSA Emisor(Receptor.N, Receptor.e);

    string msg = "G";
    ZZ msg_cifrado = Emisor.cifrar(msg);

    cout << msg_cifrado << endl;
    cout << Receptor.descifrar(msg_cifrado) << endl;

    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm
