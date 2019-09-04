#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funcMatematicas.h"

float operacionSuma(float valor1, float valor2)
{
    float resultado;
    resultado = valor1 + valor2;
    return resultado;
}

float operacionResta(float valor1, float valor2)
{
    float resultado;
    resultado = valor1 - valor2;
    return resultado;
}

float operacionDiv(float valor1, float valor2)
{
    float resultado;
    if(valor2==0)
        printf("\nNo es posible la division por cero\n");
    else
        resultado = valor1 / valor2;

    return resultado;
}

float operacionMult(float valor1, float valor2)
{
    float resultado;
    resultado = valor1 * valor2;
    return resultado;
}

static int getEnteroPositivo(float* pResultado);

int operacionFactorial(float valor1)
{
    int resultado;
    int factorial=1;
    int i;

    if(getEnteroPositivo(&valor1)==-1)
    {
        printf("\nNo existe el factorial del numero %.2f, por ser negativo o fraccion\n\n", valor1);
        resultado = -1;
    }
    else if(valor1==0)
        resultado= 1;
    else
    {
       for(i=1; i<=valor1; i++)
       {
            factorial = factorial * i;
            resultado = factorial;
       }
    }
    return resultado;
}

static int getEnteroPositivo(float* pResultado)
{
    int retorno=-1;
    int auxResultado = *pResultado;
    float resto = *pResultado - auxResultado;

    if(*pResultado >= 0 && resto==0)
        retorno=0;

    return retorno;
}
