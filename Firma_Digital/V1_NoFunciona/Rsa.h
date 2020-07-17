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

    string cifrar(string msg, ZZ _N, ZZ _e);
    string descifrar(string msg);

    string cifrar_y_firmar(string msg, ZZ _N, ZZ _e);
    string descifrar_y_confirmar(string msg, ZZ _N, ZZ _e);

    string bloques(string msg, ZZ _N);
    string cifrado_parcial(string bloques, ZZ _N, ZZ _e);
    string descifrado_parcial(string bloques);

    ZZ N;
    ZZ e;
};

RSA::RSA(short bits)            //Solo un constructor para que todos tengan clave privada
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

string RSA::cifrar(string msg, ZZ _N, ZZ _e)
{
    // Cifrar la secuencia ==========================================================+
    string secuencia = bloques(msg, _N);
    return cifrado_parcial(secuencia, _N, _e);
}

string RSA::descifrar(string msg)
{
    string output;
    string secuencia = descifrado_parcial(msg);
    // Parsear con el alfabeto ======================================================+
    for(int i = 0, pos; i < secuencia.size()-1; i += alf_dgts){
        pos = stoi(secuencia.substr(i, alf_dgts));
        if(pos == 22)
            break;
        output += alf[pos];
    }
    return output;
}

string RSA::cifrar_y_firmar(string msg, ZZ _N, ZZ _e){
    
    // msg = bloques(msg, N*10);
    // string secuencia, tmp;

    // int tam_N = ZZtoString(N).size();

    // ZZ D, Dp, Dq;

    // for(int i = 0, j; i < msg.size(); i += tam_N)
    // {
    //     D = stringToZZ(msg.substr(i, tam_N));
    // // Resto Chino modificado =======================================================+
    //     Dp = expomod(zmod(D, p), zmod(d, p - 1), p);
    //     Dq = expomod(zmod(D, q), zmod(d, q - 1), q);
    //     D = zmod(qCp*Dp + pCq*Dq, N);
    // // Fin Resto Chino modificado ===================================================+
    //     tmp = ZZtoString(D);
    //     for(j = tam_N - 1 - tmp.size(); j > 0; j--)
    //         secuencia += "0";
    //     secuencia += tmp;
    // }
    // return secuencia;
    // Firmar el mensaje ============================================================+
    string c = cifrar(msg, _N, _e);

    string r = descifrado_parcial(bloques(msg, N*10));

    // string s = cifrado_parcial(r, _N, _e);
    // return c + '#' + s;
    cout << "c: " << bloques(msg, N*10) << endl;
    cout << "r: " << descifrado_parcial(bloques(msg, N*10)) << endl;
    return descifrado_parcial(bloques(msg, N*10));
}

string RSA::descifrar_y_confirmar(string par_cs, ZZ _N, ZZ _e)
{
    // string c, s, c_bloques;
    // for(int i = 0; i < par_cs.size(); i++){
    //     if(par_cs[i] == '#')
    //         break;
    //     c_bloques += par_cs[i];
    // }
    // s = descifrado_parcial(par_cs.substr(c.size() + 1));
    // c = descifrar(c_bloques);
    // cout << "c: " << c << endl;
    // cout << "s: " << s << endl;
    // cout << "cb1: " << c_bloques << endl;
    // c_bloques = bloques(c, N);
    // cout << "cb2: " << c_bloques << endl;

    // //string r = cifrado_parcial(s, _N, _e);
    // cout << "cr: " << r << endl;
    // if(c_bloques == r)
    //     cout << "El mensaje ha sido entregado por el emisor" << endl;
    // else
    //     cout << "El mensaje ha sido adulterado" << endl;

    // return c;
    return cifrado_parcial(par_cs, _N, _e);
}

string RSA::bloques(string msg, ZZ _N)
{    // Formar la secuencia de bloques ===============================================+
    string bloque;

    for(int i = 0, pos; i < msg.size(); i++)
    {
        pos = alf.find(msg[i]);
        for(int j = alf_dgts - to_string(pos).size(); j > 0; j--)
            bloque += "0";
        bloque += to_string(pos);
    }

    int tam_bloque = ZZtoString(_N).size() - 1;

    int falta = imod(bloque.size(), tam_bloque);
    if(falta){                          //completar con 2, 22 es W, que es insignificante
        string tmp(tam_bloque - falta, '2');
        bloque += tmp;
    }

    return bloque;
}

string RSA::cifrado_parcial(string bloques, ZZ _N, ZZ _e)
{   // Cifrado con input en bloques =================================================+
    string output, tmp;
    int tam_bloque = ZZtoString(_N).size() - 1;
    ZZ C;
    for(int i = 0, j; i < bloques.size(); i += tam_bloque)
    {
        C = stringToZZ(bloques.substr(i, tam_bloque));
        C = expomod(C, _e, _N);

        tmp = ZZtoString(C);
        for(j = (tam_bloque + 1) - tmp.size(); j; j--)
            output += "0";
        output += tmp;
    }
    return output;
}

string RSA::descifrado_parcial(string bloques)
{
    string secuencia, tmp;

    int tam_N = ZZtoString(N).size();

    ZZ D, Dp, Dq;

    for(int i = 0, j; i < bloques.size(); i += tam_N)
    {
        D = stringToZZ(bloques.substr(i, tam_N));
    // Resto Chino modificado =======================================================+
        Dp = expomod(zmod(D, p), zmod(d, p - 1), p);
        Dq = expomod(zmod(D, q), zmod(d, q - 1), q);
        D = zmod(qCp*Dp + pCq*Dq, N);
    // Fin Resto Chino modificado ===================================================+
        tmp = ZZtoString(D);
        for(j = tam_N - 1 - tmp.size(); j > 0; j--)
            secuencia += "0";
        secuencia += tmp;
    }
    return secuencia;
}

#endif