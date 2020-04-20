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
        //gagaga
        break;
    case 3:
        //ga
        break;
    }

    cout << "Texto Normal: \n";
    cout << "Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso.";
    cout << "\n\nTexto Cifrado: \n";
    cout << a.cif("Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso.");
    cout << endl << endl;;
    cout << "Texto Descifrado: \n";
    cout <<b.des(a.cif("Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso."));

    return 0;
}
