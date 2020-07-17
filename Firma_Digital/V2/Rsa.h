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
    string tmp_r;
    for(int i = 0, j; i < secuencia.size(); i += tam_bloque)
    {
        D = stringToZZ(secuencia.substr(i, tam_bloque));
        // Resto Chino modificado =======================================================+
        Dp = expomod(zmod(D, p), zmod(d, p - 1), p);
        Dq = expomod(zmod(D, q), zmod(d, q - 1), q);
        D = zmod(qCp*Dp + pCq*Dq, N);
        // Fin Resto Chino modificado ===================================================+
        tmp_r = ZZtoString(D);
        for(j = tam_bloque + 1 - tmp_r.size(); j; j--)
            r += "0";
        r += tmp_r;
    }

// Creacion de la firma:
    string s, tmp_s;

    tam_bloque = ZZtoString(_N).size() - 1;
    falta = imod(r.size(), tam_bloque);
    if(falta){                          //completar con 2, 22 es W
        string tmp(tam_bloque - falta, '2');
        r += tmp;
    }

    ZZ C;
    for(int i = 0, j; i < r.size(); i += tam_bloque)
    {
        C = stringToZZ(r.substr(i, tam_bloque));
        C = expomod(C, _e, _N);

        tmp_s = ZZtoString(C);
        for(j = (tam_bloque + 1) - tmp_s.size(); j; j--)
            s += "0";
        s += tmp_s;
    }
    return c + '#' + s;
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
    string sec_s = par_cs.substr(msg.size()+1);
    msg = descifrar(msg);
// Descifrar la firma:
    string s;
    string secuencia, tmp;

    int tam_N = ZZtoString(N).size();

    ZZ D, Dp, Dq;
    for(int i = 0, j; i < sec_s.size(); i += tam_N)
    {
        D = stringToZZ(sec_s.substr(i, tam_N));
        // Resto Chino modificado =======================================================+
        Dp = expomod(zmod(D, p), zmod(d, p - 1), p);
        Dq = expomod(zmod(D, q), zmod(d, q - 1), q);
        D = zmod(qCp*Dp + pCq*Dq, N);
        // Fin Resto Chino modificado ===================================================+
        tmp = ZZtoString(D);
        for(j = tam_N - 1 - tmp.size(); j; j--)
            s += "0";
        s += tmp;
    }

    string ns;
    int tam_bloque = ZZtoString(_N).size();
    for(int i = 0; i < s.size() - tam_N; i += tam_N){
        ns+= s.substr(i, tam_bloque);
    }
    
// Comprobar la rubrica:
    string r, output;
    ZZ C;
    for(int i = 0, j; i < ns.size(); i += tam_bloque)
    {
        C = stringToZZ(ns.substr(i, tam_bloque));
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
    cout << "r: " << r << endl;

// Output
    if(msg == r)
        return msg;
    else
        return "El mensaje no es del destinatario";
}

#endif