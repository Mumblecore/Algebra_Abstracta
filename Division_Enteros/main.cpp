#include <iostream>
#include <divInt.h>

int main()
{
    int a,n;
    std::cin >> a >> n;
    std::cout << std::endl;

    divInt d(a, n);
    std::cout << "q = "<< d.q<< std::endl;
    std::cout << "r = "<< d.r<< std::endl;
    return 0;
}
