#include <iostream>
#include <string>
#include "Vigenere.h"

using namespace std;

void aqui(string &s)
{
    for (int i = 10 ; i < s.size() ; i+=14)
    {
       s.insert(i,"AQUI"); 
    }
    int mod = s.size() % 4;
    if (mod)
    {
       s.append(mod,'W');
    }
}

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
        a.ancho_car = 1;

        b.alf = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
        b.ancho_car = 1;
        break;
    case 2:
        // a.alf.resize(31);
        // a.alf += (" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
        // a.alf.resize(128);
        // b.alf.resize(31);
        // b.alf += (" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
        // b.alf.resize(128);
        break;
    case 3:
        a.alf = "000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F202122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F404142434445464748494A4B4C4D4E4F505152535455565758595A5B5C5D5E5F606162636465666768696A6B6C6D6E6F707172737475767778797A7B7C7D7E7F";
        a.ancho_car = 2;

        b.alf = "000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F202122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F404142434445464748494A4B4C4D4E4F505152535455565758595A5B5C5D5E5F606162636465666768696A6B6C6D6E6F707172737475767778797A7B7C7D7E7F";
        b.ancho_car = 2;
        break;
    }

    string msg("Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso.");

    aqui(msg);

    cout << "\nTexto Normal:\n";
    cout << msg;

    cout << "\n\nTexto Cifrado:\n";
    cout << a.cif(msg);

    cout << "\n\nTexto Descifrado:\n";
    cout << b.des(a.cif(msg));
    cout << endl;

    return 0;
}
