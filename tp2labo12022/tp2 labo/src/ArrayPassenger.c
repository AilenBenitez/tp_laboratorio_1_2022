/*
 * ArrayPassenger.c
 *
 *  Created on: 08 may. 2022
 *      Author: Ailén
 */

#include "ArrayPassenger.h"
#include "input.h"

int initPassengers(Passenger* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0) // Valida que el array exista y no se encuentre vacio
	{
		status = TRUE; // Salió bien

		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE; // Establece cada "pasajero" como LIBRE
		}
	}

	return status;
}

int addPassengers(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger,char flycode[])
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL && price >= 0 && typePassenger > 0 && typePassenger < 6 && flycode != NULL) // Valida que el array exista Y no se encuentre vacio y que todos los datos sean llenados
	{
		for(i = 0; i < len; i++) // Recorre el array en busca de un espacio libre
		{
			if(list[i].isEmpty == TRUE) // Verifica sí el espacio se encuentra libre o no
			{
				list[i].isEmpty = FALSE;
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].flycode, flycode);
				status = TRUE; // Salió bien
				list[i].statusFlight = FALSE;
				break; // Una vez creado, deja de buscar y corta el bucle
			}
		}
	}

	return status;
}


int findPassengerById(Passenger* list, int len, int id)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				status = i;
			}
		}
	}

	return status;
}


int modifyPassenger(Passenger* list, int len, int id)
{
	int status = FALSE;
	int option;
	int idModify;

	if(list != NULL && len > 0 && id != FALSE)
	{

		idModify = findEmployeeById(list, len, id);

		puts("---------------------------------");
		puts("¿Que deseas modificar?");
		puts("1. Nombre");
		puts("2. Apellido");
		puts("3. precio");
		puts("4. tipo");
		puts("5. codigo de vuelo");
		puts("---------------------------------");
		ingresoIntMinMax(&option, "", "Error. Ingrese valor valido: ", 1, 5);

		if(idModify != FALSE)
		{
			switch(option)
			{
			case 1:
				ingresoCadena(list[idModify].name, 51, "Ingrese el nuevo nombre: ", "Error. Intente nuevamente: ");
				break;
			case 2:
				ingresoCadena(list[idModify].lastName, 51, "Ingrese el nuevo apellido: ", "Error. Intente nuevamente: ");
				break;
			case 3:
				list[idModify].price = ingresoFloat("Ingrese el nuevo precio: ", "Error. Intente nuevamente: ");
				while(list[idModify].price < 0)
				{
					list[idModify].price = ingresoFloat("el precio no puede ser negativo. Ingrese nuevamente: ", "Error. Intente nuevamente: ");
				}
				break;
			case 4:
				ingresoIntMinMax(&list[idModify].typePassenger, "Ingrese el nuevo tipo de pasajero(1 a 5): ", "Error. Ingrese un sector válido: ", 1, 5);
				break;
			}
			case 5:
				ingresoCadena(list[idModify].flycode, 51, "Ingrese el nuevo codigo de vuelo: ", "Error. Intente nuevamente: ");
				break;
			status = TRUE;
		}
	}

	return status;
}

int removePassenger(Passenger* list, int len, int id)
{
	int status = FALSE;
	int idModify;

	if(list != NULL && len > 0 && id != FALSE)
	{
		idModify = findPassengerById(list, len, id);

		if(idModify != FALSE)
		{
			list[idModify].isEmpty = TRUE;
			status = TRUE;
			list[idModify].statusFlight = TRUE;
		}
	}

	return status;
}

int sortPassengers(Passenger* list, int len, int orden)
{
	int status = FALSE;
	int i;
	int j;
	Passenger* listAux;

	printf("\n\nOrden establecido: %d\n\n", orden);

	if(list != NULL && len > 0)
	{
		status = TRUE;
		if(orden == 1)
		{

			for(i = 0; i < len; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].lastName,list[j].lastName) > 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
					{
						*listAux=list[i];
						list[i]=list[j];
						list[j]=*listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
						{
							if(list[i].typePassenger > list[j].typePassenger)
							{
								*listAux=list[i];
								list[i]=list[j];
								list[j]=*listAux;
							}
						}
					}
				}
			}
		}
		else
		{

			for(i = 0; i < len; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].lastName,list[j].lastName) < 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
					{
						printf("\n\nValidación 1\n\n");
						*listAux=list[i];
						list[i]=list[j];
						list[j]=*listAux;
					}
					else
					{
						if((strcmp(list[i].lastName,list[j].lastName) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE))
						{
							printf("\n\nValidación 2\n\n");
							if(list[i].typePassenger > list[j].typePassenger)
							{
								printf("\n\nValidación 3\n\n");
								*listAux=list[i];
								list[i]=list[j];
								list[j]=*listAux;
							}
						}
					}
				}
			}

		}
	}

	return status;
}

int printPassengers(Passenger* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		status = TRUE;
		puts("---------------------------------");
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("ID: %d || %s, %s || precio: %2.f || tipo: %d\n", list[i].id, list[i].lastName, list[i].name, list[i].price, list[i].typePassenger);
			}
		}
		puts("---------------------------------");
	}

	return status;
}


int promedioPassengers(Passenger* list, int len)
{
	int status = FALSE;
	int i;
	float acum = 0;
	int cont = 0;
	float prom;
	int contProm = 0;


	if(list != NULL && len > 0)
	{
		status = TRUE;
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				acum += list[i].price;
				cont++;
			}
		}

		prom = acum / cont;

		puts("---------------------------------");
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].price > prom)
			{
				printf("ID: %d || %s, %s || precio: %2.f || Sector: %d\n", list[i].id, list[i].lastName, list[i].name, list[i].price, list[i].typePassenger);
				contProm++;
			}
		}
		puts("---------------------------------");
		printf("Cantidad de empleados con un sueldo superior al promedio: %d\n", contProm);
		puts("---------------------------------");

	}

	return status;
}


int sortPassengersByCode(Passenger* list, int len,int orden){
int status = FALSE;
int i;
int j;
Passenger* listAux;

	printf("\n\nOrden establecido: %d\n\n", orden);

	if(list != NULL && len > 0 )
	{
		status = TRUE;
		if(orden == 1)
		{

			for(i = 0; i < len; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].flycode,list[j].flycode) > 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)&& (list[i].statusFlight == FALSE && list[j].statusFlight == FALSE))
					{
						*listAux=list[i];
						list[i]=list[j];
						list[j]=*listAux;
					}
					else
					{
						if((strcmp(list[i].flycode,list[j].flycode) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)&& (list[i].statusFlight == FALSE && list[j].statusFlight == FALSE))
						{

								*listAux=list[i];
								list[i]=list[j];
								list[j]=*listAux;
						}
					}
				}
			}
		}
		else
		{

			for(i = 0; i < len; i++)
			{
				for(j = i+1; j < len; j++)
				{
					if((strcmp(list[i].flycode,list[j].flycode) < 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)&& (list[i].statusFlight == FALSE && list[j].statusFlight == FALSE))
					{
						printf("\n\nValidación 1\n\n");
						*listAux=list[i];
						list[i]=list[j];
						list[j]=*listAux;
					}
					else
					{
						if((strcmp(list[i].flycode,list[j].flycode) == 0) && (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)&& (list[i].statusFlight == FALSE && list[j].statusFlight == FALSE))
						{
							printf("\n\nValidación 2\n\n");
								*listAux=list[i];
								list[i]=list[j];
								list[j]=*listAux;
						}
					}
				}
			}

		}
	}
return status;
}

