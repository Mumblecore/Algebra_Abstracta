#ifndef REILFENCE_H
#define REILFENCE_H

#include <string>
#include <iostream>

using namespace std;

class RailFence
{
public:
    RailFence(int);
    int clave;
    string Cifrar(string);
    string Descifrar(string);
};

RailFence::RailFence(int clave)
{
    this->clave = clave;
}

string RailFence::Cifrar(string msg)
{
    string msg_cif;
    int tam = msg.size();
    int clv_t = 2 * (clave - 1);

    for(int i = 0; i < tam; i += clv_t)
        msg_cif += msg[i];

    for(int i = 1, a = clv_t - 2, b = 2; i < clave - 1; i++)
    {
        for(int j = i, c, a1 = a, b1 = b; j < tam; j += c)
        {
            c = a1;
            msg_cif += msg[j];
            swap(a1,b1);     
        }
        a-=2;
        b+=2;
    }
    for(int i = clave - 1; i < tam; i += clv_t)
        msg_cif += msg[i];

    return msg_cif;
}

string RailFence::Descifrar(string msg)
{
    string msg_des;
    int tam = msg.size();
    int clv_t = 2 * (clave - 1);

    int r = (tam-1)/clv_t + 1;

    for(int i = 0 ; i < r; i++)
    {
        msg_des += msg[i];
        for(int j = 1; j < clv_t; j++)
            msg_des += '.';
    }

    for(int i = 1, j = clv_t - 1; i != j; i++, j--)
    {
        int n_i = (tam - 1 - i)/clv_t + 1;
        int n_j = (tam - 1 - j)/clv_t + 1;
        int sum = n_i + n_j;

        for(int r1 = r, t = i; r1 < r + sum; r1 += 2, t += clv_t)
            msg_des[t] = msg[r1];
        for(int r2 = r + 1, t = j; r2 < r + sum;r2 += 2, t += clv_t)
            msg_des[t] = msg[r2];
        r += sum;
    }

    for(int i = (tam + clave - 2)/clv_t, j = clave - 1; i; i--)
    {
        msg_des[j] = msg[tam - i];
        j += clv_t;
    }

    msg_des.resize(tam);
    return msg_des;
}

#endif