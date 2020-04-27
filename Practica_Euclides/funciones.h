#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include "extensiones.h"

ZZ foo1(ZZ a, ZZ b)
{
    int c = 1;
    while(true){
        ZZ r = mod(a,b);
        cout << "vuelta: " << c++ << "\ta: " << a << "\tb: " << b << "\tr: " << r << endl;
        if(r == 0)
        {
            return b;
        }
        a = b;
        b = r;
    }
}

ZZ foo2(ZZ a, ZZ b)
{
    int c = 1;
    while(true){
        ZZ r = mod(a,b);
        cout << "vuelta: " << c++ << "\ta: " << a << "\tb: " << b << "\tr: " << r << endl;
        if(r == 0)
        {
            return b;
        }
        if(r > b/2)
        {
            r = b - r;
        }
        a = b;
        b = r;
    }
}

int cont_r = 1;

ZZ foo3(ZZ a, ZZ b)
{
    cout << "llamada " << cont_r++ << " :(" << a << ", " << b << ")" << endl;
    if(b==0)
    {
        cont_r = 1;
        return a;
    }
    return foo3(b,mod(a,b));
}

ZZ foo4(ZZ a, ZZ b)
{
    cout << "llamada " << cont_r++ << " :(" << a << ", " << b << ")" << endl;
    if(abs(b) > abs(a))
    {
        return foo4(b,a);
    }
    if(b==0)
    {
        cont_r = 1;
        return a;
    }
    if(!(a%2) && !(b%2))
    {
        return 2*foo4(a/2,b/2);
    }
    if(!(a%2))
    {
        return foo4(a/2,b);
    }
    if(!(b%2))
    {
        return foo4(a,b/2);
    }
    return foo4((abs(a)-abs(b))/2,b);
}

ZZ foo5(ZZ a, ZZ b)
{
    ZZ g(1);
    int c1 = 0;
    cout << "While 1:\n";
    cout << "\tvuelta: " << c1 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
    while(!(a%2) && !(b%2))
    {
        a/=2;
        b/=2;
        g*=2;
        cout << "\tvuelta: " << ++c1 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
    }

    int c2 = 0;
    int c3 = 0;
    int c4 = 0;
    cout << "While 2:\n";
    cout << "\tvuelta: " << c2 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
    while(a!=0)
    {
        cout << "\t\tWhile 2.1:\n";
        cout << "\t\t\tvuelta: " << c3 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
        while(!(a%2))
        {
            a/=2;
            cout << "\t\t\tvuelta: " << ++c3 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
        }

        cout << "\t\tWhile 2.2:\n";
        cout << "\t\t\tvuelta: " << c4 << "\ta: " << a << "\tb: " << b << "\tg: " << g << endl;
        while(!(b%2))
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
    int c =1;
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
        cout << "vuelta: " << ++c << "\ta: " << a << "\tb: " << b << endl;
    }
    return a;
}

#endif
