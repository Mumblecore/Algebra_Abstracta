#ifndef EXTENSIONES_H
#define EXTENSIONES_H

#include <NTL/ZZ.h>
#include <NTL/ZZVec.h>
#include <string>
#include <sstream>
#include <bitset>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds Mili;
typedef std::chrono::nanoseconds Nano;

using namespace NTL;
using namespace std;

string ZZtoString(ZZ z){
    stringstream str;
    str << z;
    return str.str();
}

ZZ stringToZZ(string str)
{
    ZZ z;
    istringstream(str) >> z;
    return z;
}

ZZ zmod(ZZ a, ZZ b){return a - a/b * b;}
//ya que solo trabajamos con positivos
int imod(int a, int b){return a - a/b * b;}

ZZ expomod(ZZ a, ZZ m, ZZ n)
{
    ZZ res(1);

    while(m!=0)
    {
        if((m&1)==1)
            res = zmod(a*res,n);
        a=zmod(a*a,n);
        m>>=1;
    }

    return res;
}

ZZ gcd(ZZ a, ZZ b)
{
    ZZ r = zmod(a,b);
    while(r != 0){
        if(r > b>>1)
        {
            sub(r, b, r);
        }
        a = b;
        b = r;
        r = zmod(a,b);
    }
    return b;
}

ZZ inversa(ZZ a, ZZ b)
{
    ZZ q, t, s2;
    ZZ s1(1);
    ZZ r2(b);
    while(r2 > 0)
    {
        div(q, a, r2);
        mul(t, q, r2);
        sub(t, a, t);
        a = r2;
        r2 = t;
        mul(t, q, s2);
        sub(t, s1, t);
        s1 = s2;
        s2 = t;
    }
    if(s1 < 0)
        s1+=b;
    return s1;
}

string StdoutFromTerminal(string cmd) {
    // Para sacar los datos del terminal ============================================+
    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
                pclose(stream);
    }
    return data;
}

ZZ aleatorio(short bits)
{
    // RC4 ==========================================================================+
    unsigned char S[256], K[5];
    //--------------Para rellenar K hago uso de la entropy-pool de unix en /dev/random
    string K5 = StdoutFromTerminal("cat /dev/random | head -c 5");
    for(unsigned char i = 0; i < 255; i++){
        S[i] = i;
        K[i] = K5[i];
    }
    
    unsigned short f;
    for(unsigned char i = 0; i < 255; i++){
        f = imod(f + S[i] + K[imod(i, 5)], 256);
        swap(S[i], S[f]);
    }

    f = 0;
    bitset<64> K_64;
    for(unsigned char i = 0, k = 0, Or; i < 8; i++)
    {
        f = imod(f + S[i], 256);
        swap(S[i], S[f]);
        Or = S[imod(S[i] + S[f], 256)];
        for(int j = 0; j < 8; j++, k++){
            
            K_64[k] = ((Or & 1) ? true : false);
            Or>>=1;
        }
    }
    // DES ==========================================================================+
    ZZ output(1);
    output.SetSize(bits);

    int PC1[56] = {
        56,48,40,32,24,16,8,0,
        57,49,41,33,25,17,9,1,
        58,50,42,34,26,18,10,2,
        59,51,43,35,62,54,46,38,
        30,22,14,6,61,53,45,37,
        29,21,13,5,60,52,44,36,
        28,20,12,4,27,19,11,3
    };
    int PC2[48] = {
        13,16,10,23,0,4,2,27,
        14,5,20,9,22,18,11,3,
        25,7,15,6,26,19,12,1,
        40,51,30,36,46,54,29,39,
        50,44,32,47,43,48,38,55,
        33,52,45,41,49,35,28,31
    };
    
    bitset<28> C;
    bitset<28> D;
    for(int i = 0; i < 28; i++){
        C[i] = K_64[PC1[i]];
        D[i] = K_64[PC1[i+28]];
    }
    
    bitset<56> K_56;
    
    int i = 1;
    while(i < bits){
        if(i == 1 || i == 49 || i == 385 || i == 721){
            C<<=2;
            D<<=2;
        }else{
            C<<=1;
            D<<=1;
        }
        for(int j = 0; j < 28; j++){
            K_56[j] = C[j];
            K_56[j+28] = D[j];
        }
        for(int j = 0; j < 48; j++)
        {
            if(i < bits)
            {
                output<<=1;
                if(K_56[PC2[j]])
                    output++;
                i++;
            }
        }
    }
    
    return output;
}

#endif