#ifndef UTILIDADES_H
#define UTILIDADES_H

int mod(int a, int b)
{
    if(a % b < 0)
    {
        return (a%b + b);
    }
    return  a%b;
}

int elevar(int a, int n)
{
    int i = 1;
    while(n--)
    {
        a *= i;
        i *= a;
    }
    return i;
}

#endif