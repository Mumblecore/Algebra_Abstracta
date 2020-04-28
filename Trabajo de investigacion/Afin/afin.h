#ifndef AFIN_H
#define AFIN_H

#include <string>
#include "utilidades.h"

using namespace std;

class Afin{
    Afin();
    string cifrado(string mensaje , int multiplicacion , int desplazamiento);
    string descifrado(string mensaje ,int multiplicacion , int desplazamiento);

};

Afin::Afin(){
    int xyz = 0;
}

string Afin::cifrado(string mensaje ,int multiplicacion , int desplazamiento){
    string cifrado ;
    int size = mensaje.size();   // C = a x m + b    mod n  
    for(int i = 0 ; i < size ; i++){
        int pos = abc.find(mensaje[i]);
        pos = pos * multiplicacion + desplazamiento ;
        if (pos > abc_size)
            pos = mod(pos ,abc_size);
        cifrado += abc[pos];
    }
    return cifrado;
}

string Afin::descifrado(string mensaje ,int multiplicacion , int desplazamiento){
    string descifrado ;
    int size = mensaje.size();

    if ( gcd( multiplicacion , size) != 1){
        descifrado = "NO SE PUDO DESCIFRAR EL MENSAJE";
        return descifrado;
    }
        
    int inversa = ( multiplicacion , abc_size);

    for(int i = 0 ; i < size ; i++){
        int pos = abc.find(mensaje[i]) ;
        pos -= desplazamiento;
        pos *= inversa;
        if (pos < 0)
            pos = mod(pos ,abc_size);
        descifrado += abc[pos];
    }
    return descifrado;
}



#endif //Afin_H