#include "funciones.h"

bool inversa(ZZ a, ZZ b, ZZ& c)
{
    if(foo2(a, b) != 1)
    {
        cout << "No posee inversa\n";
        return 0;
    }
    ZZ s, r, q, t, s2;
    ZZ s1(1);
    ZZ r2(b);
    while(r2 > 0)
    {
        div(q, a, r2);
        mul(t, q, r2);
        sub(r, a, t);
        a = r2;
        r2 = r;
        mul(t, q, s2);
        sub(s, s1, t);
        s1 = s2;
        s2 = s;
    }
    if(s1 < 0)
        c = mod(s1, b);
    else
        c = s1;
    return 1;
}

ZZ inversa(ZZ a, ZZ b)
{
    ZZ c;
    if(foo2(a, b) != 1)
    {
        cout << "No posee inversa\n";
        return c;
    }
    ZZ s, r, q, t, s2;
    ZZ s1(1);
    ZZ r2(b);
    while(r2 > 0)
    {
        div(q, a, r2);
        mul(t, q, r2);
        sub(r, a, t);
        a = r2;
        r2 = r;
        mul(t, q, s2);
        sub(s, s1, t);
        s1 = s2;
        s2 = s;
    }
    if(s1 < 0)
        c = mod(s1, b);
    else
        c = s1;
    return c;
}