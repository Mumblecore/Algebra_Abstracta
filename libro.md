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

    cout << "\nHola " << c << "\n";
    
    return 0;
}
```
### 18.19

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    
    s.insert(s.size()/2, "******");

    cout << s << endl;
    
    return 0;
}
```
