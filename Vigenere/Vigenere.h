#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

using namespace std;

class Vigenere
{
    public:
        Vigenere(string);
        virtual ~Vigenere();

        string cif(string);
        string des(string);
        string alf;
        
    private:
        string clave;
};

#endif // VIGENERE_H
