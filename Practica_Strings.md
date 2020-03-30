### 1.-Convertir un objeto string a un array de tipo char, y viceversa.

```cpp {cmd=node .line-numbers}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin,s);

    char a[s.length()];
    s.copy(a, s.length(), 0);           	//string a char[]

    cout << "Este es un string: ";

    for(int i = 0; i < s.length(); i++) 	//imprime char[]
    {
        cout << a[i];
    }

    string t;
    for(int i = 0; a[i] != '\0'; i++)   	//char[] a string
    {
        t += a[i];
    }
    cout << "\nEste es un char[]: " << t;	//imprime string

    return 0;
}
```
