#ifndef EXTENSIONES_H
#define EXTENSIONES_H

#include "NTL/ZZ.h"

using namespace NTL;

ZZ nmod(ZZ a, ZZ n)
{
    return a - a/n * n;
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

#endif