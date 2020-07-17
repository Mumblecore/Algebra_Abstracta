#ifndef RSA_H
#define RSA_H

#include "Primos.h"

using namespace std;

class RSA
{
private:
    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    int alf_dgts = to_string(alf.size()).size();

    ZZ p,q,d;
    ZZ qCp;
    ZZ pCq;
public:
    RSA(short bits);        //bits de N

    string cifrar(string msg);
    string descifrar(string msg);

    string cifrar_y_firmar(string msg);
    string descifrar_y_confirmar(string par_cs);

    ZZ N, e;
    ZZ _N, _e;
};

RSA::RSA(short bits)
{
    short _bits = bits/2;

    Vec<ZZ> criba;
    generar_criba(criba);
    p = primo(_bits, criba);
    q = primo(_bits, criba);

    N = p * q;
    ZZ phi_N = (p-1)*(q-1);

    e = aleatorio(_bits);       //Tener un e pequenho sin perder seguridad
    while(gcd(e,phi_N) != 1)
        e--;
    d = inversa(e,phi_N);
//Para el resto Chino
    qCp = q * inversa(q, p);
    pCq = p * inversa(p, q);

    // cout << "p: " << p << endl;
    // cout << "q: " << q << endl;
    // cout << "N: " << N << endl;
    // cout << "n: " << phi_N << endl;
    // cout << "e: " << e << endl;
    // cout << "d: " << d << endl;
}

string RSA::cifrar(string msg)
{
    // Formar la secuencia de bloques ===============================================+
    string secuencia;
    for(int i = 0, pos; i < msg.size(); i++)
    {
        pos = alf.find(msg[i]);
        for(short j = alf_dgts - to_string(pos).size(); j; j--)
            secuencia += "0";
        secuencia += to_string(pos);
    }

    int tam_bloque = ZZtoString(_N).size() - 1;

    int falta = imod(secuencia.size(), tam_bloque);
    if(falta){                          //completar con 2, 22 es W
        string tmp(tam_bloque - falta, '2');
        secuencia += tmp;
    }
    // Cifrar la secuencia ==========================================================+
    string output, tmp;
    ZZ C;
    for(int i = 0, j; i < secuencia.size(); i += tam_bloque)
    {
        C = stringToZZ(secuencia.substr(i, tam_bloque));
        C = expomod(C, _e, _N);

        tmp = ZZtoString(C);
        j = (tam_bloque + 1) - tmp.size();
        while(j--)
            output += "0";
        output += tmp;
    }

    return output;
}

string RSA::descifrar(string msg)
{
    string secuencia, tmp, output;

    int tam_N = ZZtoString(N).size();

    ZZ D, Dp, Dq;
    for(int i = 0, j; i < msg.size(); i += tam_N)
    {
        D = stringToZZ(msg.substr(i, tam_N));
        // Resto Chino modificado =======================================================+
        Dp = expomod(zmod(D, p), zmod(d, p - 1), p);
        Dq = expomod(zmod(D, q), zmod(d, q - 1), q);
        D = zmod(qCp*Dp + pCq*Dq, N);
        // Fin Resto Chino modificado ===================================================+
        tmp = ZZtoString(D);
        for(j = tam_N - 1 - tmp.size(); j; j--)
            secuencia += "0";
        secuencia += tmp;
    }

    for(int i = 0, pos; i < secuencia.size()-1; i += alf_dgts){
        pos = stoi(secuencia.substr(i, alf_dgts));
        if(pos == 22)
            break;
        output += alf[pos];
    }

    return output;
}

string RSA::cifrar_y_firmar(string msg)
{
    string c = cifrar(msg);
// Creacion de la rubrica:
    string secuencia, r;

    for(int i = 0, pos; i < msg.size(); i++)
    {
        pos = alf.find(msg[i]);
        for(short j = alf_dgts - to_string(pos).size(); j; j--)
            secuencia += "0";
        secuencia += to_string(pos);
    }
    //el mensaje puede caber o no, asi que hago que quepa en bloques de N-1
    int tam_bloque = ZZtoString(N).size() - 1;

    int falta = imod(secuencia.size(), tam_bloque);
    if(falta){                          //completar con 2, 22 es W
        string tmp(tam_bloque - falta, '2');
        secuencia += tmp;
    }
    ZZ D, Dp, Dq;
    string tmp;
    for(int i = 0, j; i < secuencia.size(); i += tam_bloque)
    {
        D = stringToZZ(secuencia.substr(i, tam_bloque));
        // Resto Chino modificado =======================================================+
        Dp = expomod(zmod(D, p), zmod(d, p - 1), p);
        Dq = expomod(zmod(D, q), zmod(d, q - 1), q);
        D = zmod(qCp*Dp + pCq*Dq, N);
        // Fin Resto Chino modificado ===================================================+
        tmp = ZZtoString(D);
        for(j = tam_bloque + 1 - tmp.size(); j; j--)
            r += "0";
        r += tmp;
    }

// Creacion de la firma:
    //string s;

    return c + '#' + r;
}

string RSA::descifrar_y_confirmar(string par_cs)
{
// Separar el par:
    string msg;
    for(int i = 0; i < par_cs.size(); i++)
    {
        if(par_cs[i] == '#')
            break;
        msg += par_cs[i];
    }
    string sec_r = par_cs.substr(msg.size()+1);
    msg = descifrar(msg);
// Comprobar la rubrica:
    int tam_bloque = ZZtoString(_N).size();
    string r, output, tmp;
    ZZ C;
    for(int i = 0, j; i < sec_r.size(); i += tam_bloque)
    {
        C = stringToZZ(sec_r.substr(i, tam_bloque));
        C = expomod(C, _e, _N);

        tmp = ZZtoString(C);
        for(j = tam_bloque - 1 - tmp.size(); j; j--)
            output += "0";
        output += tmp;
    }
    for(int i = 0, pos; i < output.size()-1; i += alf_dgts){
        pos = stoi(output.substr(i, alf_dgts));
        if(pos == 22)
            break;
        r += alf[pos];
    }



    return msg + '*' + r;
}

#endif