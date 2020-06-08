#include "Criba.h"
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int main()
{
    ZZ x;
    cin >> x;
    long y = conv<long>(x);
    Vec<ZZ> a;
    a.SetLength(y/4);

    auto t1 = Clock::now(), t2 = Clock::now();

    t1 = Clock::now();
    primos(a, x);
    t2 = Clock::now();
    cout << "tiempo: "<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()<< " .ms" << endl;

    // for(long i = 0; i < a.length(); i++)
    //     std::cout << a[i] << std::endl;

    return 0;
}

//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lm
//cd /Users/alan/Desktop/Proyectos/Abstracta/Criba 