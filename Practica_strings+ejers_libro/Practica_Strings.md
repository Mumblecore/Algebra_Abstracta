### 1.-Convertir un objeto string a un array de tipo char, y viceversa.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin,s);

    char a[s.length()];
    s.copy(a, s.size(), 0);           	//string a char[]

    cout << "Este es un char[]: ";

    for(int i = 0; i < s.size(); i++) 	//imprime char[]
    {
        cout << a[i];
    }

    string t(a);                        //char[] a string
    cout << "\nEste es un string: " << t;	//imprime string

    return 0;
}
```

### 2.-¿Cuál es la diferencia entre la función `capacity` y la función `size` de la clase string?

La función `size` retorna el numero de caracteres no nulos que contiene la string, mientras que la función `capacity` retorna la cantidad máxima de caracteres que puede almacenar el string, en otras palabras la capacidad de este. Esta puede ser igual o mayor al numero que tiene, lo que permite las operaciones que añaden caracteres a este.

Ejem:
```cpp
string s = hola;
cout << s.size();   //imprime 4
cout << s.capacity;  //imprime 15
```

### 3.-Convertir las letras de un string de minúsculas a mayúsculas, y las mayúsculas a minúsculas.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] > 64 && s[i] < 91)
        {
            s[i] += 32;                         //Mayúscula a Minúscula
        }
        else if(s[i] > 96 && s[i] < 123)
        {
            s[i] -= 32;                         //Minúscula a Mayúscula
        }
    }
    
    cout << s;

    return 0;
}
```
### 4.-Recibir dos números por consola en variables tipo entero, luego construir un objeto string que concatene el primer número seguido del segundo número. Imprimir la cadena resultante, y en una nueva línea su valor multiplicado por 2. Usar funciones para convertir de string a entero y visceversa.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a,b;
    cin >> a;
    cin >> b;

    string s(to_string(a)+to_string(b));

    cout << s << "\n" << stoi(s)*2;

    return 0;
}
```

### 5.-Crear un objeto string que esté formado por 1000 caracteres ‘a’, escribiendo una sola línea de código.

```cpp
string s(1000, 'a');
```

### 6.-Convertir la cadena: “Yo desaprobe el curso de Algebra Abstracta” a la cadena: “Yo aprobe el curso de Algebra Abstracta”. 

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s("Yo desaprobe el curso de Algebra Abstracta");

    s.erase(3, 3);

    cout << s;

    return 0;
}
```

### 7.-Recibir dos strings por entrada estándar, una frase y una palabra. Contar cuántas veces aparece la palabra en la frase.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string f,p;

    getline(cin, f);
    getline(cin, p);

    int n = 0;

    for(int pos = f.find(p); pos != string::npos; pos = f.find(p, pos + 1);)
    {
        n++;
    }

    cout << n;

    return 0;
}

```
### 8.-Recibir un string de longitud N e imprimir cada letra del string en una nueva línea usando iteradores.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string::iterator i;

    for(i = s.begin(); i != s.end(); i++)
    {
        cout << *i << '\n';
    }

    return 0;
}
```

### 9.-Recibir dos strings por consola e imprimir un string que tenga al segundo string en la mitad el primer string. El primer string siempre tiene tamaño par.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    
    getline(cin, s);
    getline(cin, t);

    s.insert(s.size()/2, t);

    cout << s;

    return 0;
}
```

### 10.-Recibir tres strings por consola, buscar todas las apariciones del segundo string en el primero y reemplazarlas por el tercer string recibido.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s,a,b;

    getline(cin, s);
    getline(cin, a);
    getline(cin, b);
    
    for(int pos = s.find(a); pos != string::npos; pos = s.find(a, pos + 1))
    {
        s.replace(s.find(a), a.size(), b);
    }

    cout << s;

    return 0;
}
```

### 11.-Dadas dos palabras, imprimir la que es lexicográficamente mayor.

```cpp
#include <iostream>

using namespace std;

int main()
{
    string a,b;
    
    getline(cin, a);
    getline(cin, b);

    cout << (a.compare(b) > 0 ? a : b);

    return 0;
}
```

### 12.-Crear una función que reciba un número N (N va de 1 a 10), y que escriba N números con valores que van de 1 a 1000 en un archivo llamado “numeros.txt”.

```cpp
void numeros(int n)
{
    if(n>0 && n<11)
    {
        ofstream nums_o;
        nums_o.open("numeros.txt", ios::out);

        while(n--)
        {
            nums_o << rand()%1000 + 1 << "\n";
        }
    }
}
```

### 13.	Leer los números en el archivo “numeros.txt” de la pregunta 12 e imprimir la sumatoria.

```cpp
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void numeros(int n);

int main()
{
    int n;

    cout << "Ingrese un numero del 1 al 10: ";
    cin >> n;

    ifstream nums_i;
    nums_i.open("numeros.txt", ios::in);

    //SUMATORIA

    int x;
    int s;

    while (nums_i >> x) {
        s += x;
    }

    cout << s << "\n";

}
```
