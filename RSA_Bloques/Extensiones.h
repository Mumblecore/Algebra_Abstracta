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

Vec<ZZ> criba(ZZ min, ZZ max)
{
    Vec<ZZ> menores;
    Vec<ZZ> lista;
    long i_min =conv<long>(min);
    menores.SetLength(i_min/2);
    lista.SetLength(i_min);
    menores[0] = 2;
    menores[1] = 3;
    long tam(2);
    long tam_l;
    bool primo = true;
    for(ZZ i(5); i < max; i+=2)
    {
        for(long j = 1; i >= menores[j] * menores[j]; j++)
            if(nmod(i, menores[j]) == 0){
                primo = false;
                break;
            }
        if(primo){
            menores[tam++] = i;
            if(i > min)
                lista[tam_l++] = i;
        }
        primo = true;
    }
    menores.kill();
    lista.SetLength(tam_l);
    return lista;
}

bool es_primo(ZZ p, Vec<ZZ> arr)
{
    for(long i = 1; i < arr.length(); i++)
    {
        if(nmod(p,arr[i]) == 0){
            return false;
        }
    }
    return true;
}

ZZ primo(long bits)
{
    auto t1 = Clock::now();
    ZZ min_val(1);
    min_val<<=bits-1;

    int min =conv<int>(min_val);

    ZZ max_val(1);
    max_val<<=bits;
    min_val--;
    auto t2 = Clock::now();
    
    srand(std::chrono::duration_cast<Nano>(t1-t2).count());

    Vec<ZZ> lista = criba(min_val, max_val);

    ZZ p = lista[mod(rand(), lista.length())];

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
        div(q, a, r2);
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

ZZ resto_chino(Vec<ZZ>& a, Vec<ZZ>& p, ZZ &P)
{
    for(int i = 0; i < p.length(); i++){
        for(int j = i + 1; j < p.length(); j++)
            if(gcd(p[i], p[j]) > 1){
                std::cout << "No hay solucion\n";
                return P;
            }
        P *= p[i];
    }

    Vec<ZZ> Pi;
    Vec<ZZ> q;
    Pi.SetLength(p.length());
    q.SetLength(p.length());
    ZZ xo;

    for(int i = 0; i < p.length(); i++){
        Pi[i] = P/p[i];
        q[i] = inversa(Pi[i], p[i]);
        xo += a[i] * Pi[i] * q[i];
    }
    xo = nmod(xo, P);

    return xo;
}

#endif