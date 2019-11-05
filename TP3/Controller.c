#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    int parseo;

    file = fopen(path, "r");
    if(file==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    parseo = parser_EmployeeFromText(file, pArrayListEmployee);
    if(parseo!=TODOOK)
    {
        printf("\n\nSALIO MAL\n\n");
        return ERROR;
    }
    fclose(file);
    return TODOOK;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    int parseo;

    file = fopen(path, "rb");
    if(file==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    parseo = parser_EmployeeFromBinary(file, pArrayListEmployee);
    if(parseo==ERROR)
    {
        printf("\n\nSALIO MAL\n\n");
        return ERROR;
    }
    fclose(file);
    return TODOOK;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    Employee* this = employee_new();
    Employee auxEmp;

    if(pArrayListEmployee!=NULL && this!=NULL)
    {
        if(getString(auxEmp.nombre, 128, 3, "\nEscriba el nombre: ", "Error, intente nuevamente\n")==TODOOK
        && employee_setNombre(this, auxEmp.nombre)==TODOOK

        && getNumInt(&auxEmp.horasTrabajadas, 3, 0, 100000, "Ingrese la cantidad de horas trabajadas: ", "Error\n")==TODOOK
        && employee_setHorasTrabajadas(this, auxEmp.horasTrabajadas)==TODOOK

        && getNumInt(&auxEmp.sueldo, 3, 0, 100000, "Ingrese el salario: ", "Error\n")==TODOOK
        && employee_setSueldo(this, auxEmp.sueldo)==TODOOK)
        {
            auxEmp.id = contadorID();
            employee_setId(this, auxEmp.id);
            if(this != NULL)
            {
                ll_add(pArrayListEmployee, this);
                retorno = TODOOK;
            }
        }
        else
        {
            printf("\n\nError en el alta de Empleado");
        }
    }
    else
    {
        printf("\n\nError en el espacio de la memoria");
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int i;
    int id;
    int len = ll_len(pArrayListEmployee);
    int flagOk=0;
    int opcion=-1;
    int salir=FALSE;
    Employee* this;
    Employee auxEmp;

    if(pArrayListEmployee!=NULL && len>=0)
    {
        if(controller_ListEmployee(pArrayListEmployee)==TODOOK
        && getNumInt(&id, 3, 0, 5000, "\n\nIngrese el numero de ID: ", "\nError")==TODOOK)
        {
            for(i=0;i<len;i++)
            {
                this = (Employee*)ll_get(pArrayListEmployee, i);
                if(this!=NULL && this->id==id)
                {
                    flagOk=1;
                    break;
                }
            }
            if(flagOk==1)
            {
                do
                {
                    system("cls");
                    printf("\nID    Nombre    Horas Trabajadas  Sueldo");
                    printf("\n--    ------    ----------------  ------");
                    printf("\n%2d%10s%12d hs%12d", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
                    printf("\n\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\n");
                    if(getNumInt(&opcion, 3, 1, 4,"\nIngrese la opcion a modificar: ", "\nError")==TODOOK)
                    {
                        switch(opcion)
                        {
                            case 1:
                                if(getString(auxEmp.nombre, 128, 3, "\nEscriba el nombre: ", "Error, intente nuevamente\n")==TODOOK
                                && employee_setNombre(this, auxEmp.nombre)==TODOOK)
                                {
                                    printf("\nNombre modificado...");
                                }
                                break;

                            case 2:
                                if(getNumInt(&auxEmp.horasTrabajadas, 3, 0, 100000, "Ingrese la cantidad de horas trabajadas: ", "Error\n")==TODOOK
                                && employee_setHorasTrabajadas(this, auxEmp.horasTrabajadas)==TODOOK)
                                {
                                    printf("\nHoras Trabajadas modificado...");
                                }
                                break;

                            case 3:
                                if(getNumInt(&auxEmp.sueldo, 3, 0, 100000, "Ingrese el salario: ", "Error\n")==TODOOK
                                && employee_setSueldo(this, auxEmp.sueldo)==TODOOK)
                                {
                                    printf("\nSueldo modificado...");
                                }
                                break;

                            case 4:
                                retorno = TODOOK;
                                salir = TRUE;
                                break;
                        }
                    }
                    else
                    {
                        printf("\nNo se realizara ningun cambio...");
                        salir = TRUE;
                    }
                    printf("\n\n");
                    system("pause");
                }while(salir==FALSE);
            }
            else
            {
                printf("\n\nNo se encuentra el ID buscado...");
            }
        }
    }
    else
    {
        printf("\n\nError en el espacio de la memoria");
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int i, id;
    int flagOk = 0;
    int len = ll_len(pArrayListEmployee);
    Employee* this;

    if(pArrayListEmployee!=NULL && len>=0)
    {
        if(controller_ListEmployee(pArrayListEmployee)==TODOOK
        && getNumInt(&id, 3, 0, 5000, "\n\nIngrese el numero de ID: ", "\nError")==TODOOK)
        {
            for(i=0;i<len;i++)
            {
                this = (Employee*)ll_get(pArrayListEmployee, i);
                if(this!=NULL && this->id==id)
                {
                    flagOk=1;
                    break;
                }
            }
            if(flagOk==1)
            {
                system("cls");
                printf("\nID    Nombre    Horas Trabajadas  Sueldo");
                printf("\n--    ------    ----------------  ------");
                printf("\n%2d%10s%12d hs%12d", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
                printf("\n\nSeguro de desea eliminarlo?\n");
                switch(opciones(3, 1, 2))
                {
                    case 1:
                        ll_remove(pArrayListEmployee, i);
                        printf("\nEmpleado Eliminado...");
                        retorno = TODOOK;
                        break;

                    case 2:
                        printf("\nNo se realizara ningun cambio...");
                        retorno = TODOOK;
                        break;
                }
            }
            else
            {
                printf("\n\nNo se encuentra el ID buscado...");
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = ERROR;
    int len = ll_len(pArrayListEmployee);
    int i;
    Employee* empleado;

    if(pArrayListEmployee!=NULL && len>=0)
    {
        printf("\nID    Nombre    Horas Trabajadas  Sueldo");
        printf("\n--    ------    ----------------  ------");
        for(i=0;i<len;i++)
        {
            empleado = (Employee*)ll_get(pArrayListEmployee, i);
            if(empleado!=NULL)
                printf("\n%2d%10s%12d hs%12d", (empleado)->id, (empleado)->nombre, (empleado)->horasTrabajadas, (empleado)->sueldo);
        }
        retorno = TODOOK;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int orden, num;

    if(pArrayListEmployee!=NULL)
    {
        printf("\nORDENAR:\n\n1.Ascendente\n2.Descendente");
        if(getNumInt(&num, 3, 1, 2, "\n\nIngrese una opcion: ", "\n\nError")==TODOOK)
        {
            if(num==1)
                orden=1;
            if(num==2)
                orden=0;

            ll_sort(pArrayListEmployee, compararXNombre, orden);
            retorno=TODOOK;
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE*pArchivo;
    int retorno=ERROR;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo=fopen(path,"w");
        if(pArchivo != NULL)
        {
            retorno=save_EmployeeToText(pArchivo,pArrayListEmployee);
            fclose(pArchivo);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    FILE *pArchivo;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pArchivo=fopen(path, "wb");
        if(pArchivo!=NULL && save_EmployeeToBin(pArchivo, pArrayListEmployee)==TODOOK)
        {
            retorno=TODOOK;
            fclose(pArchivo);
        }
    }
    fclose(pArchivo);

    return retorno;
}

/** \brief Decide el criterio para posterior ordenamiento.
 * \param void* this1 Empleado 1
 * \param void* this2 Empleado 2
 * \return int
 */
int compararXNombre(void* this1, void* this2)
{
    char nombre1[100], nombre2[100];
    int retorno=0;

    employee_getNombre(this1,nombre1);
    employee_getNombre(this2,nombre2);

    if(strcmp(nombre1,nombre2)<0)
        retorno=-1;
    else if(strcmp(nombre1,nombre2)>0)
        retorno=1;

    return retorno;
}
