#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

using namespace std;
using namespace string;

class Vigenere
{
    public:
        Vigenere(string);

        string cif(string);
        string des(string);
        string alf;

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
        lpos = alf.find(msg[i]);
        cpos = alf.find(clave[i%clave.size()]);

        msg_cif += alf[(lpos + cpos)%alf.size()];
    }

    return msg_cif;
}

string Vigenere::des(string msg_cif)
{
    string msg_des;
    int lpos,cpos;
    for(int i = 0; i < msg_cif.size(); i++)
    {
        lpos = alf.find(msg_cif[i]);
        cpos = alf.find(clave[i%clave.size()]);

        msg_des += alf[(lpos - cpos + alf.size())%alf.size()];
    }

    return msg_des;
}
#endif // VIGENERE_H
