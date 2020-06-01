#ifndef EXTENCIONES_H
#define EXTENCIONES_H

#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ mod(ZZ a, ZZ n)
{
    return (a - (a/n)*n);
    //return a%n;
}

#endif