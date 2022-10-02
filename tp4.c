/*
TP 4
INGCOM - 2022
Programacion 1 - Ingenieria en computacion
José Lambrechts
*/

#include <stdio.h>
#define MAX_CADENA 50
#define CADENA_SIN_TERMINADOR -1
#define OVERFLOW_CADENA -2
#define CADENA_INVALIDA -3

/* Prototipos funcionales */
int largo_cadena(int largo_cadena, char cadena[]);
int insertar_cadena(int len_cad1, int len_cad2, int posicion,
                    char cad_original[], char cad_insertar[]);

int main(int argc, char *argv[])
{   int resultado;
    resultado = largo_cadena(5, "asdfaaa");
    printf("%d", resultado);
   return 0;
}


/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena[] es la direccion de la cadena con la que se contaran los caracteres
 *  @pre        cadena es un puntero no nulo
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                y es el tamaño en memoria del arreglo
 *  @pre        es un valor numerico entero positivo mayor a uno
 *  @returns    int en donde los valores positivos incluyendo el cero representan la cantidad de 
 *              caracteres y los valores negativos, las siguientes situaciones de error:
                CADENA_SIN_TERMINADOR cuando la cantidad de caracteres sea por lo menos igual 
                a la capacidad indicada por el argumento
 *  @post       la cadena pasada como parámetro no se modifica y el resultado es un int > 0 si 
                se encontró el caracter \0 y -1 si no se puede obtener el largo
 */
int largo_cadena(int largo_cadena, char cadena[])
{
    int resultado, i;
    for(i = 0; i < largo_cadena && cadena[i] != '\0'; i++);
    /* el ciclo no tiene sentencias porque solo se ejecuta 
    para recorrer la cadena */
    if (i == largo_cadena){
        resultado = CADENA_SIN_TERMINADOR;
    }
    else
    {
        resultado = i;
    }
    return resultado;
}

/** 
* La funcion inserta cad_insertar en cad_original en el índice 
* representado en posicion.
*  @param len_cad1 es el largo de cad_original.
*  @param len_cad2 es el largo de cad_insertar.
*  @param posicion es la posicion en la que 
*                  se insertará cad_insertar.
*  @param cad_original  es la direccion de la cadena en la que se insertará
*                       cad_insertar.
*  @param cad_insertar  es la direccion de la cadena que se insertará
*
*  @pre len_cad1, len_cad2 son un enteros > 0.
*       posicion es un entero < len_cad 1.
*       cad_original, cad_insertar son punteros no nulos a cadenas de caracteres.
*  @return  se devuelve un entero == 0 si se pudo ejecutar la insercion y != 0 si 
*           hubo error, los códigos de error están definidos en  #define.
*  @post    cad_original se modifica, con la inserción de cad_insertar en el
*           índice posicion, cad_insertar no se modifica.
 **/
int insertar_cadena(int len_cad1, int len_cad2, int posicion,
                    char cad_original[], char cad_insertar[])
{
    int resultado = 0;
    int total_caracteres;
    char cad_auxiliar[MAX_CADENA];
    if(largo_cadena(len_cad1, cad_original) == -1)
    {
        resultado = CADENA_INVALIDA;
    }
    else
    {
        total_caracteres = largo_cadena(len_cad1, cad_original);
    }
    if(largo_cadena(len_cad2, cad_insertar) == -1)
    {
        resultado = CADENA_INVALIDA;
    }
    else
    {
        total_caracteres = largo_cadena(len_cad1, cad_original);
    }

}
