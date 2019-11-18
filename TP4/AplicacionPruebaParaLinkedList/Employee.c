#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "validaciones.h"



int employee_setId(Employee* this,int id)
{

    int todoOk = ERROR;

    if( this != NULL && id > 0)
    {
        this->id = id;
        todoOk = TODOOK;
    }

    return todoOk;
}


int employee_getId(Employee* this,int* id)
{

    int todoOk = ERROR;

    if( this != NULL && id != NULL )
    {
        *id = this->id;
        todoOk = TODOOK;
    }
    return todoOk;
}


int employee_setNombre(Employee* this, char* nombre)
{

    int todoOk = ERROR;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = TODOOK;
    }

    return todoOk;

}

int employee_getNombre(Employee* this, char* nombre)
{

    int todoOk = ERROR;

    if( this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = TODOOK;
    }

    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = ERROR;

    if( this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = TODOOK;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int todoOk = ERROR;

    if( this != NULL && horasTrabajadas != NULL )
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = TODOOK;
    }
    return todoOk;

}

int employee_setSueldo(Employee* this,int sueldo)
{

    int todoOk = ERROR;

    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = TODOOK;
    }

    return todoOk;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = ERROR;

    if( this != NULL && sueldo != NULL )
    {
        *sueldo = this->sueldo;
        todoOk = TODOOK;
    }
    return todoOk;
}

Employee* employee_new()
{

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this;

        if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
        {
            this  = employee_new();
            if(this != NULL)
            {

                if(employee_setId(this, atoi(idStr))==ERROR
                || employee_setNombre(this, nombreStr)==ERROR
                || employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr))==ERROR
                || employee_setSueldo(this, atoi(sueldoStr))==ERROR)
                {
                    free(this);
                    this = NULL;
                }
            }
        }
    return this;
}

void mostrarEmpleado(Employee* emp)
{
    if(emp != NULL)
    {
        printf("%d  %s  %d  %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }
}


int ordenarXSueldo( void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if( emp1 != NULL && emp2 != NULL)
    {
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if( p1->sueldo > p2-> sueldo)
        {
            retorno = 1;
        }
        else if( p1->sueldo < p2-> sueldo)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int ordenarXHoras( void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if( emp1 != NULL && emp2 != NULL)
    {

        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if( p1->horasTrabajadas > p2->horasTrabajadas)
        {
            retorno = 1;
        }
        else if( p1->horasTrabajadas < p2->horasTrabajadas)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int ordenarXNombre(void* emp1, void* emp2)
{
    char nombre1[100], nombre2[100];
    int i;
    int retorno=0;

    employee_getNombre(emp1,nombre1);
    employee_getNombre(emp2,nombre2);

    for(i=0; nombre1[i]!='\0'; i++)
    {
        nombre1[i] = toupper(nombre1[i]);
    }

    for(i=0; nombre2[i]!='\0'; i++)
    {
        nombre2[i] = toupper(nombre2[i]);
    }

    if(strcmp(nombre1,nombre2)<0)
        retorno=-1;
    else if(strcmp(nombre1,nombre2)>0)
        retorno=1;

    return retorno;
}

int menuConOpcion(int reintentos, int numOpcMin, int numOpcMax)
{
    int opcion;
    int auxOpcion;

    printf("\n -*- MENU DE OPCIONES -*-\n\n ");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n ");
    printf(" 2. Alta de empleado\n ");
    printf(" 3. Modificar datos de empleado\n ");
    printf(" 4. Baja de empleado\n ");
    printf(" 5. Listar empleados\n ");
    printf(" 6. Ordenar empleados\n ");
    printf(" 7. Guardar los datos de los empleados en el archivo data2.csv (modo texto)\n ");
    printf(" 8. Borrar lista de la memoria\n ");
    printf(" 9. Salir\n ");

    fflush(stdin);
    if(getNumInt(&auxOpcion, reintentos, numOpcMin, numOpcMax, "\n\nIngrese una opcion: ", "Opcion Incorrecta")==0)
        opcion = auxOpcion;
    else
        opcion = -1;

    return opcion;
}

int opciones(int reintentos, int numOpcMin, int numOpcMax)
{
    int opcion;
    int auxOpcion;

    printf("    1. Si\n");
    printf("    2. No\n");

    fflush(stdin);
    if(getNumInt(&auxOpcion, reintentos, numOpcMin, numOpcMax, "\n\nIngrese una opcion: ", "Opcion Incorrecta")==0)
        opcion = auxOpcion;
    else
        opcion = -1;

    return opcion;
}

int contadorID(void)
{
    static int id=0;
    id++;
    int retorno = id;

    return retorno;
}
