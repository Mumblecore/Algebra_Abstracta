#include "Rc4.h"

using namespace std;

int main()
{
    RC4(32);
    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm

//LC_CTYPE=C tr -dc 0-9 < /dev/random | head -c 20 | xargs
//LC_CTYPE=C tr -dc 0-9 < /dev/fd/0 | head -c 20 | xargs
