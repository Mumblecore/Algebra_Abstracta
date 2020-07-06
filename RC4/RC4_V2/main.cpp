#include "Aleatorio.h"

using namespace std;

int main()
{
    ZZ z;
    auto t1 = Clock::now();
    auto t2 = Clock::now();
    cout << "================================================================================\n";
    cout << "128 bits:\n";
    for(int i = 0; i < 10; i++){
        t1 = Clock::now();
        z = DES(128);
        t2 = Clock::now();
        cout << z;
        cout << "\ttiempo: " <<  std::chrono::duration_cast<Mili>(t2-t1).count() << " ms.\n";
    }
    cout << "================================================================================\n";
    cout << "512 bits:\n";
    for(int i = 0; i < 10; i++){
        t1 = Clock::now();
        z = DES(512);
        t2 = Clock::now();
        cout << z;
        cout << "\ntiempo: " <<  std::chrono::duration_cast<Mili>(t2-t1).count() << " ms.\n";
    }
    cout << "================================================================================\n";
    cout << "1024 bits:\n";
    for(int i = 0; i < 10; i++){
        t1 = Clock::now();
        z = DES(1024);
        t2 = Clock::now();
        cout << z;
        cout << "\ntiempo: " <<  std::chrono::duration_cast<Mili>(t2-t1).count() << " ms.\n";
    }

    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm
