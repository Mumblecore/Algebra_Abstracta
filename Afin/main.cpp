
#include <iostream>
#include "Afin.h"

using namespace std;

int main()
{
    Afin A;
    Afin B(*((int*)&A),*((int*)(&A) + 1));
    
    string s;
    getline(cin,s);

    cout << A.cifrar(s) << "\n";
    cout << B.descifrar(A.cifrar(s)) << "\n";
    return 0;
}