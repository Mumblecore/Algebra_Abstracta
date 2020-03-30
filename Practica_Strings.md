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

    cout << "Este es un string: ";

    for(int i = 0; i < s.size(); i++) 	//imprime char[]
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

### 2.-¿Cuál es la diferencia entre la función `capacity` y la función `size` de la clase string?

La función `size` retorna el numero de caracteres no nulos que contiene la string, mientras que la función `capacity` retorna la cantidad máxima de caracteres que puede almacenar el string, en otras palabras la capacidad de este. Esta puede ser igual o mayor al numero que tiene, lo que permite las operaciones que añaden caracteres a este.

Ejem:
```cpp
string s = hola;
cout << s.size();   //imprime 4
cout << s.capacity;  //imprime 15
```
### 5.-Crear un objeto string que esté formado por 1000 caracteres ‘a’, escribiendo una sola línea de código.

```cpp
string s(1000, 'a');
```
