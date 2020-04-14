#ifndef CESAR_H
#define CESAR_H

#include <string>

using namespace std;

class Cesar
{
    public:
        Cesar(int);
        virtual ~Cesar();

        string cif(string);
        string des(string);
        string alf;

    private:
        int clave;
};

#endif // CESAR_H
