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

### 18.22

```cpp
#include <iostream>
#include <string>

using namespace std;

int main ()
{
  string s;
  getline(cin,s);
  for (string::reverse_iterator i = s.rbegin(); i != s.rend(); ++i){
      cout << *i;
  }
  cout << endl;

  return 0;
}
```

### 18.27

```cpp
#include <iostream>
#include <string>

using namespace std;


bool asc(string a, string b)
{
    return (a.compare(b) < 0);
}

bool dsc(string a, string b)
{
    return (a.compare(b) > 0);
}

void selectionSort(string a[], int n, bool(*compara)(string, string))  
{  
    int menOmay;  
  
    for (int i = 0; i < n-1; i++)  
    {  
        menOmay = i;  
        for (int j = i+1; j < n; j++)  
            if (!(*compara)(a[menOmay],a[j])){
                menOmay = j;  
            }
        swap(a[menOmay], a[i]);  
    }  
} 

void printArray(string a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main ()
{
    string s[5] = {"hola", "alan", "captura", "cama", "acido"};

    printArray(s,5);

    int orden;
    cout << "\nOrden(1 = ascendente / 0 = descendente) ";
    cin >> orden;

    (orden) ? selectionSort(s,5,asc) : selectionSort(s,5,dsc);

    printArray(s,5);

    return 0;
}
```
