#include "Extensiones.h"

using namespace std;

int main()
{//limite superior de p_i ingresado por consola
    ZZ n;
    cin >> n;
//vectores a_i & p_i
    Vec<ZZ> a,p;
    p.SetLength(conv<long>(n));

/*convertimos a p_i en un vector de primos para que todos sus
  elementos sean coprimos y el teorema del resto chino pueda
  funcionar.*/
    p[0] = 2;
    p[1] = 3;
    bool primo = true;
    long tam = 2;
    for(ZZ i(5); i < n; i+=2){
        for(long j = 1; i >= p[j] * p[j];j++)
            if(nmod(i, p[j]) == 0){
                primo = false;
                break;
            }
        if(primo)
            p[tam++] = i;
        primo = true;
    }
//tanto a como p deben tener el mismo tamanio
    p.SetLength(tam);
    a.SetLength(tam);
/*llenamos a con valores de 1 a p.size() que en este caso es igual a tam
  de paso que imprimimos las ecuaciones en consola*/
    ZZ j(1);
    for(long i = 0; i < tam; i++){
        a[i] = j;
        cout << "x = " << a[i] << " mod " << p[i] << "\n";
        j++;
    }

//imprimimos X
    resto_chino(a,p);
    cout << "\nX = " << resto_chino(a,p) << endl;

    return 0;
}
//g++ -g -O2 -std=c++11 -pthread -march=native main.cpp -o main -lntl -lgmp -lm
