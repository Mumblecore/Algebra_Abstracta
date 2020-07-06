#include "Sistema.h"

using namespace std;

void RC4(long bits)
{
    Vec<ZZ> S,K;
    S.SetLength(bits);
    //rellenar S
    for(long i = 0; i < bits; i++)
        S[i] = conv<ZZ>(i);

    //K contendra 6 variables: load-average(3), CPUload(1), MemoryUsage(1) y el tiempo
    //que demorara calcular todo esto
    K.SetLength(6);
    auto t1 = Clock::now();
    AddLoadAverage(K);
    K[3] = GetSystemMemoryUsagePercentage();
    K[4] = ZZCPULoad();
    auto t2 = Clock::now();
    long time = chrono::duration_cast<Nano>(t2-t1).count();
    K[5] = ZZ(conv<ZZ>(time));

    cout << "K: ";
    for(int i = 0; i < 6; i++)
        cout << K[i] << " ";
    cout << endl;

    ZZ f;
    for(long i = 0, i_k = 0; i < bits; i++){
        if(i_k == K.length())
            i_k = 0;
        f = nmod(f + S[i] + K[i_k++], conv<ZZ>(bits));
        swap(S[i], S[conv<int>(f)]);
    }

    //Resto del algoritmo que deberia estar en un bucle
    // int i = 0;
    // int j = 0;
    // i = (i + 1) % bits;
    // j = (j + S[i]) % bits;
    // swap(S[i], S[j]);
    // int t = (S[i] + S[j])%256;
    // return S[t];

    //demostracion de S intercambiado
    for(int i = 0; i < bits; i++)
        cout << S[i] << " ";
    cout << endl;

}