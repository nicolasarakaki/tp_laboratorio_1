#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funcMatematicas.h"

static int esNumero(char* cadena);
static int getInt(int* pResultado);
int getNumInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error)
{
    int numeroAux;
    int retorno = -1;

    if(maximo>=minimo && reintentos>=0 && pNumero!=NULL && mensaje!=NULL && error!=NULL)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            fflush(stdin);
            if(getInt(&numeroAux)==0 && numeroAux >= minimo && numeroAux <= maximo)
            {
                *pNumero = numeroAux;
                retorno = 0;
                break;
            }
            else
                printf(error);
        }while(reintentos > 0);
    }
    return retorno;
}

static int esNumero(char* cadena)
{
    int retorno=-1;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            retorno = 0;
    }
    return retorno;
}

static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];
    scanf("%s", buffer);
    if(esNumero(buffer)==0)
    {
        *pResultado = atoi(buffer);
        retorno=0;
    }
    else
        retorno=-1;
    return retorno;
}

static int getFloat(float* pResultado);
int getNumFloat(float* pNumero, int reintentos, float minimo,
                float maximo, char* mensaje, char* error)
{
    int retorno = -1;
    float floatAux;

    if(maximo >= minimo && reintentos >= 0 && pNumero != NULL && mensaje != NULL && error != NULL)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            fflush(stdin);
            if(getFloat(&floatAux) == 0 && floatAux >= minimo && floatAux <= maximo)
            {
                *pNumero = floatAux;
                retorno = 0;
                break;
            }
            else
                printf("%s", error);
        }while(reintentos > 0);
    }
    return retorno;
}

static int getFloat(float* pResultado)
{
    int retorno;

    if(scanf("%f", pResultado) == 1)
        retorno=0;
    else
        retorno=-1;
    return retorno;
}

int mostrarMenu(float numero1, float numero2, int banderaA, int banderaB)
{
    int opcion;
    int auxOpcion;

    printf("\nElija una de las siguientes opciones: \n");

    if(banderaA==0)
        printf("\n1- Ingresar 1er operando (A=x)");
    else
        printf("\n1- Ingresar 1er operando (A=%.2f)", numero1);

    if(banderaB==0)
        printf("\n2- Ingresar 2do operando (B=y)");
    else
        printf("\n2- Ingresar 2do operando (B=%.2f)", numero2);

    printf("\n3- Calcular todas las operaciones");
    printf("\n    a- Calcular la suma (A+B)");
    printf("\n    b- Calcular la resta (A-B)");
    printf("\n    c- Calcular la division (A/B)");
    printf("\n    d- Calcular la multiplicacion (AxB)");
    printf("\n    e- Calcular el Factorial (A!) y (B!)");
    printf("\n4- Informar resultados");
    printf("\n5- Salir");

    fflush(stdin);
    if(getNumInt(&auxOpcion, 3, 1, 5, "\n\nIngrese una opcion: ", "Opcion Incorrecta")==0)
        opcion = auxOpcion;
    else
        opcion = -1;

    return opcion;
}

void mostrarInforme(float suma, float resta, float division,
                    float multiplicacion, int factorialA, int factorialB)
{
    printf("\n\n***INFORMES***\n\n");
    printf("\n    a- El resultado de A+B es: %.2f", suma);
    printf("\n    b- El resultado de A-B es: %.2f", resta);
    printf("\n    c- El resultado de A/B es: %.2f", division);
    printf("\n    d- El resultado de A*B es: %.2f", multiplicacion);
    printf("\n    e- El factorial de A es: %d y El factorial de B es: %d \n\n", factorialA, factorialB);
}
