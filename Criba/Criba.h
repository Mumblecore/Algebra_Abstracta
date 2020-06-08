#ifndef CRIBA_H
#define CRIBA_H

#include "Extensiones.h"
#include <NTL/ZZVec.h>

using namespace NTL;

void primos(Vec<ZZ>& a, ZZ n)
{
    a[0] = 2;
    a[1] = 3;
    long tam(2);
    bool primo = true;
    for(ZZ i(5); i < n; i+=2)
    {
        for(long j = 1; i >= a[j] * a[j]; j++)
            if(i % a[j] == 0){
                primo = false;
                break;
            }
        if(primo)
            a[tam++] = i;
        primo = true;
    }
    a.SetLength(tam);
}

void primos(int a[], int n)
{
    a[0] = 2;
    a[1] = 3;
    int tam(2);
    bool primo = true;
    for(int i = 5; i < n; i+=2)
    {
        for(int j = 1; i >= a[j] * a[j]; j++)
            if(mod(i, a[j]) == 0){
                primo = false;
                j = tam;
            }
        if(primo)
            a[tam++] = i;
        primo = true;
    }
}

#endif