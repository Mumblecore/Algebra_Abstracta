### 18.11

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b,c;
    cout << "Nombre: ";
    getline(cin,a);
    cout << "Apellido: ";
    getline(cin,b);
    
    c = a + " " + b;

    cout << "/nHola " << c << endl;
}
```
