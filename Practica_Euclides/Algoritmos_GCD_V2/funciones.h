#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include "extensiones.h"

ZZ foo1(ZZ a, ZZ b)
{
    ZZ c(0);
    ZZ r = mod(a,b);
    while(r != 0){
        cout << "vuelta: " << ++c << "\ta: " << a << "\tb: " << b << "\tr: " << r << endl;
        a = b;
        b = r;
        r = mod(a,b);
    }
    return b;
}

ZZ foo2(ZZ a, ZZ b)
{
    ZZ c(0);
    ZZ r = mod(a,b);
    while(r != 0){
        cout << "vuelta: " << ++c <<"\ta: " << a << "\tb: " << b << "\tr: " << r << endl;
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

ZZ cont_r(0);

ZZ foo3(ZZ a, ZZ b)
{
    cout << "llamada " << ++cont_r << " :(" << a << ", " << b << ")" << endl;
    if(b==0)
    {
        cont_r = 0;
        return a;
    }
    return foo3(b,mod(a,b));
}

ZZ foo4(ZZ a, ZZ b)
{
    cout << "llamada " << ++cont_r << " :(" << a << ", " << b << ")" << endl;
    if(abs(b) > abs(a))
    {
        return foo4(b,a);
    }
    if(b==0)
    {
        cont_r = 0;
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
    ZZ c1(0);
    cout << "While 1:\n";
    cout << "\tvuelta: " << c1 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
    while(!(mod(a,2)) && !(mod(b,2)))
    {
        a/=2;
        b/=2;
        g*=2;
        cout << "\tvuelta: " << ++c1 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
    }

    ZZ c2(0);
    ZZ c3(0);
    ZZ c4(0);
    cout << "While 2:\n";
    cout << "\tvuelta: " << c2 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
    while(a!=0)
    {
        cout << "\t\tWhile 2.1:\n";
        cout << "\t\t\tvuelta: " << c3 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
        while(!(mod(a,2)))
        {
            a/=2;
            cout << "\t\t\tvuelta: " << ++c3 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
        }

        cout << "\t\tWhile 2.2:\n";
        cout << "\t\t\tvuelta: " << c4 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
        while(!(mod(b,2)))
        {
            b/=2;
            cout << "\t\t\tvuelta: " << ++c4 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
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
        cout << "\tvuelta: " << ++c2 << "\ta: " << a << "\tb: " << b << "\tg: " << g << "\tt: " << t << endl;   
    }
    cout << "Iteraciones totales: " << c1+c2+c3+c4 << endl;
    return g*b;
}

ZZ foo6(ZZ a, ZZ b)
{
    ZZ c(0);
    cout << "vuelta: " << c << "\ta: " << a << "\tb: " << b << endl;
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
        cout << "vuelta: " << c << "\ta: " << a << "\tb: " << b << endl; c++;
    }
    return a;
}

#endif