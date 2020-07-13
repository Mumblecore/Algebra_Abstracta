#include "Rsa.h"

using namespace std;

int main()
{
    int bits;
    cout << "Nro de bits: ";
    cin >> bits;

    RSA Receptor(bits);
    RSA Emisor(Receptor.N, Receptor.e);

    cout << "Mensaje: ";
    string msg;
    cin.ignore();
    getline(cin, msg);

    bool cifrar;
    cout << "Cifrar(1) o descifrar(0): ";
    cin >> cifrar;

    if(cifrar)
        cout << Emisor.cifrar(msg) << endl;
    else
        cout << Receptor.descifrar(msg) << endl;

    cout << "Inversa: \n";
    if(cifrar)
        cout << Receptor.descifrar(Emisor.cifrar(msg)) << endl;
    else
        cout << Emisor.cifrar(Receptor.descifrar(msg)) << endl;
    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm
