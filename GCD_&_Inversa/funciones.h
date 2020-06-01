#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "extensiones.h"

ZZ foo1(ZZ a, ZZ b)
{
    ZZ r = mod(a,b);
    while(r != 0){
        a = b;
        b = r;
        r = mod(a,b);
    }
    return b;
}

ZZ foo2(ZZ a, ZZ b)
{
    ZZ r = mod(a,b);
    while(r != 0){
        if(r > b>>1)
        {
            sub(r, b, r);
        }
        a = b;
        b = r;
        r = mod(a,b);
    }
    return b;
}

ZZ foo3(ZZ a, ZZ b)
{
    if(b==0)
    {
        return a;
    }
    return foo3(b,mod(a,b));
}

ZZ foo4(ZZ a, ZZ b)
{
    if(abs(b) > abs(a))
    {
        return foo4(b,a);
    }
    if(b==0)
    {
        return a;
    }
    if((a & 1) == 0 && (b & 1) == 0)
    {
        return (foo4(a>>1,b>>1)<<1);
    }
    if((a & 1) == 0)
    {
        return foo4(a>>1,b);
    }
    if((b & 1) == 0)
    {
        return foo4(a,b>>1);
    }
    return foo4((abs(a)-abs(b))>>1,b);
}

ZZ foo5(ZZ a, ZZ b)
{
    ZZ g(1);
    while((a & 1) == 0 && (b & 1) == 0)
    {
        a>>=1;
        b>>=1;
        g<<=1;
    }
    while(a!=0)
    {
        while((a & 1) == 0)
        {
            a>>=1;
        }
        while((b & 1) == 0)
        {
            b>>=1;
        }
            
        ZZ t = abs(a-b)>>1;
        if(a >= b)
        {
            a = t;
        }
        else
        {
            b = t;
        }
    }
    return g*b;
}

ZZ foo6(ZZ a, ZZ b)
{
    while(a!=b)
    {
        if(a > b)
        {
            a-=b;
        }
        else
        {
            b-=a;
        }
    }
    return a;
}

#endif