#include <iostream>
#include "Polybios.h"

using namespace std;

int main()
{
    Polybios a;
    string msg = "POLYBIOS";
    cout << a.Cifrar(msg) << endl;
    cout << a.Descifrar(a.Cifrar(msg)) << endl;
    return 0;
}