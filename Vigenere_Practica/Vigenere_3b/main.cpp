#include <iostream>
#include <string>
#include "Vigenere.h"

using namespace std;

int main()
{
    int alf;
    Vigenere a("Pablo Neruda");
    Vigenere b("Pablo Neruda");

    cout << "Ingrese el alfabeto: 1.Numerico 2.ASCII 3.HEX ";
    cin >> alf;

    switch(alf)
    {
    case 1:
        a.alf = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
        b.alf = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
        break;
    case 2:
        a.alf += (" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
        b.alf += (" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
        break;
    case 3:
        a.alf = "000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F202122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F404142434445464748494A4B4C4D4E4F505152535455565758595A5B5C5D5E5F606162636465666768696A6B6C6D6E6F707172737475767778797A7B7C7D7E7F";
        b.alf = "000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F202122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F404142434445464748494A4B4C4D4E4F505152535455565758595A5B5C5D5E5F606162636465666768696A6B6C6D6E6F707172737475767778797A7B7C7D7E7F";
        break;
    }

    cout << "Texto Normal:\n";
    cout << "Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso.";
    
    cout << "\n\nTexto Cifrado:\n";
    cout << a.cif("Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso.");
    
    cout << "\n\nTexto Descifrado:\n";
    cout << b.des(a.cif("Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso."));
    cout << endl;

    return 0;
}
