/*
 * menuGeneral.c
 *
 *  Created on: 08 may. 2022
 *      Author: Ailén
 */
#include "ArrayPassenger.h"
#include "input.h"

#define TRUE 0
#define FALSE -1
#define PASSENGERS 2000

/*
brief: Inicializa un contador y lo suma cuando se retorna la función
return: Int incrementado en uno
 */
static int getNewId(void)
{
	static int counter = 0;

	return(counter++);
}

/*
brief: Inicializa el menú de la aplicación
 */
void initMenu(void)
{

	int contPassengers = 0;
	int option;

	//Variables de usuario
	static int newId;
	static char newName[51];
	static char newLastName[51];
	static float newPrice;
	static int newTypePassenger;
	static char newFlyCode[10];

	//Variables de busqueda
	int idFounded;
	int order;

	Passenger passenger[PASSENGERS];

	initPassengers(passenger, PASSENGERS);

	do
	{
		//Muestra el menú
		puts("---------------------------------");
		puts("1. Dar de alta pasajero");
		puts("2. Modificar pasajero");
		puts("3. Dar de baja pasajero");
		puts("4. Informes");
		puts("5. Salir");
		puts("---------------------------------");

		fflush(stdin);
		ingresoIntMinMax(&option,"", "Error, ingrese un numero valido: " , 1, 5);

		switch(option)
		{
		case 1:

			if(contPassengers < PASSENGERS)
			{

				newId = getNewId();
				ingresoCadena(newName, 51, "Ingrese el nombre del pasajero: ", "Error. Ingrese nuevamente: ");
				ingresoCadena(newLastName, 51, "Ingrese el apellido el pasajero: ", "Error. Ingrese nuevamente: ");
				newPrice = ingresoFloat("Ingrese el precio del voleto: ", "Error. Ingrese un número válido: ");
				while(newPrice < 0)
				{
					newPrice = ingresoFloat("Ingrese un valor positivo: ", "Error. Ingrese un número válido: ");
				}
				ingresoIntMinMax(&newTypePassenger, "Ingrese el tipo de pasajero (1 a 5)", "Error. Ingrese un valor válido", 1, 5);

				if(addPassengers(passenger, PASSENGERS, newId, newName, newLastName, newPrice, newTypePassenger, newFlyCode) == FALSE)
				{
					puts("---------------------------------");
					puts("Error. ¡Algo salió mal!");
					puts("---------------------------------");
				}
				else
				{
					contPassengers++;
					puts("---------------------------------");
					puts("¡pasajero creado con éxito!");
					puts("---------------------------------");
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. ¡Límite de pasajeros alcanzado!");
				puts("---------------------------------");
			}

			break;
		case 2:
			if(contPassengers > 0)
			{
				if(printPassengers(passenger, PASSENGERS) != FALSE)
				{
					idFounded = ingresoInt("Ingrese el número de ID del pasajero a modificar: ", "Error. Ingrese un número valido: ");
					if(findPassengerById(passenger, PASSENGERS, idFounded) != FALSE)
					{
						if(modifyPassenger(passenger, PASSENGERS, idFounded) != FALSE)
						{
							puts("---------------------------------");
							puts("¡Pasajero modificado con éxito!");
							puts("---------------------------------");
						}
						else
						{
							puts("---------------------------------");
							puts("Error. ¡Algo salió mal!");
							puts("---------------------------------");
						}
					}
					else
					{
						puts("---------------------------------");
						puts("Error. ¡Pasajero no encontrado!");
						puts("---------------------------------");
					}
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. ¡No existen pasajeros. Debe existir al menos un pasajero para usar esta opción!");
				puts("---------------------------------");
			}


			break;
		case 3:
			if(contPassengers > 0)
			{
				if(printEmployees(passenger, PASSENGERS) != FALSE)
				{

					idFounded = ingresoInt("Ingrese el número de ID del pasajero a eliminar: ", "Error. Ingrese un número valido: ");
					if(findPassengerById(passenger, PASSENGERS, idFounded) != FALSE)
					{
						if(removePassenger(passenger, PASSENGERS, idFounded) != FALSE)
						{
							contPassengers--;
							puts("---------------------------------");
							puts("Error. ¡Pasajero eliminado con éxito!");
							puts("---------------------------------");
						}
						else
						{
							puts("---------------------------------");
							puts("Error. ¡Algo salió mal!");
							puts("---------------------------------");
						}
					}
					else
					{
						puts("---------------------------------");
						puts("Error. ¡Empleado no encontrado!");
						puts("---------------------------------");
					}
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. ¡No existen pasajeros. Debe existir al menos un pasajero para usar esta opción!");
				puts("---------------------------------");
			}

			break;
		case 4:
			if(contPassengers > 0)
			{
				puts("---------------------------------");
				puts("Ingrese el orden en el que quieres ordenar los pasajeros");
				puts("1. Ascendente");
				puts("2. Descendente");
				puts("---------------------------------");
				ingresoIntMinMax(&order, "", "Error. Ingrese un número válido: ", 1, 2);

				if(sortPassengers(passenger, PASSENGERS, order) != FALSE)
				{
					if(printPassengers(passenger, PASSENGERS) == FALSE)
					{
						puts("---------------------------------");
						puts("Error. ¡Algo salió mal!");
						puts("---------------------------------");
					}
					else
					{
						puts("¡Fin de la impresión!");
						puts("---------------------------------");
					}


				if(promedioEmployees(passenger, PASSENGERS) == FALSE)
				{
						puts("---------------------------------");
						puts("Error. ¡Algo salió mal!");
						puts("---------------------------------");
					}
					else
					{
						puts("¡Fin de la impresión!");
						puts("---------------------------------");
					}
				}
				else{
					puts("---------------------------------");
					puts("Error. ¡Algo salió mal!");
					puts("---------------------------------");
				}
			}
			if( sortPassengersByCode(passenger, PASSENGERS, order)!= FALSE)
			{
				if(printPassengers(passenger, PASSENGERS) == FALSE)
				{
					puts("---------------------------------");
					puts("Error. ¡Algo salió mal!");
					puts("---------------------------------");
					}
				else
				{
					puts("¡Fin de la impresión!");
					puts("---------------------------------");
					}
				}
			else
			{
				puts("---------------------------------");
				puts("Error. ¡No existen pasajeros. Debe existir al menos un pasajero para usar esta opción!");
				puts("---------------------------------");
			}

			break;
		case 5:
			puts("---------------------------------");
			puts("¡Aplicación cerrada con éxito!");
			puts("---------------------------------");
			break;
		}


	}while(option != 5);

}
