#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Alta de empleado
     3. Modificar datos de empleado
     4. Baja de empleado
     5. Listar empleados
     6. Ordenar empleados
     7. Guardar los datos de los empleados en el archivo data2.csv (modo texto).
     8. Borrar lista de la memoria.
     9. Salir
*****************************************************/


int main()
{
    int salir = FALSE;
    int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = ll_newLinkedList();
    LinkedList* listaEmpleados3 = ll_newLinkedList();
    LinkedList* listaEmpleados4 = ll_newLinkedList();
    void* pElemento;

    do{
        system("cls");
        switch(menuConOpcion(3, 1, 14))
        {
            case 1:
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    printf("\n\nSe borraran los datos que ya estan cargados en memoria.\nDesea continuar?:\n\n");
                    opcion = opciones(3, 1, 2);
                    if(opcion==1)
                    {
                        ll_clear(listaEmpleados);
                    }
                    else
                    {
                        printf("\n\nNo se realizo ninguna accion...\n\n");
                        break;
                    }
                }
                if(controller_loadFromText("data.csv",listaEmpleados)==TODOOK)
                {
                    controller_ListEmployee(listaEmpleados);
                    printf("\n\nDatos cargados exitosamente...\n\n");
                }
                break;

            case 2:
                printf("\n*** ALTA DEL EMPLEADO ***\n");
                if(controller_addEmployee(listaEmpleados)==TODOOK)
                {
                    printf("\n\nAlta de empleado cargado exitosamente...\n\n");
                }
                break;

            case 3:
                printf("\n*** MODIFICACION DEL EMPLEADO ***\n");
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    if(controller_editEmployee(listaEmpleados)==ERROR)
                        printf("\nERROR EN LA MODIFICACION DEL EMPLEADO...");
                    else
                        printf("\n\nModificacion exitosa...\n\n");
                }
                else
                {
                    printf("\n\nNo se encuentran datos cargados en la memoria...\n\n");
                }
                break;

            case 4:
                printf("\n*** BAJA DEL EMPLEADO ***\n");
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    if(controller_removeEmployee(listaEmpleados)==ERROR)
                        printf("\nERROR EN LA BAJA DEL EMPLEADO...");
                }
                else
                {
                    printf("\n\nNo se encuentran datos cargados en la memoria...\n\n");
                }
                break;

            case 5:
                controller_ListEmployee(listaEmpleados);
                break;

            case 6:
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("\n\nNo se encuentran datos cargados en la memoria...\n\n");
                }
                break;

            case 7:
                if(controller_saveAsText("data2.csv", listaEmpleados)==TODOOK)
                    printf("\n\nDatos guardados exitosamente...\n");
                break;

            case 8:
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    printf("\nEsta seguro?\n");
                    switch(opciones(3, 1, 2))
                    {
                        case 1:
                            ll_clear(listaEmpleados);
                            printf("\n\nLista en memoria BORRADA...\n\n");
                            break;

                        case 2:
                            printf("\n\nNo se realizo ninguna accion...\n\n");
                            break;
                    }
                }
                else
                {
                    printf("\n\nNo hay datos cargados en la memoria...\n\n");
                }
                break;

            case 9:
                listaEmpleados2 = ll_clone(listaEmpleados);
                pElemento = ll_get(listaEmpleados, 6);
                if(listaEmpleados2!=NULL && ll_contains(listaEmpleados2, pElemento)==1)
                {
                    printf("\nll_clone y ll_contains funcionan correctamente\n");
                }
                else
                    printf("\nError\n");
                break;

            case 10:
                listaEmpleados3 = ll_clone(listaEmpleados);
                if(listaEmpleados3!=NULL && ll_containsAll(listaEmpleados, listaEmpleados3)==1)
                {
                    printf("\nll_clone y ll_containsAll funcionan correctamente\n");
                }
                break;

            case 11:
                listaEmpleados4 = ll_subList(listaEmpleados, 0, 5);
                if(listaEmpleados4!=NULL)
                {
                    controller_ListEmployee(listaEmpleados4);
                }
                break;

            case 12:
                printf("\nSe le agrega el elemento de la posicion 10 de la SubLista a la posicion 3 de una lista nueva\n");

                pElemento = ll_get(listaEmpleados, 10);
                if(ll_push(listaEmpleados4, 3, pElemento)==TODOOK)
                {
                    controller_ListEmployee(listaEmpleados4);
                }
                break;

            case 13:
                printf("\nSe elimina el elemento de la posicion 3 de la SubLista y se imprime solamente el elemento eliminado\n");

                pElemento = ll_pop(listaEmpleados4, 3);
                printf("\nID    Nombre    Horas Trabajadas  Sueldo");
                printf("\n--    ------    ----------------  ------");
                mostrarEmpleado((Employee*)pElemento);
                break;

            case 14:
                printf("\nSALIENDO....");
                salir = TRUE;
                break;
        }
        printf("\n\n");
        system("pause");
    }while(salir == FALSE);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
