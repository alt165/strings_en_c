/*
TP 4
INGCOM - 2022
Programacion 1 - Ingenieria en computacion
José Lambrechts
*/

#include <stdio.h>
#include <string.h>
#define MAX_CADENA 50
#define CADENA_SIN_TERMINADOR -1
#define OVERFLOW_CADENA -3
#define INDICE_INVALIDO -5
#define TRUE 1
#define FALSE 0

/* Prototipos funcionales */
int largo_cadena(int largo_cadena, char cadena[]);
int insertar_cadena(int len_cad1, int len_cad2, int posicion,
                    char cad_original[], char cad_insertar[]);
int copia_cadenas(int len_cad1, int len_cad2, char cad_original[],
                    char cad_copiar[]);
int limpia_cadena(int len_cad, char cadena[]);
int es_alfanum(char c);
int inversor_cadena(int len_cad, char cadena[]);

int main(int argc, char *argv[])
{   int resultado;
    char cadena1[MAX_CADENA];
    char cadena2[MAX_CADENA];
    
    /* strcpy(cadena1,"ASDF");
    strcpy(cadena2,"bcdef");

    insertar_cadena(MAX_CADENA,MAX_CADENA,2,cadena1,cadena2);
    printf("%s", cadena1);*/
    strcpy(cadena1,"asdfgh");
    printf("%s", cadena1);
    printf("\n");
    resultado = inversor_cadena(MAX_CADENA,cadena1);
    printf("%s", cadena1);
    printf("\n");
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
*  @param len_cad1 es el largo disponible de cad_original.
*  @param len_cad2 es el largo disponible cad_insertar.
*  @param posicion es la posicion en la que 
*                  se insertará cad_insertar.
*  @param cad_original  es la direccion de la cadena en la que se insertará
*                       cad_insertar.
*  @param cad_insertar  es la direccion de la cadena que se insertará
*
*  @pre len_cad1, len_cad2 son un enteros > 0.
*       posicion es un entero < len_cad1.
*       cad_original, cad_insertar son punteros no nulos a cadenas de caracteres.
*  @return  se devuelve un entero == 0 si se pudo ejecutar la insercion y != 0 si 
*           hubo error, los códigos de error están definidos en  #define y se suman
*           para devolver el acumulado de los errores. Si se excede 
*           la capacidad de cad_original no se inserta y se devuelve el error OVERFLOW_CADENA
*  @post    cad_original se modifica, con la inserción de cad_insertar en el
*           índice posicion, cad_insertar no se modifica.
 **/
int insertar_cadena(int len_cad1, int len_cad2, int posicion,
                    char cad_original[], char cad_insertar[])
{
    int resultado = 0;
    int total_caracteres, i;
    char cad_auxiliar[MAX_CADENA];
    if(largo_cadena(len_cad1, cad_original) == -1)
    {
        resultado = CADENA_SIN_TERMINADOR;
    }
    else
    {
        total_caracteres = largo_cadena(len_cad1, cad_original);
    }
    if(largo_cadena(len_cad2, cad_insertar) == -1)
    {
        resultado = CADENA_SIN_TERMINADOR;
    }
    else
    {
        total_caracteres = total_caracteres + largo_cadena(len_cad2, cad_insertar);
    }
    if (total_caracteres > len_cad1)
    {
        resultado = resultado + OVERFLOW_CADENA;
    }
    if (posicion > len_cad1)
    {
        resultado = resultado + INDICE_INVALIDO;
    }
    if (resultado == 0)
    /* si se dan las condiciones inserto una cadena en otra */
    {
        for(i = posicion; i <= len_cad1; i++)
        /* i <= len_cad1 incluye \0 */
        {
            cad_auxiliar[i - posicion] = cad_original[i];
            /* copiar en aux comenzando en posicion 0 */
        }
        for(i = posicion; i < len_cad1; i++)
        {
            cad_original[i] = cad_insertar[i - posicion];
        }
        int posicion_subcad_final = posicion + largo_cadena(len_cad2, cad_insertar);
        /* en este indice hay que comenzar a copiar la segunda parte de cad_original */
        for (i = posicion_subcad_final; i <= total_caracteres; i++)
        {
            cad_original[i] = cad_auxiliar[i -posicion_subcad_final];
        }
        
    }
    return resultado;
}

/** 
* La funcion inserta cad_copiar en cad_original al final de cad_original. 
*  @param len_cad1 es el largo disponible de cad_original.
*  @param len_cad2 es el largo disponible cad_insertar.
*  @param cad_original  es la direccion de la cadena en la que se insertará
*                       cad_insertar.
*  @param cad_copiar  es la direccion de la cadena que se insertará
*
*  @pre len_cad1, len_cad2 son un enteros > 0.
*       cad_original, cad_copiar son punteros no nulos a cadenas de caracteres.
*  @return  se devuelve un entero > 0  que es el largo de la cadena resultante si se pudo
*           ejecutar la insercion y < 0 si hubo error, los códigos de error están 
*           definidos en  #define y se suman
*           para devolver el acumulado de los errores. Si se excede 
*           la capacidad de cad_original no se inserta y se devuelve el error OVERFLOW_CADENA
*  @post    cad_original se modifica, con la inserción de cad_insertar en el
*           índice posicion, cad_copiar no se modifica.
 **/
int copia_cadenas(int len_cad1, int len_cad2, char cad_original[],
                    char cad_copiar[])
{
    int resultado = 0;
    int posicion;
    posicion = largo_cadena(len_cad1, cad_original);
    resultado = insertar_cadena(len_cad1, len_cad2,posicion, cad_original, cad_copiar);
    if (resultado == 0)
    {   
        resultado = largo_cadena(len_cad1, cad_original);        
    }
    
    return resultado;
}

/** 
* La funcion elimina los carácteres no alfanumericos de una cadena.
* Se eliminan tambien los carácteres que no pertenecen al idioma inglés.
*  @param len_cad es el largo disponible de cadena.
*  @param cadena  es la direccion de la cadena que se modificará
*
*  @pre len_cad es un entero > 0.
*       cadena es un puntero no nulo a una cadena de caracteres.
*  @return  se devuelve un entero > 0  que es el largo de la cadena resultante si se pudo
*           ejecutar la insercion y < 0 si hubo error, los códigos de error están 
*           definidos en  #define y se suman para devolver el acumulado de los errores. 
*  @post    cad_original se modifica de forma que no queden caracteres no alfanumericos
*           y los que aparecen están en el mismo orden que antes de ejecutar la función.
 **/
int limpia_cadena(int len_cad, char cadena[])  
{
    char cad_auxiliar[len_cad];
    int i;
    int cuenta_caracteres = 0;
    int resultado = 0;
    resultado = largo_cadena(len_cad, cadena);
    if (resultado > 0)
    {
        for (i = 0; i < resultado; i++)
        {
            if(es_alfanum(cadena[i]))
            {
                cad_auxiliar[i - cuenta_caracteres] = cadena[i];
            }
            else
            {
                cuenta_caracteres++;
            }
        }
        strcpy(cadena, cad_auxiliar);
        resultado = largo_cadena(len_cad, cadena);
    }
    

    return resultado;
}


/** 
* La funcion evalua si un caractes es alfanumérico.
* No se consideran los carácteres que no pertenecen al idioma inglés.
*  @param c es el caracter a evaluar.
*  @pre c es un caracter del código ascii.
*  @return  la función devuelve TRUE si c está entre a y z, A y Z o es un dígito
*           y FALSE si no lo es.
 **/
int es_alfanum(char c)
{
    int resultado = FALSE;
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        resultado = TRUE;
    }
    return resultado;
}

int inversor_cadena(int len_cad, char cadena[])
{
    char cadena_auxiliar[len_cad];
    int resultado = 0;
    int i;
    resultado = largo_cadena(len_cad, cadena);
    if (resultado > 0)
    {
        for(i = resultado - 1; i >= 0; i--)
        {
            cadena_auxiliar[resultado - i - 1] = cadena[i];
        }
        strcpy(cadena, cadena_auxiliar);
    }
    return resultado;
}