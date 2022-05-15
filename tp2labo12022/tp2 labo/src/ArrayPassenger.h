/*
 * ArrayPassenger.h
 *
 *  Created on: 08 may. 2022
 *      Author: Ailén
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE 0
#define FALSE -1
#define EMPLOYEES 2000

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;


/*
brief: Recorre el array y establece todas las posiciones como isEmpty == TRUE (Libre)
param: Struct -> Passenger* list -Lista de Passengers
param: Int len -Longitud de la lista
return: 0 TRUE || -1 FALSE
 */
int initPassengers(Passenger* list, int len);

/*
brief: Recibe los parametros y crea un nuevo Passenger
param: Struct -> Passenger* list - Lista de Passengers
param: Int len - Longitud de la lista
param: Int id - ID del Passenger
param: Char name[] - Nombre del vPassenger
param: Char lastName[] - Apellido del Passenger
param: Float price - precio del vuelo
param: Int tipo - tipo de Passenger
return: 0 TRUE || -1 FALSE
 */
int addPassengers(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger,char flycode[]);
/*
brief: Recorre el array y busca la posición donde conincida el id a buscar con el id del Passenger
param: Struct -> Passenger* list - Lista de Passengers
param: Int len - Longitud de la lista
param: Int id - ID del Passenger a buscar
return: -1 FALSE || Posición del Passenger dentro del array
 */
int findPassengerById(Passenger* list, int len, int id);

/*
brief: Recorre el array y busca la posición donde conincida el id a buscar con el id del Passenger para modificarlo
param: Struct -> Passenger* list - Lista de Passengers
param: Int len - Longitud de la lista
param: Int id - ID del Passenger a modicar
return: -1 FALSE || 0 TRUE
 */
int modifyPassenger(Passenger* list, int len, int id);

/*
brief: Recorre el array y busca la posición donde conincida el id a buscar con el id del usuario para eliminarlo
param: Struct -> Passenger* list - Lista de Passengers
param: Int len - Longitud de la lista
param: Int id - ID del Passenger a eliminar
return: -1 FALSE || 0 TRUE
 */
int removePassenger(Passenger* list, int len, int id);

/*
brief: Recorre el array y lo ordena alfabeticamente
param: Struct -> Passenger* list - Lista de Passengers
param: Int len - Longitud de la lista
param: Int orden - Orden ascendente o descendente
return: -1 FALSE || 0 TRUE
 */
int sortPassengers(Passenger* list, int len, int order);

/*
brief: Recorre el array e imprime aquellos Passenger donde isEmpty == FALSE
param: Struct -> Passenger* list - Lista de Passengers
param: Int len - Longitud de la lista
return: -1 FALSE || 0 TRUE
 */
int printPassengers(Passenger* list, int length);

/*
brief: Recorre el array, acumula los precios y cuenta los Passengers. Cuenta cantidad de usuarios pasan el precio promedio y los imprime
param: Struct -> Passenger* list - Lista de empleados
param: Int len - Longitud de la lista
return: -1 FALSE || 0 TRUE
 */
int promedioPassengers(Passenger* list, int len);

/*
brief: Recorre el array y lo ordena por codigo de vuelo si el estado es activo
param: Struct -> Passenger* list - Lista de Passengers
param: Int len - Longitud de la lista
param: Int orden - Orden ascendente o descendente
return: -1 FALSE || 0 TRUE
 */
int sortPassengersByCode(Passenger* list, int len,int order);



#endif /* ARRAYPASSENGER_H_ */
