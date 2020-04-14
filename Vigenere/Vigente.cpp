#include "Vigenere.h"

Vigenere::Vigenere()
{
    alf = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
}

Vigenere::~Vigenere()
{
    //dtor
}

void Vigenere::setClave(string c)
{
    clave = c
}

string Vigenere::cif(string msg)
{
    string msg_cif;

    for(int i = 0; i < msg.size(); i++)
    {
        int lpos = alf.find(msg[i]);
        if(lpos != string::npos)
        {
            msg_cif += alf[(lpos + alf.find(clave[i%clave.size()]))%alf.size()];
        }else{
            msg_cif += msg[i];
        }
    }

    return msg_cif;
}

string Vigenere::des(string msg_cif)
{
    string msg_des;

    for(int i = 0; i < msg_cif.size(); i++)
    {
        int lpos = alf.find(msg_cif[i]);
        if(lpos != string::npos)
        {
            msg_cif += alf[(lpos - alf.find(clave[i%clave.size()]))%alf.size()];
        }else{
            msg_des += msg_cif[i];
        }
    }

    return msg_des;
}
