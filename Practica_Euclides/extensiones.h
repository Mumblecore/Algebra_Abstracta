#ifndef EXTENCIONES_H
#define EXTENCIONES_H

#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ div(ZZ a, ZZ n)
{
    ZZ q(0);

    if(a<0)
    {
        while(a <= n)
        {
            a += n;
            q--;
        }
        q++;
    }
    else
    {
        while(a >= n)
        {
            a -= n;
            q++;
        }
    }
    
    return q;
}

ZZ mod(ZZ a, ZZ n)
{
    ZZ m = (a - (div(a,n)*n));

    return m;
}

int div(ZZ a, int n)
{
    int q(0);

    if(a<0)
    {
        while(a <= n)
        {
            a += n;
            q--;
        }
        q++;
    }
    else
    {
        while(a >= n)
        {
            a -= n;
            q++;
        }
    }
    
    return q;
}

bool mod(ZZ a, int n)
{
    if(a == (div(a,n)*n))
    {
        return false;
    }
    return true;
}

#endif
