### Conclusiones:

#### a)¿Cuáles son las debilidades y fortalezas del cifrado de Cesar (cifrado monoalfabético)?

Las principal fortaleza del Cesar viene a ser su facilidad para aplicar e implementar en distintos sitemas. Un cifrado que no lleva bastante tiempo y aun asi cumple con su función. Sin embargo esta fortaleza es la causante de su debilidad, el cifrado es fácil tanto para cifrar como para descifrar, inclusive si no se cuenta con la llave, un simple ataque por fuerza bruta es más que suficiente para romper el cifrado, puesto que solo se necesita (en el peor de los casos) un numero de intentos igual al tamaño del alfabeto que se esta utilizando (unos 26 en el caso del alfabeto inglés).

Además al ser monoalfabético (y poseer una unica clave), a cada palabra le corresponde otra, asi las palabras repetidas en el texto plano, vuelven a repetirse en el texto ya cifrado. Otra forma de romperlo, además de la fuerza bruta, sería por medio del analisis de la frecuencia de las letras o palabras(digramas o trigramas) más utilizidas en el idioma que se emplea.

#### b)¿Cuáles son las debilidades y fortalezas del cifrado de Vigenere (cifrado polialfabético)?

Su fortaleza proviene de la variedad en la clave, que se amplia enormemente, debido a que ahora la clave puede contenter un numero de caracteres que llega como máximo hasta el tamaño del mensaje, este número se multiplica por la cantidad de caracteres en el alfabeto, y aun asi, hay quue agregar que el numero caracteres en la subclaves en si es otra incognita para el hacker.

Su debilidad viene a ser una complicación en la implementación del mismo, que de todas formas no es mucha (ojo que el sistema tiene ya unos siglos de antiguedad). Además puede ser roto por ciertos metodos de criptoanalisis, uno de ellos es el metodo Kasiki, por el que utilizando la distancia entre palabras repetidas, se puede hallar la longitud de la clave, con lo cual, utilizando otra vez más las frecuencias de ciertas letras, es posible descifrar el mensaje tras un par de intentos. Un ataque por medio de fuerza bruta de forma manual viene a ser inutil a esta escala.
