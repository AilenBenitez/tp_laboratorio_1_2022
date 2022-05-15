/*
 * input.h
 *
 *  Created on: 14 may. 2022
 *      Author: Ailén
 */

#ifndef INPUT_H_
#define INPUT_H_


// VALIDACIONES

/*
/////////////////////////////////////////////////////////////////////
brief:pide cadena de caracteres ingresada para validar un numero entero
param: se pide un tipo char
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarEntero(char *pIngreso);
/*
/////////////////////////////////////////////////////////////////////
brief: pide cadena de caracteres ingresada para validar un numero flotante
param: se pide un tipo char
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarFlotante(char *pIngreso);
/*
/////////////////////////////////////////////////////////////////////
brief: pide un char ingresado para validar si es char
param: se pide un tipo char
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarCaracter(char ingreso);
/*
/////////////////////////////////////////////////////////////////////
brief: pide cadena de caracteres ingresada para validar sí es alfabética
param: pide un tipo char
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int validarCadena(char *pIngreso);

// INGRESOS SIN REINTENTOS

/*
/////////////////////////////////////////////////////////////////////
brief: pide un mensaje y  mensaje de error
param: pide un char, se valida sí es un int o no
return: int que refiere al numero ingresado
/////////////////////////////////////////////////////////////////////
*/
int ingresoInt(char* message, char* errorText);
/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un mensaje y mensaje de error
param: pide un char, se valida sí es un float o no
return: float que refiere al numero ingresado
/////////////////////////////////////////////////////////////////////
*/
float ingresoFloat(char* message, char* errorText);

/*
/////////////////////////////////////////////////////////////////////
brief:pide unmensaje y mensaje de error
param: pide un char, se valida sí es un char o no.
return: char que refiere al caracter ingresado
/////////////////////////////////////////////////////////////////////
*/
char ingresoChar(char* message, char* errorText);
/*
/////////////////////////////////////////////////////////////////////
brief: pide un array de cadena de texto, la longitud de la cadena ,un mensaje y mensaje de error
param: pide una cadena de texto, se valida sí es una cadena o no.
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoCadena(char pIngreso[],int len, char* message, char* errorText);

// INGRESOS CON REINTENTOS

/*
/////////////////////////////////////////////////////////////////////
brief:  pide un array de enteros, un mensaje y mensaje de error, cantidad de intentos
param:  pide un entero, se valida sí es un entero o no.
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoIntRetry(int* pIngreso, char* message, char* errorText, int retry);

/*
/////////////////////////////////////////////////////////////////////
brief: pide un array de float, unmensaje y un mensaje de error, cantidad de intentos
param: pide un flotante, se valida sí es un flotante o no.
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoFloatRetry(float* pIngreso, char* message, char* errorText, int retry);

/*
/////////////////////////////////////////////////////////////////////
brief: pide un array de char, un mensaje, un mensaje de error, cantidad de intentos
param: pide un caracter, se valida sí es un char o no.
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoCharRetry(char* pIngreso, char* message, char* errorText,int retry);
/*
/////////////////////////////////////////////////////////////////////
brief:pide un array para cadena de texto, el tamaño de la cadena, un mensaje, un mensaje de error, y cantidad de intentos
param: pide una cadena de texto, se valida sí es una cadena o no.
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoTextoRetry(char pIngreso[],int len, char* message, char* errorText, int retry);

// INGRESOS CON MIN Y MAX

/*
/////////////////////////////////////////////////////////////////////
brief: pide un entero, un mensaje,un mensaje de error,minimo y maximo, y cantidad de intentos
param:pide un int, se valida sí es un entero o no y si esta dentro de los parametros min y max.
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoIntMinMax(int* pIngreso, char* message, char* errorText, int min, int max);

/*
/////////////////////////////////////////////////////////////////////
brief:pide un flotante, un mensaje, mensaje de error,minimo y maximo, cantidad de intentos
param: pide un int, se valida sí es un flotante o no y si esta dentro de ls parametros min y max. En caso de que no, se vuelve a pedir la cantidad de veces mientras no supere los intentos y sino se retorna el status
return: int que refiere al estado TRUE = 1 || FALSE = 0
/////////////////////////////////////////////////////////////////////
*/
int ingresoFloatMinMax(float* pIngreso, char* message, char* errorText, float min, float max);


#endif /* INPUT_H_ */
