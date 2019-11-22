#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* this;
    int retorno = ERROR;

    char buffer[4][30];

    int cant;

    //ESTO ES PARA LEER LA PRIMER FILA Q TIENE LA DESCRIPCION DEL STRUCT
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf(" %5s %15s %15s %9s\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            cant =  fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant < 4)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("Problemas para leer el archivo\n");
                    break;
                }
            }

            this = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            if(this!=NULL)
            {
                ll_add(pArrayListEmployee, this);
                contadorID();
            }
        }
        retorno = TODOOK;
    }
    return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = ERROR;
    int cant;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            Employee* this = employee_new();
            cant =  fread(this, sizeof(Employee), 1, pFile);

            if(cant < 1)
            {
                if(feof(pFile))
                {
                    retorno = TODOOK;
                    break;
                }
                else
                {
                    printf("Problemas para leer el archivo\n");
                    break;
                }
            }
            ll_add(pArrayListEmployee, this);
        }
    }
    return retorno;
}


/** \brief Guarda como texto un empleado en archivo de texto.
 * \param FILE* pFile
 * \param LinkedList* pArrayListEmployee
 * \return int TodoOK o Error
 */
int save_EmployeeToText(FILE* pFile,LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int i=0;
    int len, idAux, horasAux, sueldoAux;
    Employee* empleado;
    char nombreAux[50];

    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        retorno=TODOOK;
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        len=ll_len(pArrayListEmployee);
        do
        {
            empleado=(Employee*)ll_get(pArrayListEmployee,i);

            if(empleado!=NULL && employee_getNombre(empleado, nombreAux)==TODOOK
            && employee_getId(empleado,&idAux)==TODOOK
            && employee_getSueldo(empleado,&sueldoAux)==TODOOK
            && employee_getHorasTrabajadas(empleado,&horasAux)==TODOOK)
            {
                fprintf(pFile,"%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);
            }
            i++;
        }while(i<len);
    }
    return retorno;
}

/** \brief Guarda un empleado en archivo binario.
 * \param FILE* pFile
 * \param LinkedList* pArrayListEmployee
 * \return int TodoOK o Error
 */
int save_EmployeeToBin(FILE* pArchivo,LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int lenLinkedList;
    int i;
    Employee* pEmpleado;

    lenLinkedList = ll_len(pArrayListEmployee);

    if(pArchivo != NULL && pArrayListEmployee!= NULL)
    {
        retorno=TODOOK;

        for(i=0;i<lenLinkedList;i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            if(pEmpleado!= NULL)
                fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
        }
    }
    return retorno;
}
