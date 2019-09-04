#include <stdio.h>
#include <stdlib.h>


/** \brief  Funcion para obtener la suma entre 2 valores.
 *
 * \param valor1 float  Parametro donde almacena el numero de la primer variable.
 * \param valor2 float  Parametro donde almacena el numero de la segunda variable.
 * \return float    Retorna el resultado de la suma entre los 2 valores.
 *
 */
float operacionSuma(float valor1, float valor2);


/** \brief  Funcion para obtener la resta entre 2 valores.
 *
 * \param valor1 float  Parametro donde almacena el numero de la primer variable.
 * \param valor2 float  Parametro donde almacena el numero de la segunda variable.
 * \return float    Retorna el resultado de la resta entre los 2 valores.
 *
 */
float operacionResta(float valor1, float valor2);


/** \brief  Funcion para obtener la division entre 2 valores.
 *
 * \param valor1 float  Parametro donde almacena el numero de la primer variable.
 * \param valor2 float  Parametro donde almacena el numero de la segunda variable.
 * \return float    Si el valor del segundo parametro es cero, avisa un error.
 *                  Sino, retorna el resultado de la division entre los 2 valores.
 *
 */
float operacionDiv(float valor1, float valor2);


/** \brief  Funcion para obtener la multiplicacion entre 2 valores.
 *
 * \param valor1 float  Parametro donde almacena el numero de la primer variable.
 * \param valor2 float  Parametro donde almacena el numero de la segunda variable.
 * \return float    Retorna el resultado de la multiplicacion entre los 2 valores.
 *
 */
float operacionMult(float valor1, float valor2);


/** \brief  Funcion para obtener el factorial del numero de la variable.
 *
 * \param valor1 float  Parametro donde almacena el numero de la variable.
 * \return int  Retorna -1 y con mensaje si no existe factorial del numero.
 *              Si existe, retorna el resultado del factorial del valor.
 *
 */
int operacionFactorial(float valor1);
