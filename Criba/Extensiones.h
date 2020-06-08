#ifndef EXTENSIONES_H
#define EXTENSIONES_H

#include "NTL/ZZ.h"

using namespace NTL;

ZZ nmod(ZZ a, ZZ n)
{
    return a - a/n * n;
}

int mod(int a, int b)
{
    if(a < 0)
        return a - a/b * b + b;
    return a - a/b * b;
}   

#endif