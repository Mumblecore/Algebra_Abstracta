#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
#include <iostream>
#include "utilidades.h"

using namespace std;

class Vigenere
{
    public:
        Vigenere(string);

        string cif(string);
        string des(string);
        string alf;
        int com;

    private:
        string clave;
};

Vigenere::Vigenere(string c)
{
    clave = c;
}

string Vigenere::cif(string msg)
{
    string msg_cif;
    int lpos,cpos;
    for(int i = 0; i < msg.size(); i++)
    {
        lpos = alf.find(msg[i]) + com;
        cpos = alf.find(clave[mod(i,clave.size())]) + com;

        msg_cif += alf[mod((lpos + cpos),alf.size()+com)-com];
    }

    return msg_cif;
}

string Vigenere::des(string msg_cif)
{
    string msg_des;
    int lpos,cpos;
    for(int i = 0; i < msg_cif.size(); i++)
    {
        lpos = alf.find(msg_cif[i]) + com;
        cpos = alf.find(clave[mod(i,clave.size())]) + com;

        msg_des += alf[mod((lpos - cpos),alf.size()+com)-com];
    }

    return msg_des;
}
#endif // VIGENERE_H
