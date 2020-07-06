#ifndef EXTENSIONES_H
#define EXTENSIONES_H

#include <NTL/ZZ.h>
#include <NTL/ZZVec.h>
#include <cstdlib>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds Mili;
typedef std::chrono::nanoseconds Nano;

using namespace NTL;

ZZ nmod(ZZ a, ZZ n)
{
    return a - a/n * n;
}

ZZ gcd(ZZ a, ZZ b)
{
    ZZ r = nmod(a,b);
    while(r != 0){
        if(r > b>>1)
        {
            sub(r, b, r);
        }
        a = b;
        b = r;
        r = nmod(a,b);
    }
    return b;
}
//div, mul y sum son funciones tipo ensamblador nativas de la libreria ntl se utilizan debido a lo recomendado en la documentacion oficial de la libreria para obtener la mejor performance https://www.shoup.net/ntl/doc/tour-tips.html
ZZ inversa(ZZ a, ZZ b)
{
    ZZ q, t, s2;
    ZZ s1(1);
    ZZ r2(b);
    while(r2 > 0)
    {
        q = a/r2;
        mul(t, q, r2);
        sub(t, a, t);
        a = r2;
        r2 = t;
        mul(t, q, s2);
        sub(t, s1, t);
        s1 = s2;
        s2 = t;
    }
    if(s1 < 0)
        s1+=b;
    return s1;
}
#endif