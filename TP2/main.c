#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"

int main()
{
    Employee employee[CANT_EMPLEADOS];
    int salir=0;
    int numID=1;
    int flag1=0;
    int indexEmployee;
    int idEmployee;

    if(initEmployees(employee, CANT_EMPLEADOS)==0)
        printf("Array de empleados inicializados\n\n");
    else
        printf("Error en inicializacion del array\n");

    do{
        system("cls");
        switch(menuConOpcion(3,1,5))
        {
            case 1:
                numID = getEmployeeID(employee, CANT_EMPLEADOS, numID);
                if(addEmployee(employee, CANT_EMPLEADOS, numID, employee->name, employee->lastName, employee->sector, employee->salary)==-1)
                    printf("\nError en el Alta del empleado\n");
                else
                {
                    printf("\nAlta Exitosa\n\n");
                    flag1=1;
                }
                break;

            case 2:
                system("cls");
                if(flag1==1 && getNumInt(&idEmployee, 3, 1, NUMMAX,
                                          "\n**MODIFICACION DE DATOS**\n\nIngrese el ID: ", "No existe el numero ingresado")==0)
                {
                    indexEmployee = findEmployeeById(employee, idEmployee, CANT_EMPLEADOS);
                    if(indexEmployee!=-1 && editEmployeeData(employee, indexEmployee, CANT_EMPLEADOS)==0)
                        printf("\n\nModificacion exitosa\n");
                    else
                        printf("\n\nError en la modificacion\n");
                }
                break;

            case 3:
                if(flag1==1 && getNumInt(&idEmployee, 3, 1, NUMMAX,"\n**BORRAR DATOS DE EMPLEADO**\n\nIngrese el ID: ", "No existe el numero ingresado")==0
                && removeEmployee(employee, idEmployee, CANT_EMPLEADOS)==0)
                    printf("Baja exitosa\n\n");
                else
                    printf("Error en la baja del empleado\n\n");
                break;

            case 4:
                if(flag1==1 && informesConOpciones(employee, CANT_EMPLEADOS, 3, 1, 2)==-1)
                    printf("\n\nError, intentelo mas tarde\n\n");
                break;

            case 5:
                salir=1;
                break;

            default:
                printf("\n\nError, intentelo mas tarde\n\n");
                break;
        }

    system("pause");
    }while(salir==0);

    return 0;
}
