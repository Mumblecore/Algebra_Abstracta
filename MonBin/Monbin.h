#ifndef MONBIN_H
#define MONBIN_H

#include <string>
#include <iostream>

using namespace std;

class Monbin
{
public:
    short c1, c2;
    Monbin(string);
    string alf;
    string Cifrar(string);
    string Descifrar(string);
};

Monbin::Monbin(string clave)
{
    alf = clave;
    c1 = alf.find(" ");
    alf[c1] =  '_';
    c2 = alf.find(" ");
    alf[c2] =  '_';
    alf += "BCDFGHJKLMPQ/UVWXYZ.";
}

string Monbin::Cifrar(string msg)
{
    string msg_cif;
    for(int i = 0; i < msg.size(); i++)
    {
        int c = alf.find(msg[i]);
        if(c > 19)
            msg_cif += to_string(c2);
        if(c > 9 && c < 20)
            msg_cif += to_string(c1);
        msg_cif += to_string(c%10);
        if(c==22)
            msg_cif += msg[++i];
    }
    return msg_cif;
}

string Monbin::Descifrar(string msg)
{
    string msg_des;
    for(int i = 0; i < msg.size(); i++)
    {
        if(msg[i] - 48 == c1)
        {
            msg_des += alf[msg[++i] - 38];
        }
        else if(msg[i] - 48 == c2)
        {
            msg_des += alf[msg[++i] - 28];
            if(msg[i] - 48 == 2)
            {
                msg_des += msg[++i];
            }
        }
        else
        {
            msg_des += alf[msg[i] - 48];
        }
    }
    return msg_des;
}

#endif