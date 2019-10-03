#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"

int initEmployees(Employee* list, int len)
{
    int i;
    int retorno=-1;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty = TRUE;
        }
        retorno=0;
    }
    return retorno;
}

int findEmptyIndex(Employee* list, int len)
{
    int retorno=-1;
    int index;
    if(list!=NULL && len>0)
    {
        for(index=0;index<len;index++)
        {
            if(list[index].isEmpty==TRUE)
            {
                retorno = index;
                break;
            }
        }
    }
    return retorno;
}

int getEmployeeID(Employee* list, int len, int numId)
{
    int retorno=numId;
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FALSE && numId<=list[i].id)
        {
            numId = list[i].id;
            retorno = numId+1;
        }
    }
    return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], int sector, float salary)
{
    int retorno=-1;
    int index;
    Employee auxList;

    index = findEmptyIndex(list, len);
    if(list!=NULL && index>=0 && index<len)
    {
        if(getString(auxList.name, 51, 3, "\nEscriba el nombre: ", "Error, intente nuevamente\n") == 0
        && getString(auxList.lastName, 51, 3, "Escriba el apellido: ", "Error intente nuevamente\n") == 0
        && getNumInt(&auxList.sector, 3, 1, CANT_SECTORES, "Ingrese el numero de sector: ", "Error\n") == 0
        && getNumFloat(&auxList.salary, 3, 0.1, SALARIO_MAX, "Ingrese el salario: ", "Error\n") == 0)
        {
            list[index] = auxList;
            list[index].id = id;
            list[index].isEmpty = FALSE;
            retorno = 0;
        }
    }
    else
    {
        printf("\n\nNo hay mas espacio para guardar empleados");
    }
    return retorno;
}

int findEmployeeById(Employee* list, int id, int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FALSE && list[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    if(retorno==-1)
        printf("\n\nNo existe el ID buscado");
    return retorno;
}

int editEmployeeData(Employee* list, int index, int len)
{
    int retorno=-1;
    int opcion;
    int salir=0;
    Employee auxList;

    printf("\n\nID\tNOMBRE\t\tAPELLIDO\tSECTOR\tSALARIO\t\tINDEX\n");
    printEmployees(list, index, len);

    if(list!=NULL && index>=0 && index<len)
    {
        do{
            printf("\nQue desea modificar?:\n\n ");
            printf(" 1. Nombre\n ");
            printf(" 2. Apellido\n ");
            printf(" 3. Sector\n ");
            printf(" 4. Salario\n ");
            printf(" 5. Salir\n ");

            if(getNumInt(&opcion, 3, 1, 5, "\nElija una opcion: ", "Opcion Incorrecta")==0)
            {
                switch(opcion)
                {
                    case 1:
                        if(getString(auxList.name, 51, 3, "\nEscriba nuevo nombre: ", "Error, intente nuevamente ") == 0)
                        {
                            strcpy(list[index].name, auxList.name);
                            retorno = 0;
                        }
                        break;

                    case 2:
                        if(getString(auxList.lastName, 51, 3, "Escriba nuevo apellido: ", "Error intente nuevamente") == 0)
                        {
                            strcpy(list[index].lastName, auxList.lastName);
                            retorno = 0;
                        }
                        break;

                    case 3:
                        if(getNumInt(&auxList.sector, 3, 0, CANT_SECTORES, "Ingrese nuevo numero de sector: ", "Error\n") == 0)
                        {
                            list[index].sector = auxList.sector;
                            retorno = 0;
                        }
                        break;

                    case 4:
                        if(getNumFloat(&auxList.salary, 3, 0.1, SALARIO_MAX, "Ingrese nuevo salario: ", "Error\n") == 0)
                        {
                            list[index].salary = auxList.salary;
                            retorno = 0;
                        }
                        break;

                    case 5:
                        salir = 1;
                        retorno = 0;
                        break;

                    default:
                        printf("NO EXISTE LA OPCION, Intente nuevamente");
                }
            }
        }while(salir==0);
    }
    return retorno;
}

int removeEmployee(Employee* list, int id, int len)
{
    int retorno=-1;
    int index = findEmployeeById(list, id, len);
    if(index != -1)
    {
        list[index].isEmpty=TRUE;
        retorno=0;
    }
    return retorno;
}

int printEmployees(Employee* list, int index, int len)
{
    int retorno=-1;
    if(list!=NULL && index<len)
    {
        printf("%d\t%s\t\t%s\t\t%d\t$%.2f\t\t%d\n",
               list[index].id, list[index].name, list[index].lastName, list[index].sector, list[index].salary, index);
        retorno=0;
    }
    else
    {
        printf("Error al imprimir los datos de pantalla \n");
    }
    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    int retorno=-1;
    Employee auxlist;
    int i,j;
    if(list!=NULL)
    {
        for(i=0; i < len - 1; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                continue;
            }
            for(j=i+1; j < len; j++)
            {
                if(list[j].isEmpty == TRUE)
                {
                    continue;
                }
                if((order==0 && strcmp(list[j].lastName, list[i].lastName)<0)
                    || (order==1 && strcmp(list[j].lastName, list[i].lastName) > 0))
                {
                    auxlist = list[j];
                    list[j] = list[i];
                    list[i] = auxlist;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0)
                {
                    if((order==0 && list[j].sector < list[i].sector) || (order==1 && list[j].sector > list[i].sector))
                    {
                        auxlist = list[j];
                        list[j] = list[i];
                        list[i] = auxlist;
                    }
                }
            }
        }
    retorno = 0;
    }
    return retorno;
}

float getTotalSalary(Employee* list, int len)
{
    int retorno=-1;
    int i;
    float totalSalary=0;
    for(i=0;i < len; i++)
    {
        if(list[i].isEmpty == FALSE)
        {
            totalSalary = totalSalary + list[i].salary;
            retorno = totalSalary;
        }
    }
    return retorno;
}

float getAverageSalary(Employee* list, int len)
{
    int i;
    float totalSalary = 0;
    int activeEmployee = 0;

    for(i=0;i < len; i++)
    {
        if(list[i].isEmpty == FALSE)
        {
            totalSalary = totalSalary + list[i].salary;
            activeEmployee++;
        }
    }
    if(activeEmployee == 0)
    {
        return -1;
    }
    return (totalSalary / (float)activeEmployee);
}

int informesConOpciones(Employee* list, int len, int reintentos, int numOpcMin, int numOpcMax)
{
    int retorno=-1;
    int i;
    int opcion;
    int cantEmpleadosSuperaProm=0;
    float promSalarioTotal;
    float auxSalarioProm;
    float salarioTotal;
    float auxSalarioTotal;

    printf("**DATOS DE LOS EMPLEADOS**\n\n");
    printf("INFORME POR:\n\n");
    printf("1. Lista en orden alfabetico\n2. Total / promedio de salarios y Cant de empleados que superan el promedio");
    if(getNumInt(&opcion, reintentos, numOpcMin, numOpcMax, "\n\nIngrese la opcion: ", "No existe la opcion ingresada")==0)
    {
        switch(opcion)
        {
            case 1:
                if(sortEmployees(list, len, 0)==0)
                {
                    printf("\n\nID\tNOMBRE\t\tAPELLIDO\tSECTOR\tSALARIO\t\tINDEX\n");
                    for(i=0;i<len;i++)
                    {
                        if(list[i].isEmpty==FALSE)
                            printEmployees(list,i,len);
                    }
                }
                else
                    printf("\n\nNO HAY DATOS CARGADOS");
                retorno=0;
                break;

            case 2:
                auxSalarioTotal = getTotalSalary(list, len);
                if(auxSalarioTotal == -1)
                    printf("\nNO HAY SALARIOS");
                else
                {
                    salarioTotal = auxSalarioTotal;
                    printf("\nSALARIO TOTAL: $%.2f\n", salarioTotal);
                }
                auxSalarioProm = getAverageSalary(list, len);
                if(auxSalarioProm == -1)
                    printf("\nNO HAY PROMEDIO\n");
                else
                {
                    promSalarioTotal = auxSalarioProm;
                    printf("PROMEDIO DEL SALARIO TOTAL: $%.2f\n", promSalarioTotal);
                }
                for(i=0;i < len; i++)
                {
                    if(list[i].salary > promSalarioTotal && list[i].isEmpty == FALSE)
                        cantEmpleadosSuperaProm++;
                }
                printf("CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO DEL SALARIO: %d\n", cantEmpleadosSuperaProm);
                retorno=0;
                break;
        }
    }
    return retorno;
}
