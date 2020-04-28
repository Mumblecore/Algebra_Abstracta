#ifndef DIVINT_H
#define DIVINT_H

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

#endif // DIVINT_H
