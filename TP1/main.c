#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funcMatematicas.h"

int main()
{
    int flagA=0, flagB=0, flagCalculosCargados=0;
    int resultadoFactA, resultadoFactB;
    float operadorA, operadorB;
    float resultadoSuma, resultadoResta, resultadoDiv, resultadoMult;
    char respuesta = 's', auxRespuesta;

    do
    {
        switch(mostrarMenu(operadorA, operadorB, flagA, flagB))
        {
            case 1:
                if(getNumFloat(&operadorA, 3, MIN, MAX,"\n Ingrese numero para el 1er operando A: ", "\n\nDEBE SER UN NUMERO\n")==0)
                {
                    flagA=1;
                    flagCalculosCargados=0;
                }
                else
                    printf("\nERROR EN LA CARGA DE DATOS...\n\n");
                break;

            case 2:
                if(getNumFloat(&operadorB, 3, MIN, MAX,"\n Ingrese numero para el 2do operando B: ", "\n\nDEBE SER UN NUMERO\n")==0)
                {
                    flagB=1;
                    flagCalculosCargados=0;
                }
                else
                    printf("\nERROR EN LA CARGA DE DATOS...\n\n");
                break;

            case 3:
                if(flagA==1 && flagB==1)
                {
                    resultadoSuma = operacionSuma(operadorA, operadorB);
                    resultadoResta = operacionResta(operadorA, operadorB);

                    if(operadorB==0)
                    {
                        printf("\n\nNo es posible la division por cero (operador B=0)\n\n");
                        flagCalculosCargados=-1;
                    }
                    else
                        resultadoDiv = operacionDiv(operadorA, operadorB);

                    resultadoMult = operacionMult(operadorA, operadorB);

                    if(operacionFactorial(operadorA)==-1)
                        flagCalculosCargados=-1;
                    else
                        resultadoFactA = operacionFactorial(operadorA);

                    if(operacionFactorial(operadorB)==-1)
                        flagCalculosCargados=-1;
                    else
                        resultadoFactB = operacionFactorial(operadorB);

                    if(flagCalculosCargados==-1)
                        printf("\n\n ERROR, LOS OPERADORES DEBEN ESTAR CORRECTAMENTE CARGADOS\n\n");
                    else
                        printf("\n\n* CALCULOS REALIZADOS CORRECTAMENTE *\n\n");
                        flagCalculosCargados=1;
                }
                else
                    printf("\n\nERROR, LOS OPERADORES A y B DEBEN ESTAR CARGADOS\n\n");
                break;

            case 4:
                if(flagCalculosCargados==1)
                    mostrarInforme(resultadoSuma, resultadoResta, resultadoDiv,
                               resultadoMult, resultadoFactA, resultadoFactB);
                else
                    printf("\n\nERROR, PRIMERO SE DEBEN REALIZAR TODOS LOS CALCULOS\n\n");
                break;

            case 5:
                printf("\nSi desea salir pulse  n: ");
                fflush(stdin);
                scanf("%c", &auxRespuesta);
                if(auxRespuesta=='n')
                    respuesta = auxRespuesta;
                break;

            default:
                printf("\n\nIntentalo nuevamente... \n\n");
                break;
        }
        system("pause");
        system("cls");
    }while(respuesta=='s');

    return 0;
}
