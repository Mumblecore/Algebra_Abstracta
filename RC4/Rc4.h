#include "Extensiones.h"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/unistd.h>

ZZ Seed(int Sbits, int Kbits)
{
    // for i from 0 to 255
    //     S[i] := i
    // endfors
    // j := 0
    // for i from 0 to 255
    //     j := (j + S[i] + key[i mod keylength]) mod 256
    //     swap values of S[i] and S[j]
    // endfor
    ZZ Smax(1);
    Smax <<= Sbits;
    Vec<ZZ> S,K;
    for(ZZ i; i < Smax; i++)
        S.append(i);

    return Smax;
}