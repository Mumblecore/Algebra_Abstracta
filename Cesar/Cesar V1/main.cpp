
#include <iostream>
#include <string>
#include "Cesar.h"

using namespace std;

int main()
{
    Cesar a(4);
    Cesar b(4);

    cout << a.cif("ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmonpqrstuv 1234567890,.") << "\n";
    cout << b.des(a.cif("ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmonpqrstuv 1234567890,.")) << "\n";

    return 0;
}
