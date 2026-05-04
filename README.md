# Prueba-Diagnostica-Giovanni-Martinez
Scripts hechos en el lenguaje C++ para la resolución de 3 problemas planteados en la prueba diagnóstica de la materia Lenguajes y Compiladores.
Se adjunta tambien un video subido a la plataforma de YouTube explicando el funcionamiento y explicación lógica de cada uno de los scripts presentados en este repositorio

# Link del video explicativo
https://youtu.be/jegn1vtI19s

## Configuraciones
* **IDE UTILIZADO:** EMBARCADERO DEV-C++ 6.3
* **COMPILADOR:** TDM-GCC 9.2.0 64-bit Release

## Librerías utilizadas
* **cctype** -> Permitiendo la verificacion de caracteres con isdigit(), isalpha(), isalnum(), isspace(c)

* **string** -> Para trabajar con cadenas de texto y el uso de metodos como .length() y concatenacion

* **vector** -> Uso de listas 

* **sstream** -> Dividir strings como si fueran entradas (cin) 

## Problema 1: Detección de componentes dada una expresión aritmética
El programa le pide al usuario que ingrese una expresión aritmética y al darle enter arrojará como salida todos los componentes que haya detectado.

Ejemplo: 12+4*(3+2.5)

Salida: NUMERO 12 OPERADOR + NUMERO 4 PAREN_IZQ (NUMERO 3 OPERADOR + NUMERO 2 DECIMAL 5 PAREN_DER)

## Problema 2: Detección de una cadena de texto con Notación FEN (Forsyth-Edwards)
El programa le pide al usuario que ingrese una cadena de texto y el programa verificara si está escrito en notación FEN; utilizada para describir el estado en que se encontraba una partida de ajedrez
Como la cadena tiene una serie de reglas y orden para identificar el estado del juego. El programa verifica por partes la cadena de texto ingresada por el usuario en busca de patrones como la descripción de las filas que tienen que ser 8 y tiene que describir lo que se encuentra en las 8 casillas, las letras que son aceptadas para representar una pieza del ajedrez y el orden de los campos: tablero, turno, enroque, captura al paso, movimientos.

**1r6/5pp1/R1R4p/1r1pP3/2pkQPP1/7P/1P6/2K5 w - - 0 41 -> Esto es un ejemplo de una cadena con notación FEN**

## Problema 3: Demostración de conjetura de Collatz dada un intervalo de números
Para este problema se hace un programa donde el usuario tiene que dar un intervalo de numeros (mínimo y maximo), y entre esos números se ejecutara una serie de cálculos para demostrar la conjetura de Collatz que nos dice:

**"Si n es par → n = n / 2, Si n es impar → n = 3n + 1"** 

Una vez que el usuario haya ingresado el intervalo de números, el programa irá haciendo esos cálculos según el número sea par o impar. Con esto se demostraría que los númueros siempre terminará en la siguiente secuencia: **4 - 2  -  1**
Esto se podrá visualizar en el vídeo que pueden encontrar en el repositorio.
