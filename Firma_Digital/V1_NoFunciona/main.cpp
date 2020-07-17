#include "Rsa.h"

using namespace std;

int main()
{
    int bits;
    cout << "Nro de bits: ";
    cin >> bits;

    RSA Receptor(bits);
    RSA Emisor(bits);

    cout << "Mensaje: ";
    string msg;
    cin.ignore();
    getline(cin, msg);

    // cout << Emisor.cifrar(msg, Receptor.N, Receptor.e) << endl;
    // cout << Receptor.descifrar(Emisor.cifrar(msg, Receptor.N, Receptor.e)) << endl;

    string msg_cifrado = Emisor.cifrar_y_firmar(msg, Receptor.N, Receptor.e);

    // cout << "M: " << msg_cifrado << endl;
    cout << "D: " << Receptor.descifrar_y_confirmar(msg_cifrado, Emisor.N, Emisor.e) << endl;

    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm
