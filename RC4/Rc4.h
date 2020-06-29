#include "Sistema.h"

using namespace std;

string StdoutFromTerminal(string cmd) {

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

ZZ stringToZZ(string str)
{
    ZZ z;
    istringstream(str) >> z;
    return z;
}

void RC4(long bits)
{
    Vec<ZZ> S,K;
    S.SetLength(bits);
    K.SetLength(bits);
    //rellenar S
    for(long i = 0; i < bits; i++)
        S[i] = conv<ZZ>(i);

    //rellenar K
    for(long i = 0; i < 4; i++){
        K[i] = stringToZZ(StdoutFromTerminal("LC_CTYPE=C tr -dc 0-9 < /dev/random | head -c 8 | xargs"));
    }

    ZZ f;
    for(long i = 0, i_k = 0; i < bits; i++){
        if(i_k == bits)
            i_k = 0;
        f = nmod(f + S[i] + K[i_k++], conv<ZZ>(bits));
        swap(S[i], S[conv<int>(f)]);
    }

    // int i = 0;
    // int j = 0;
    // i = (i + 1) % bits;
    // j = (j + S[i]) % bits;
    // swap(S[i], S[j]);
    // int t = (S[i] + S[j])%256;
    // return S[t];

    for(int i = 0; i < bits; i++)
        cout << S[i] << " ";
    cout << endl;

}