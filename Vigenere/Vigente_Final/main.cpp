#include <iostream>
#include <string>
#include "Vigenere.h"

using namespace std;

int main()
{
    int alf;

    Vigenere a("clave");
    Vigenere b("clave");

    cout << "Ingrese el alfabeto: 1.Numerico 2.ASCII 3.HEX ";
    cin >> alf;

    switch(alf)
    {
    case 1:
        a.alf = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
        a.com = 0;
        b.alf = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
        b.com = 0;
        break;
    case 2:
        a.alf = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
        a.com = 32;
        b.alf = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
        b.com = 32;
        break;
    case 3:
        a.alf = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
        a.com = 0x20;
        b.alf = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
        b.com = 0x20;
        break;
    }

    string msg("Mensaje secreto");

    cout << "\nTexto:\n";
    cout << msg;

    cout << "\n\nTexto Cifrado:\n";
    cout << b.cif(msg);
    cout << endl;

    return 0;
}
