#include <fstream>
#include "funciones.h"

int main()
{
   fstream f("nros.txt", ios_base::in);

   ZZ a, b;

   f >> a >> b;
   
   cout << foo1(a,b) << endl;
   cout << endl << "Algoritmo 2: " << endl << foo2(a,b) << endl;
   //cout << endl << "Algoritmo 3: " << endl << foo3(a,b) << endl;
   //cout << endl << "Algoritmo 4: " << endl << foo4(a,b) << endl;
   cout << endl << "Algoritmo 5: " << endl << foo5(a,b) << endl;
   cout << endl << "Algoritmo 6: " << endl << foo6(a,b) << endl;

   return 0;
}

//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm