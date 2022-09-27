/*
TP 4
INGCOM - 2022
Programacion 1 - Ingenieria en computacion
José Lambrechts
*/

#include <stdio.h>
#define MAX_CADENA 50
#define CADENA_SIN_TERMINADOR -1

int largo_cadena(int largo_cadena, char cadena[])
{
    int resultado, i;
    for(i = 0; i < largo_cadena && cadena[i] != '\0'; i++);
    if (i == largo_cadena){
        resultado = CADENA_SIN_TERMINADOR;
    }
    else
    {
        resultado = i;
    }
    return resultado;

}

int main(int argc, char *argv[])
{   int resultado;
    resultado = largo_cadena(5, "asdfaaa");
    printf("%d", resultado);
   return 0;
}