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
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int salir = FALSE;
    int opcion;
    int flagDatosCargados=FALSE;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        system("cls");
        switch(menuConOpcion(3, 1, 10))
        {
            case 1:
                if(flagDatosCargados==TRUE)
                {
                    printf("\n\nSe borraran los datos que ya estan cargados en memoria.\nDesea continuar?:\n\n");
                    opcion = opciones(3, 1, 2);
                    if(opcion==1)
                    {
                        ll_clear(listaEmpleados);
                        flagDatosCargados = FALSE;
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
                    flagDatosCargados = TRUE;
                }
                break;

            case 2:
                if(flagDatosCargados==TRUE)
                {
                    printf("\n\nSe borraran los datos que ya estan cargados en memoria.\nDesea continuar?:\n\n");
                    opcion = opciones(3, 1, 2);
                    if(opcion==1)
                    {
                        ll_clear(listaEmpleados);
                        flagDatosCargados = FALSE;
                    }
                    else
                    {
                        printf("\n\nNo se realizo ninguna accion...\n\n");
                        break;
                    }
                }
                if(controller_loadFromBinary("data2.csv",listaEmpleados)==TODOOK)
                {
                    controller_ListEmployee(listaEmpleados);
                    printf("\n\nDatos cargados exitosamente...\n\n");
                    flagDatosCargados = TRUE;
                }
                break;

            case 3:
                printf("\n*** ALTA DEL EMPLEADO ***\n");
                if(controller_addEmployee(listaEmpleados)==TODOOK)
                {
                    printf("\n\nAlta de empleado cargado exitosamente...\n\n");
                    flagDatosCargados=TRUE;
                }
                break;

            case 4:
                printf("\n*** MODIFICACION DEL EMPLEADO ***\n");
                if(flagDatosCargados==TRUE)
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

            case 5:
                printf("\n*** BAJA DEL EMPLEADO ***\n");
                if(flagDatosCargados==TRUE)
                {
                    if(controller_removeEmployee(listaEmpleados)==ERROR)
                        printf("\nERROR EN LA BAJA DEL EMPLEADO...");
                }
                else
                {
                    printf("\n\nNo se encuentran datos cargados en la memoria...\n\n");
                }
                break;

            case 6:
                controller_ListEmployee(listaEmpleados);
                break;

            case 7:
                if(flagDatosCargados==TRUE)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("\n\nNo se encuentran datos cargados en la memoria...\n\n");
                }
                break;

            case 8:
                if(controller_saveAsText("data3.csv", listaEmpleados)==TODOOK)
                    printf("\n\nDatos guardados exitosamente...\n");
                break;

            case 9:
                if(controller_saveAsBinary("data2.csv", listaEmpleados)==TODOOK)
                    printf("\n\nDatos guardados exitosamente...\n");
                break;

            case 10:
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

