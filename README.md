# TP C4

En este TP, vamos a implementar una libreria de funciones de cadenas.

## Forma de entrega

* Cada archivo debe seguir la estructura indicada dentro de `plantilla.c`, la cual debe
estar completa con su nombre y usuario de GitHub.
* La prolijidad cuenta.
* No mezclen tabuladores y espacios en la indentación.
* En ningún caso se aceptara el uso de variables globales. Toda la información 
  necesaria para el funcionamiento de las funciones a desarrollar tienen que ser
  pasado como argumentos de las mismas.
* Cada funcion implementada debe contar con un comentario sobre su prototipo que describa:
  * Las pre y poscondiciones de cada funcion implementada de forma coloquial
  * La descripción de los argumentos que recibe
  * La descripción de los valores que retorna.  
* Mantengan separado lo que es entrada, del algoritmo y la salida.
* Siempre que sea posible, los mensajes de commit deben ser descriptivos, nada de "cambios"
* ***En la medida de lo posible***, no utilicen las funciones de la libreria estandar.

# Fecha de entrega

La fecha de entrega de este TP es el dia viernes 7 de octubre a las 17 horas. (7/10/2022)

# Ejercicios

El programa que hace uso de estas funciones debe ser utilizando los argumentos de programa.
(argc/argv)

## Strings seguros

Manipular un arreglo de manera segura es poder limitar la cantidad de posiciones que serán recorridas en el caso de que la cadena de caracteres no cuente con su carácter de terminación (`\0`).

* Las funciones a implementar no pueden utilizar las funciones de la librería.
* Implementar las funciones indicadas a continuación en un único programa.
* Implementar un programa que haga uso de estas funciones con datos ingresados por la consola.

Todas las funciones deben retornar codigos de error como números negativos para las situaciones que se puedan encontrar, como que la cadena de destino es mas chica de lo que se necesita. Por ejemplo:

```c
#define CADENA_SIN_TERMINADOR -1
```

La entrega del ejercicio es sin la utilización de estructuras, si desean utilizarlas, haganló en un archivo separado.

### Largo de cadenas

Implementar una función que cuente el largo de una cadena de texto de manera segura, La función debe retornar el largo de la cadena o el código de error correspondiente.

Esta prototipo es un ejemplo para el resto de las funciones a implementar.
```C
/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es un puntero no nulo
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post 
 */
int largo_seguro(char cadena[], int capacidad);
``` 

### Inserción de cadenas

Implementar una función que inserte una cadena en otra luego de la posición indicada de manera segura.

Que hacer cuando la cadena destino no tiene la capacidad necesaria para alojar la cadena a insertar es
su decisión, la cual debe quedar registrada en el comentario de la función.

**Ejemplo**

Insertar "HOLA" en "Mundo" en la posición 2 daría como resultado "MunHOLAdo"

La función debe retornar el largo de la cadena destino o el código de error correspondiente.

### Copia de cadenas

Implementar una función que copie una cadena en otra y deje solo un `\0` en la cadena destino

La función debe retornar el largo de la cadena destino o el código de error correspondiente.

### Limpieza

Implementar una función que limpie la cadena de todos los caracteres que no sean los alfanuméricos (`AZaz09`) menos el `\0` en una cadena diferente a la de entrada.

La función debe retornar el largo de la cadena destino o el código de error correspondiente.

### Inversor

Implementar una función que en un string destino devuelva el de origen invertido.

**Ejemplo**

Hola -> aloH

### Comparación

Implementar una función que indique el ordenamiento alfabético de dos cadenas (solo minúsculas)

* -1 la primera cadena va antes de que las segunda
* 0 ambas cadenas son iguales
* 1 la primera cadena va después que la segunda.

### Contador de caracteres

Implementar una función que cuente los caracteres alfanuméricos de una cadena (`AZaz09`)

### Contador de simbolos

Implementar una función que cuente todos los otros caracteres de una cadena, aquellos que no son alfanuméricos.

### A minusculas y a mayusculas

Implementar una funcion que modifique la cadena dejando todos sus caracteres en minusculas.

### Palindromo seguro

Implementar una función que indique con TRUE si la cadena es un palindromo, con FALSE si no lo es o indicar un error si no posee `\0`.

Una palabra es palindromo cuando se puede leer de la misma manera en ambas direcciones.

Ignoren mayúsculas y minúsculas.

Neuquen -> es palindromo

***Opcionalmente***, pueden agregar un argumento para las opciones de la función, como ignorar
mayusculas/minusculas o simbolos.
