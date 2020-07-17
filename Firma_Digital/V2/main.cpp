#include "Rsa.h"

using namespace std;

int main()
{
    int bits;
    cout << "Nro de bits: ";
    cin >> bits;

    RSA Receptor(bits);
    RSA Emisor(bits);
    Receptor._N = Emisor.N;
    Receptor._e = Emisor.e;

    Emisor._N = Receptor.N;
    Emisor._e = Receptor.e;

    cout << "Mensaje: ";
    string msg;
    cin.ignore();
    getline(cin, msg);

    string rr = Emisor.cifrar_y_firmar(msg);
    cout << rr << endl;
    cout << Receptor.descifrar_y_confirmar(rr) << endl;

    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm
