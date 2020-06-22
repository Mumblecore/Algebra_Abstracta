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
    int alf_char_size = 3;
    RSA(long bits);
    RSA(ZZ _N, ZZ _e);

    string cifrar(string msg);
    string descifrar(string msg);

    ZZ N;
    ZZ e;
    int b;
};

RSA::RSA(long bits)
{
    ZZ p(primo(bits));
    ZZ q(primo(bits));

    b = bits;

    N = p*q;                    //va a tener 2*bits bits
    ZZ phi_N = (p-1)*(q-1);     //igual

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

string RSA::cifrar(string msg)
{
    string msg2;
    string msg_cif;

    for(int i = 0; i < msg.size(); i++)
    {
        int j = alf.find(msg[i]);
        msg2 += '0';
        if(alf.find(msg[i]) < 10)
            msg2 += '0';
        msg2 += msg[i];
    }

    ZZ Bits(1);
    Bits <<= (b-1)*2;

    int tam_bloque = Bits.size() - 1;

    for(int i = 0; i < msg2.size(); i+=tam_bloque)
    {
        string bloque;
        for(int j = 0; j < tam_bloque; j++)
        {
            bloque += msg2[j];
        }
        ZZ p = conv<string>(bloque);
        
    }

    //long p = alf.find(msg[0]);
    //ZZ P(p);

    return msg2;

    //return expomod(P,e,N);
}

string RSA::descifrar(string msg)
{
    ZZ Q = expomod(msg,d,N);
    long q = conv<long>(Q);

    string msg_des;
    msg_des += alf[q];
    return msg_des; 
}

#endif