#include "Cesar.h"

Cesar::Cesar()
{
    alf = "abcdefghijklmnopqrstuvwxyz";
    clave = 4;
}

Cesar::~Cesar()
{
    //dtor
}

string Cesar::cif(string msg)
{
    string msg_cif;

    for(int i = 0; i < msg.size(); i++)
    {
        int lpos = alf.find(msg[i]);
        if(lpos != string::npos)
        {
            msg_cif += alf[(lpos + clave)%alf.size()];
        }else{
            msg_cif += msg[i];
        }
    }

    return msg_cif;
}

string Cesar::des(string msg_cif)
{
    string msg_des;

    for(int i = 0; i < msg_cif.size(); i++)
    {
        int lpos = alf.find(msg_cif[i]);
        if(lpos != string::npos)
        {
            msg_des += alf[(lpos - clave)%alf.size()];
        }else{
            msg_des += msg_cif[i];
        }
    }

    return msg_des;
}
