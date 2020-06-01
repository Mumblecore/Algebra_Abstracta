#include <fstream>
#include <chrono>
#include "funciones.h"
#include "inversa.h"

class Timer
{
    using clk = std::chrono::steady_clock;
    using microseconds = std::chrono::microseconds;

    clk::time_point tsb;
    clk::time_point tse;

public:

    void clear() { tsb = tse = clk::now(); }
    void start() { tsb = clk::now(); }
    void stop() { tse = clk::now(); }

    friend std::ostream& operator<<(std::ostream& o, const Timer& timer)
    {
        return o << timer.secs();
    }

    // return time difference in seconds
    double secs() const
    {
        if(tse <= tsb)
            return 0.0;
        auto d = std::chrono::duration_cast<microseconds>(tse - tsb);
        return d.count() / 1000000.0;
    }
};

int main()
{
   ifstream input("numeros.txt");
   ZZ a, b;
   input >> a >> b;

   Timer timer;

   cout << "Algoritmo 1: " << endl;
   timer.start();
   foo1(a,b);
   timer.stop();
   cout << "tiempo: "<< timer << " s." << endl;

   cout << "Algoritmo 2: " << endl;
   timer.start();
   foo2(a,b);
   timer.stop();
   cout << "tiempo: "<< timer << " s." << endl;
   
//    cout << "Algoritmo 3: " << endl;
//    timer.start();
//    foo3(a,b);
//    timer.stop();
//    cout << "tiempo: "<< timer << " s." << endl;
   
//    cout << "Algoritmo 4: " << endl;
//    timer.start();
//    foo4(a,b);
//    timer.stop();
//    cout << "tiempo: "<< timer << " s." << endl;
   
   cout << "Algoritmo 5: " << endl;
   timer.start();
   foo5(a,b);
   timer.stop();
   cout << "tiempo: "<< timer << " s." << endl;
   
//    cout << "Algoritmo 6: " << endl;
//    timer.start();
//    foo6(a,b);
//    timer.stop();
//    cout << "tiempo: "<< timer << " s." << endl;

    // ZZ a(98723645431);
    // ZZ b(9827364);
    // ZZ c;

    // // if(inversa(a, b, c))
    // // {
    // //     cout << "\nSi tiene inversa\n";
    // //     cout << "Inversa: " << c << "\n";
    // // }

    // cout << "Inversa: " << endl;
    // timer.start();
    // foo6(a,b);
    // timer.stop();
    // cout << "tiempo: "<< timer << " s." << endl;
   
   return 0;
}

//g++ -g -O2 -std=c++11 -pthread -march=native gcd.cpp -o gcd -lntl -lgmp -lm