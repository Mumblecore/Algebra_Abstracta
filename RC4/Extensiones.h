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

int mod(int a, int n)
{
    if(a < 0)
        return a - a/n * n + n;
    return a - a/n * n;
}

void criba(Vec<ZZ>& a, ZZ n)
{
    a[0] = 2;
    a[1] = 3;
    long tam(2);
    bool primo = true;
    for(ZZ i(5); i < n; i+=2)
    {
        for(long j = 1; i >= a[j] * a[j]; j++)
            if(nmod(i, a[j]) == 0){
                primo = false;
                break;
            }
        if(primo)
            a[tam++] = i;
        primo = true;
    }
    a.SetLength(tam);
}

bool esPrimo(ZZ p, Vec<ZZ> arr)
{
    for(long i = 1; i < arr.length(); i++)
    {
        if(nmod(p,arr[i]) == 0){
            return false;
        }
    }
    return true;
}

ZZ primo()
{
    auto t1 = Clock::now();
    auto t2 = Clock::now();
    srand(std::chrono::duration_cast<Nano>(t1-t2).count());
    long t = mod(rand(), 500000);
    if(t<0)
        t = -t;
    ZZ zt(t);

    Vec<ZZ> lista;
    lista.SetLength(t);
    criba(lista, zt);

    ZZ p = zt*zt;
    if((p & 1) == 0)
        p--;
    while(!esPrimo(p, lista))
        p-=2;
    return p;
}

ZZ expomod(ZZ a, ZZ m, ZZ n)
{
    ZZ res(1);

    while(m!=0)
    {
        if((m&1)==1)
            res = nmod(a*res,n);
        a=nmod(a*a,n);
        m>>=1;
    }

    return res;
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