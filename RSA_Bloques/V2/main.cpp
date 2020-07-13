#include "Rsa.h"

using namespace std;

int main()
{
    RSA Receptor(64);
    RSA Emisor(Receptor.N, Receptor.e);

    string msg;// = "HOLA asfha HJIsfb IUH iuhdushfidsf IHDFIUDSHF siudhfui SIDFUH isudhfuHFSD iudhf 23432-234-35";
    getline(cin, msg);
    string rpta = Emisor.cifrar(msg);
    cout << "MSG_cifrado: " << rpta << endl;
    cout << Receptor.descifrar(rpta) << endl;
    //cout << Receptor.descifrar(rpta) << endl;
    // auto t1 = Clock::now();
    // Emisor.cifrar(msg);
    // auto t2 = Clock::now();
    // cout << "tiempo: " << chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count() << endl;
    // t1 = Clock::now();
    // cout << primo(n, criba) << endl;
    // t2 = Clock::now();

    // cout << "tiempo     : " << chrono::duration_cast<std::chrono::seconds>(t2-t1).count() << endl;
    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm
