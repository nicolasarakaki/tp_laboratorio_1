#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define TRUE 1
#define FALSE 0

#define ERROR -1
#define TODOOK 0

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void mostrarEmpleado(Employee* emp);
int ordenarXSueldo( void* emp1, void* emp2);
int ordenarXHoras( void* emp1, void* emp2);

int menuConOpcion(int reintentos, int numOpcMin, int numOpcMax);
int opciones(int reintentos, int numOpcMin, int numOpcMax);
int contadorID(void);

#endif // employee_H_INCLUDED
