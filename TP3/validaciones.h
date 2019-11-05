#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


/** \brief
 *  Funcion para obtener una cadena de caracteres (solo letras) por teclado con mensajes al usuario.
 *  \param pNombre char*    Direccion de memoria a almacenar la cadena ingresada por teclado.
 *  \param limite int       Longitud del array de caracteres a ingresar por teclado.
 *  \param reintentos int   Cantidad de reintentos al usuario.
 *  \param mensaje char*    Mensaje personalizado que solicita el dato al usuario.
 *  \param error char*      Mensaje personalizado en caso de error.
 *  \return         Retorna 0 si obtuvo la cadena correctamente y -1 si hubo un error.
 *
 */
int getString(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError);


/** \brief
 *  Funcion para obtener una cadena de caracteres (letras y numeros) por teclado con mensajes al usuario.
 *  \param pNombre char*    Direccion de memoria a almacenar la cadena ingresada por teclado.
 *  \param limite int       Longitud del array de caracteres a ingresar por teclado.
 *  \param reintentos int   Cantidad de reintentos al usuario.
 *  \param mensaje char*    Mensaje personalizado que solicita el dato al usuario.
 *  \param error char*      Mensaje personalizado en caso de error.
 *  \return         Retorna 0 si obtuvo la cadena correctamente y -1 si hubo un error.
 *
 */
int getStringAlfaNum(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError);

#endif // VALIDACIONES_H_INCLUDED
