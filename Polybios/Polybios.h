#ifndef POLYBIOS_H
#define POLYBIOS_H

#include <string>
#include <iostream>

using namespace std;

class Polybios
{
public:
    Polybios();
    string alfabeto;
    string Cifrar(string);
    string Descifrar(string);
};

Polybios::Polybios()
{
    alfabeto = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
}

string Polybios::Cifrar(string msg)
{
    string msg_cif;
    for(int i = 0; i < msg.size(); i++)
    {
        int c = alfabeto.find(msg[i]);
        msg_cif += alfabeto[c/5];
        msg_cif += alfabeto[c%5];
    }
    return msg_cif;
}

string Polybios::Descifrar(string msg)
{
    string msg_des;
    for(int i = 0; i < msg.size(); i+=2)
    {
        int a = alfabeto.find(msg[i]);
        int b = alfabeto.find(msg[i+1]);
        msg_des += alfabeto[(5*a)+b];
    }
    return msg_des;
}

#endif