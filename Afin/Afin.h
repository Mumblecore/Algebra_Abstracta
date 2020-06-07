
#ifndef AFIN_H
#define AFIN_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

using namespace std;

class Afin
{
    private:
        int a;
        int b;
    public:
        Afin();
        Afin(int, int);
        string alf;
        string cifrar(string);
        string descifrar(string);
};

Afin::Afin()
{
    alf = " ETAOINSRHDLUCMFYWGPBVKXQJZ.";
    int tam = alf.size();
    srand(time(NULL));
    a = mod(rand(), (tam - 1) + 1);
    while(gcd(a,tam) != 1)
    {
        srand(time(NULL));
        a = mod(rand(), (tam - 1) + 1);
    }
    srand(time(NULL));
    b = mod(rand(), (tam - 1) + 1);
}

Afin::Afin(int _a, int _b)
{
    alf = " ETAOINSRHDLUCMFYWGPBVKXQJZ.";

    a = inversa(_a, alf.size());
    b = _b;
}

string Afin::cifrar(string msg)
{
    string msg_cif;
    int tam = msg.size();
    for(int i = 0; i < tam; i++)
    {
        int lpos = alf.find(msg[i]);
        msg_cif += alf[mod(((lpos * a) + b), alf.size())];
    }
    return msg_cif;
}

string Afin::descifrar(string msg)
{
    string msg_des;
    int tam = msg.size();
    for(int i = 0; i < tam; i++)
    {
        int lpos = alf.find(msg[i]);
        msg_des += alf[mod(((lpos - b) * a), alf.size())];
    }
    return msg_des;
}

#endif