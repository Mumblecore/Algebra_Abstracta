#ifndef UTILIDADES_H
#define UTILIDADES_H

int div(int a, int n)
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

int mod(int a, int n)
{
    return (a - (div(a,n)*n));
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

int gcd(int a, int b)
{
    int g(1);
    while(!(a%2) && !(b%2))
    {
        a/=2;
        b/=2;
        g*=2;
    }

    while(a!=0)
    {
        while(!(a%2))
        {
            a/=2;
        }

        while(!(b%2))
        {
            b/=2;
        }
        
        if(a>=b)
        {
            a = abs(a-b)/2;
        }
        else
        {
            b = abs(a-b)/2;
        }
   }
    return g*b;
}

#endif