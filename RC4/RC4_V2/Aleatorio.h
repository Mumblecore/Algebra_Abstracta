#include "Sistema.h"
#include <bitset>

using namespace std;

//positive mod
int pmod(size_t a, size_t b){return a - a/b * b;}

bitset<64> RC4()
{
    //Inicializacion=================================================================+
    unsigned char S[256], K[5];
    //--------------Para rellenar K hago uso de la entropy-pool de unix en /dev/random
    string K5 = StdoutFromTerminal("cat /dev/random | head -c 5");
    for(unsigned char i = 0; i < 255; i++){
        S[i] = i;
        K[i] = K5[i];
    }
    
    unsigned short f;
    for(unsigned char i = 0; i < 255; i++){
        f = pmod(f + S[i] + K[pmod(i, 5)], 256);
        swap(S[i], S[f]);
    }

    //Generacion de la secuencia cifrante============================================+
    f = 0;
    bitset<64> output;//--------------------vector que almacenara los 64bits de output
    for(unsigned char i = 0, k = 0, Or; i < 8; i++)
    {
        f = pmod(f + S[i], 256);
        swap(S[i], S[f]);
        Or = S[pmod(S[i] + S[f], 256)];
        for(int j = 0; j < 8; j++, k++){
            
            output[k] = ((Or & 1) ? true : false);
            Or>>=1;
        }
    }
    return output;
}

ZZ DES(short bits)
{
    ZZ output(1);
    output.SetSize(bits);
    //Paso de K por la PC1 & division en 28 bits=====================================+
    bitset<64> K_64 = RC4();
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
    
    //Generacion de subclaves de 48 bits=============================================+
    bitset<56> K_56;
    string K_output;
    
    int i = 1;
    while(i < bits){
        //-------------------------------vueltas donde el el desplazamiento es de a 2
        if(i == 1 || i == 49 || i == 385 || i == 721){
            C<<=2;
            D<<=2;
        }else{
            C<<=1;
            D<<=1;
        }
        //------------------------------------------------rellenar K_56 con C_n & D_n
        for(int j = 0; j < 28; j++){
            K_56[j] = C[j];
            K_56[j+28] = D[j];
        }
        //paso por PC2 y conversion a ZZ ===========================================+
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