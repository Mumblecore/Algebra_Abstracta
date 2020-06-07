#ifndef FUNCIONES_H
#define FUNCIONES_H

int mod(int a, int b)
{
    if(a < 0)
        return a - a/b * b + b;
    return a - a/b * b;
}

int gcd(int a, int b)
{
    int r = mod(a,b);
    while(r != 0){
        if(r > b>>1)
        {
            r -= b;
        }
        a = b;
        b = r;
        r = mod(a,b);
    }
    return b;
}

// int inversa(int a, int b)
// {
//     int s, r, q, t, s2 = 0;
//     int s1(1);
//     int r2(b);
//     while(r2 > 0)
//     {
//         std::cout << "i1\n";
//         q = a/r2;
//         t = q * r2;
//         r = a - t;
//         a = r2;
//         r2 = r;
//         t = q * s2;
//         s = s1 - t;
//         s1 = s2;
//         s2 = s;
//     }
//     if(s1 < 0)
//         s1+=b;
//     return s1;
// }

int inversa(int a, int b)
{
    int t, q, s2 = 0;
    int s1 = 1, r2 = b;
    while(r2 > 0)
    {
        q = a/r2;
        t = a - q * r2;
        a = r2;
        r2 = t;
        t = s1 - q * s2;
        s1 = s2;
        s2 = t;
    }
    if(s1 < 0)
        s1+=b;
    return s1;
}

#endif