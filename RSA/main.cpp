#include "Extensiones.h"

using namespace std;

int main()
{
    // ZZ a,b,c;
    // int n = 40000;
    // auto t1 = Clock::now();
    // auto t2 = Clock::now();
    // cin >> a >> b >> c;
    // t1 = Clock::now();
    // while(n--)
    //     expomod(a,b,c);
    // t2 = Clock::now();
    // cout << "tiempo: " << chrono::duration_cast<Mili>(t2 - t1).count() << " .ms\n";
    // cout << "mod: " << expomod(a,b,c) << endl;

    int n = 10;
    while(n--)
        cout << primo() << endl;

    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm