  
#include "Cesar.h"

Cesar::Cesar(int c)
{
    alf = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,";
    clave = c;
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
            if(lpos + clave > alf.size())
            {
               lpos -= alf.size();
            }
            msg_cif += alf[lpos + clave];
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
            if(lpos + clave > alf.size())
            {
               lpos += alf.size();
            }
            msg_des += alf[lpos - clave];
        }else{
            msg_des += msg[i];
        }
    }

    return msg_des;
}
