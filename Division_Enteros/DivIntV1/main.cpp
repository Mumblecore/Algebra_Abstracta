#include <iostream>
#include <divInt.h>

int main()
{
    int a,n;
    std::cin >> a >> n;
    std::cout << std::endl;

    std::cout << div(a,n) << std::endl;
    std::cout << mod(a,n) << std::endl;
    return 0;
}
