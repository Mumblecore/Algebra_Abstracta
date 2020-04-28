#include "divInt.h"

divInt::divInt(int a, int n)
{
    this->a = a;
    this->n = n;

    if(n < 1){
        n = -n;
    }

    q = a/n;
    r = a%n;

    if(a < 0){
        q--;
        r += n;
    }


}
