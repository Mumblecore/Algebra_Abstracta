#include <iostream>
#include "Monbin.h"

using namespace std;

int main()
{
    Monbin a("AT ONE SIR");

    string m;
    getline(cin,m);
    cout << a.Cifrar(m) << endl;
    cout << a.Descifrar(a.Cifrar(m)) << endl;

    return 0;
}