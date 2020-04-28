### 18.7 
Cierta información en Internet se puede cifrar con un algoritmo simple conocido como “rot13”, el
cual rota cada carácter 13 posiciones en el alfabeto. Así, 'a' corresponde a 'n', y 'x' corresponde a 'k'. rot13 es un ejemplo
del cifrado de clave simétrica. Con este tipo de cifrado, tanto el que cifra como el que descifra utilizan la misma clave.

a) Escriba un programa que cifre un mensaje usando rot13.
b) Escriba un mensaje que descifre el mensaje codifi cado usando 13 como la clave.
c) Después de escribir los programas de los incisos (a) y (b), responda brevemente a la siguiente pregunta: si no cono-
ciera la clave para el inciso (b), ¿qué tan difícil cree usted que sería quebrantar el código? ¿Qué pasaría si tuviera
acceso a un poder de cómputo considerable ( por ejemplo, supercomputadoras)? En el ejercicio 18.26 le pediremos
que escriba un programa para lograr esto.

```cpp
#include <iostream>
#include <string>

using namespace std;

/*
Este programa sirve tanto para codificar como para decodificar mensajes en rot13, dado que al tener el alfabeto 26 letras,
al rotar las letras 13 espacios dos veces, se voleria al lugar de origen. Un mensaje ya cifrado saldria como uno sin cifrar
*/

int main ()
{
    string s;
    getline(cin,s);

    for(int i = 0; i < s.size(); i++)			//loop q codifica char por char
    {
        if(isalpha(s[i]))				//verifica si es alfabetica(numeros y signos no)
        {
            if(s[i] > 96)
            {
                s[i] += ((s[i] < 109) ? 13 : -13);	//cod para minusculas
            }else
            {
                s[i] += ((s[i] < 77) ? 13 : -13);	//cod para mayusculas
            }
            
        }
    }

    cout << s << endl;

    return 0;
}
```
### 18.11
Escriba un programa que introduzca por separado un primer nombre y un apellido, y que concatene los dos en un
nuevo objeto string.

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
### 18.12
Escriba un programa para jugar al ahorcado.

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void dibujar(string s, int n)
{
    system("cls");              //limpia la pantalla

    cout << "Adivine la palabra:\t" << s << "\n";           //muestra "XXXXXXX"

    string ahorcado[7] =
    {
        "\t o\n",
        "\t/","|","\\ \n",
        "\t | \n",
        "\t/ ","\\ \n"
    };

    for(int i = 0; i < n; i++)
    {
        cout <<ahorcado[i];             //imprime las partes del cuerpo segun el numero de intentos incorrectos
    }
}
int main()
{
    string pal[5] = {"gato", "perro", "caballo", "lanza", "tarea"};
    string p = pal[rand()%5];
    string o(p.size(), 'x');
    string c;

    cout << "Adivine la palabra:\t" << o << "\n\n";
    int int_ = 0;       //nro de intentos
    int inco = 0;       //nro de intentos incorrectos

    bool juego = 1;     //controla si el ususario sigue jugando
    while(juego)        //loop del juego
    {
        cout << "\nIngrese: ";
        cin >> c;

        if (p.find(c) != string::npos)              //si encuentra lo ingresado por el usuario:
        {
            for(int pos = p.find(c); pos != string::npos; pos = p.find(c, pos + 1))
            {
                o.replace(pos, c.size(), c);        //reemplaza todas las conicidencias
            }
        }
        else
        {
            inco++;
        }
        int_++;

        dibujar(o,inco);    //llama a la funcion para limpiar la pantalla y preparar la siguiente entrada

        if(p==o || inco==7)     //revisa cada jugada si se perdio o gano
        {
            cout << "\nNumero de intentos: " << int_;   //muestra el nro de intentos cque le llevo al jugador
            cout << ((inco==7) ? "\nPerdiste." : "\nFelicidades!!! Adivino mi palabra." );
            jugar:
                cout << "Desea jugar otra vez? si/no ";
                string rpta;
                cin >> rpta;

                if(rpta == "si"){   //asigna 0 a las variables y vuelve XXX a la string a comparar
                    int_ = 0;
                    inco = 0;
                    p = pal[rand()%5];
                    o.assign(p.size(), 'x');
                    dibujar(o,inco);
                }else if(rpta == "no")
                    juego = 0;
                else
                    goto jugar;     //si no entiende la respuesta vuelve a preguntar
        }
    }
	return 0;
}
```

### 18.19
Escriba un programa que inserte los caracteres "******" en la mitad exacta de un objeto string.

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
Escriba un programa que introduzca una línea de texto, reemplace todos los signos de puntuación con espacios y utilice
la función strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).
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
Escriba un programa que introduzca una línea de texto y la imprima al revés. Use iteradores en su solución.
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
Escriba una versión de la rutina de ordenamiento por selección (fi gura 8.28) que ordene objetos string. Use la función
swap en su solución.
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
