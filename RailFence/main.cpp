#include <iostream>
#include "RailFence.h"

using namespace std;

int main()
{
    int n;
    cin >> n;

    RailFence A(n);

    string m;
    cin.ignore();
    getline(cin, m);
    cout << endl << A.Cifrar(m) << endl;
    cout << A.Descifrar(A.Cifrar(m)) << endl;
    
    return 0;
}