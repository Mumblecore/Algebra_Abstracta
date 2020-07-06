#include "Aleatorio.h"

using namespace std;

int main()
{
    vector<bool> ga = RC4();
    for(int i = 0; i < ga.size(); i++)
        cout << ga[i];
    cout << endl;
    // auto t1 = Clock::now();

    // auto t2 = Clock::now();
    // cout << std::chrono::duration_cast<Nano>(t2-t1).count() << endl;

    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm
