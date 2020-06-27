#ifndef RSA_H
#define RSA_H

#include <string>
#include "Extensiones.h"

using namespace std;

class RSA
{
private:
    ZZ d;
public:
    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    RSA();
    RSA(ZZ _N, ZZ _e);

    ZZ cifrar(string msg);
    string descifrar(ZZ msg);

    ZZ N;
    ZZ e;
};

RSA::RSA()
{
    ZZ p(primo());
    ZZ q(primo());

    N = p*q;
    ZZ phi_N = (p-1)*(q-1);  

    srand(time(0));
    long r = rand();
    ZZ R = conv<ZZ>(r);
    e = nmod(R, phi_N);

    while(gcd(e,phi_N) != 1)
    {
        e++;
    }
    d = inversa(e,phi_N);
}

RSA::RSA(ZZ _N, ZZ _e)
{
    N = _N;
    e = _e;
}

ZZ RSA::cifrar(string msg)
{
    long p = alf.find(msg[0]);
    ZZ P(p);

    return expomod(P,e,N);
}

string RSA::descifrar(ZZ msg)
{
    ZZ Q = expomod(msg,d,N);
    long q = conv<long>(Q);

    string msg_des;
    msg_des += alf[q];
    return msg_des; 
}

#endif