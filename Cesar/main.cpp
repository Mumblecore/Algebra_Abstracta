#include <iostream>
#include <string>
#include "Cesar.h"

using namespace std;

int main()
{
    Cesar a;

    cout << a.cif("abcdefghijklmonpqrstuv 1234567890,.") << "\n";
    cout << a.des(a.cif("abcdefghijklmonpqrstuv 1234567890,.")) << "\n";

    return 0;
}
