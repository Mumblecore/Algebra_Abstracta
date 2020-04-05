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

### 18.21

```cpp
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
    string s;
    getline(cin,s);

    for(int i = 0; i < s.size(); i++)       //loop que remplaza los s.de puntuacion por " "
    {
        if(ispunct(s[i]))
        {
            s.replace(i,1," ");
        }
    }

    string token = strtok(const_cast<char  *>(s.c_str())," ");  //crea el primer token en forma de string
  
    while (token.back() != '\0') {      //loop q imprime token por token
        cout << token << endl; 
        token = strtok(NULL, " ");      //actualiza el token
    } 
    return 0;
}
```
