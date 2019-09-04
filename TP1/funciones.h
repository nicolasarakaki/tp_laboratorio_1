#include <stdio.h>
#include <stdlib.h>
#define MAX 999999999999999999
#define MIN -9999999999999999


/** \brief Pide al usuario un numero del tipo flotante, entre un minimo y un maximo, y valida.
 *
 * \param pNumero *float    Almacena en el puntero de la variable el numero que se desea ingresar.
 * \param reintentos int    Limite de intentos de la peticion del numero.
 * \param minimo float      El numero minimo que se puede ingresar.
 * \param maximo float      El numero maximo que se puede ingresar.
 * \param mensaje *char     Mensaje de solicitud del numero.
 * \param error *char       Mensaje de error por no ingresar un numero del tipo flotante.
 * \return  int     Retorna -1 si esta mal, o 0 si esta OK.
 *
 */
int getNumFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error);


/** \brief Pide al usuario un numero del tipo entero, entre un minimo y un maximo, y valida.
 *
 * \param pNumero *int      Almacena en el puntero de la variable el numero que se desea ingresar.
 * \param reintentos int    Limite de intentos de la peticion del numero.
 * \param minimo int        El numero minimo que se puede ingresar.
 * \param maximo int        El numero maximo que se puede ingresar.
 * \param mensaje *char     Mensaje de solicitud del numero.
 * \param error *char       Mensaje de error por no ingresar un numero del tipo entero.
 * \return  int     Retorna -1 si esta mal, o 0 si esta OK.
 *
 */
int getNumInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error);


/** \brief Pide al usuario una opcion del menu, siendo el numero del tipo entero, entre un minimo y maximo, y lo valida.
 *
 * \param numero1 float     Valor de la variable que se visualizara al elegir e ingresar la opcion 1.
 * \param numero2 float     Valor de la variable que se visualizara al elegir e ingresar la opcion 2.
 * \param banderaA int      Bandera de estado para que, al ingresar el valor de la opcion 1, se vizualice A="numero1".
 * \param banderaB int      Bandera de estado para que, al ingresar el valor de la opcion 2, se vizualice B="numero2".
 * \return int      Retorna -1 si no existe la opcion ingresada, o si esta OK, retorna el numero de la opcion deseada.
 *
 */
int mostrarMenu(float numero1, float numero2, int banderaA, int banderaB);


/** \brief Muestra todos los resultados de las operaciones matematicas entre A y B.
 *
 * \param suma float                Variable del resultado de la suma entre A y B.
 * \param resta float               Variable del resultado de la resta entre A y B.
 * \param division float            Variable del resultado de la division entre A y B.
 * \param multiplicacion float      Variable del resultado de la multiplicacion entre A y B.
 * \param factorialA int            Variable del resultado del factorial de A.
 * \param factorialB int            Variable del resultado del factorial de B.
 * \return void
 *
 */
void mostrarInforme(float suma, float resta, float division, float multiplicacion, int factorialA, int factorialB);

