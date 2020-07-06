#include "Sistema.h"
#include <vector>

using namespace std;

//positive mod
int pmod(size_t a, size_t b){return a - a/b * b;}

vector<bool> RC4()
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
    vector<bool> k;                       //vector que almacenara los 64bits de output
    for(unsigned char i = 0, Or; i < 8; i++)
    {
        f = pmod(f + S[i], 256);
        swap(S[i], S[f]);
        Or = S[pmod(S[i] + S[f], 256)];
        for(int j = 0; j < 8; j++){
            k.push_back((Or & 1) ? true : false);
            Or>>=1;
        }
    }
    return k;
}