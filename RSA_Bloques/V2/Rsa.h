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
    RSA(ZZ _N, ZZ _e);

    string cifrar(string msg);
    string descifrar(string msg);

    ZZ resto_chino(ZZ D);

    ZZ N;
    ZZ e;
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
    pCq = q * inversa(p, q);

    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "N: " << N << endl;
    cout << "n: " << phi_N << endl;
    cout << "e: " << e << endl;
    cout << "d: " << d << endl;
}

RSA::RSA(ZZ _N, ZZ _e)
{
    N = _N;
    e = _e;
}

string RSA::cifrar(string msg)
{
    // Formar la secuencia de bloques ===============================================+
    string secuencia;
    for(int i = 0, pos; i < msg.size(); i++)
    {
        pos = alf.find(msg[i]);
        if(pos < 10)
            secuencia += "0";
        secuencia += to_string(pos);
    }

    int tam_bloque = ZZtoString(N).size() - 1;

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
        C = expomod(C, e, N);

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

    ZZ D;
    for(int i = 0, j; i < msg.size(); i += tam_N)
    {
        D = stringToZZ(msg.substr(i, tam_N));
        cout << "\nINICIO========\n";
        D = resto_chino(D);
        cout << "\nFINAL========\n";

        tmp = ZZtoString(D);
        for(j = tam_N - 1 - tmp.size(); j; j--)
            secuencia += "0";
        secuencia += tmp;
    }

    for(int i = 0, pos; i < secuencia.size(); i += alf_dgts){
        pos = stoi(secuencia.substr(i, alf_dgts));
        if(pos == 22)
            break;
        output += alf[pos];
    }

    return output;
}

ZZ RSA::resto_chino(ZZ D){
    // Resto Chino modificado =======================================================+

    ZZ xp = expomod(zmod(D, p), zmod(d, p - 1), p);
    ZZ xq = expomod(zmod(D, q), zmod(d, q - 1), q);

    cout << "xp: " << xp << endl;
    cout << "xq: " << xq << endl;
    cout << "qCp: " << qCp << endl;
    cout << "pCq: " << pCq << endl;
    cout << "qCp*xp" << qCp*xp << endl;
    cout << "pCq*xq" << pCq*xq << endl;
    ZZ x = zmod(qCp*xp + pCq*xq, N);
    cout << "Resto Chino x: " << x << endl;
    cout << "Exponenci mod: " << expomod(D, d, N) << endl;

    return x;
}

// ZZ RSA::resto_chino(Vec<ZZ> a, Vec<ZZ> p){
//     // Resto Chino modificado =======================================================+
//     ZZ P(1);
//     for(int i = 0; i < p.length(); i++)
//         P *= p[i];

//     Vec<ZZ> Pi;
//     Vec<ZZ> q;
//     Pi.SetLength(p.length());
//     q.SetLength(p.length());
//     ZZ xo;

//     for(int i = 0; i < p.length(); i++){
//         Pi[i] = P/p[i];
//         q[i] = inversa(Pi[i], p[i]);
//         xo += a[i] * Pi[i] * q[i];
//     }
//     xo = zmod(xo, P);

//     return xo;
// }

#endif