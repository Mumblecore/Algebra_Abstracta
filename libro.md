### 18.7

```cpp
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string s;
    getline(cin,s);

    for(int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i]))
        {
            if(s[i] > 96)
            {
                s[i] += ((s[i] < 109) ? 13 : -13);
            }else
            {
                s[i] += ((s[i] < 77) ? 13 : -13);
            }
            
        }
    }

    cout << s << endl;

    return 0;
}
```
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
### 18.12

```cpp
#include <iostream>
#include <string>

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
    string p("gato");
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
