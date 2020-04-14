#include <iostream>
#include <string>
#include "Vigenere.h"

using namespace std;

int main()
{
    Vigenere a("ef A");
    Vigenere d("ef A");

    cout << a.cif("abc Fg") << "\n";
    cout << d.des(a.cif("abc Fg")) << "\n";

    return 0;
}
