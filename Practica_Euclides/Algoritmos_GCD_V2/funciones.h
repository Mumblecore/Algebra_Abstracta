#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
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
        if(r > b/2)
        {
            r = b - r;
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
    if(!(mod(a,2)) && !(mod(b,2)))
    {
        return 2*foo4(a/2,b/2);
    }
    if(!(mod(a,2)))
    {
        return foo4(a/2,b);
    }
    if(!(mod(b,2)))
    {
        return foo4(a,b/2);
    }
    return foo4((abs(a)-abs(b))/2,b);
}

ZZ foo5(ZZ a, ZZ b)
{
    ZZ g(1);
    while(!(mod(a,2)) && !(mod(b,2)))
    {
        a/=2;
        b/=2;
        g*=2;
    }

    while(a!=0)
    {
        while(!(mod(a,2)))
        {
            a/=2;
        }

        while(!(mod(b,2)))
        {
            b/=2;
        }
            
        ZZ t = abs(a-b)/2;
        if(a>=b)
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