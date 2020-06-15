#ifndef RSA_H
#define RSA_H

#include <string>
#include "Extensiones.h"

using namespace std;

class RSA
{
private:
    ZZ clave_publica;
    ZZ clave_privada;

    string alf;
public:
    RSA();
    RSA(ZZ pub);

    string cifrar(ZZ msg);
    string descifrar(ZZ msg);
};

RSA::RSA()
{
    ZZ p,q;

}

RSA::RSA(ZZ pub)
{

}

string RSA::cifrar(ZZ msg)
{
    
}

string RSA::descifrar(ZZ msg)
{
    
}

#endif