#ifndef PRIMOS_H
#define PRIMOS_H

#include "Extensiones.h"

using namespace NTL;

bool MillerRabin(ZZ n, int vueltas, short bits)
{
    ZZ s, a, x;
    ZZ r(n - 1);
    ZZ dos(2);

    while((r & 1) == 0){
        s++;
        r>>=1;
    }
    while(vueltas--){
        a = zmod(aleatorio(bits), n-3) + 2;
        x = expomod(a, r, n);
        if(x != 1 && x != n - 1){
            for(ZZ i(1); i < s && x != n - 1; i++){
                x = expomod(x, dos, n);
                if(x == 1)
                    return false;
            }
            if(x != n - 1)
                return false;
        }
    }
    return true;
}

//Generamos una criba con los primeros 400 primos
void generar_criba(Vec<ZZ> &criba)
{
    criba.SetLength(77);    //hay 77 sin contar al 2
    criba[0] = 3;           //no consideramos al 2 ya que nunca trabajamos con pares
    bool primo = true;
    int tam = 1;

    for(ZZ i(5); i < 400; i+=2)
    {
        for(long j = 0; i >= criba[j] * criba[j]; j++)
            if(zmod(i, criba[j]) == 0){
                primo = false;
                break;
            }
        if(primo)
            criba[tam++] = i;
        primo = true;
    }
}

bool TestCriba(ZZ n, Vec<ZZ> &criba)
{
    for(short i = 0; i < criba.length(); i++){
        if(zmod(n, criba[i]) == 0)
            return false;
    }
    return true;
}

ZZ primo(short bits, Vec<ZZ> &criba)
{
    ZZ p;
    do{
        do{
        p = aleatorio(bits);
        p |= 1;
        }while(!TestCriba(p, criba));
    }while(!MillerRabin(p, 20, bits));
    return p;
}

#endif