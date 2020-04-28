#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

using namespace std;

class Vigenere
{
    public:
        Vigenere(string);

        string cif(string);
        string des(string);
        string alf;
        int ancho_car;

    private:
        string clave;
};

Vigenere::Vigenere(string c)
{
    clave = c;
}

string Vigenere::cif(string msg)
{
    string msg_cif, car_cif;
    int lpos,cpos;

    int clave_or = clave.size();
    clave += msg;
    
    for(int i = 0; i < msg.size(); i += ancho_car)
    {
        string car_msg(msg,i,ancho_car);
        string car_clv(clave,i,ancho_car);

        lpos = alf.find(car_msg);
        cpos = alf.find(car_clv);

        for(int j = 0; j < ancho_car; j++)
            msg_cif += alf[(lpos + cpos)%alf.size() + j];
    }

    clave.erase(clave_or,msg.size());

    return msg_cif;
}


// string Vigenere::des(string msg_cif)       No funciona debido a que la nueva clave contiene el texto en plano, el cual no conocemos            
// {
//     string msg_des;
//     int lpos,cpos;

//     int clave_or = clave.size();
//     clave += msg_cif;
    
//     for(int i = 0; i < msg_cif.size(); i += ancho_car)
//     {
//         string car_msg(msg_cif,i,ancho_car);
//         string car_clv(clave,i,ancho_car);

//         lpos = alf.find(car_msg);
//         cpos = alf.find(car_clv);

//         for(int j = 0; j < ancho_car; j++)
//             msg_des += alf[(lpos - cpos + alf.size())%alf.size() + j];
//     }

//     clave.erase(clave_or,msg_cif.size());

//     return msg_des;
// }
#endif // VIGENERE_H
