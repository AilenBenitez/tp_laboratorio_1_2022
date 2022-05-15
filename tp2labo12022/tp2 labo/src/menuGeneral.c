/*
 * menuGeneral.c
 *
 *  Created on: 08 may. 2022
 *      Author: Ail�n
 */
#include "ArrayPassenger.h"
#include "input.h"

#define TRUE 0
#define FALSE -1
#define PASSENGERS 2000

/*
brief: Inicializa un contador y lo suma cuando se retorna la funci�n
return: Int incrementado en uno
 */
static int getNewId(void)
{
	static int counter = 0;

	return(counter++);
}

/*
brief: Inicializa el men� de la aplicaci�n
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
		//Muestra el men�
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
				newPrice = ingresoFloat("Ingrese el precio del voleto: ", "Error. Ingrese un n�mero v�lido: ");
				while(newPrice < 0)
				{
					newPrice = ingresoFloat("Ingrese un valor positivo: ", "Error. Ingrese un n�mero v�lido: ");
				}
				ingresoIntMinMax(&newTypePassenger, "Ingrese el tipo de pasajero (1 a 5)", "Error. Ingrese un valor v�lido", 1, 5);

				if(addPassengers(passenger, PASSENGERS, newId, newName, newLastName, newPrice, newTypePassenger, newFlyCode) == FALSE)
				{
					puts("---------------------------------");
					puts("Error. �Algo sali� mal!");
					puts("---------------------------------");
				}
				else
				{
					contPassengers++;
					puts("---------------------------------");
					puts("�pasajero creado con �xito!");
					puts("---------------------------------");
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. �L�mite de pasajeros alcanzado!");
				puts("---------------------------------");
			}

			break;
		case 2:
			if(contPassengers > 0)
			{
				if(printPassengers(passenger, PASSENGERS) != FALSE)
				{
					idFounded = ingresoInt("Ingrese el n�mero de ID del pasajero a modificar: ", "Error. Ingrese un n�mero valido: ");
					if(findPassengerById(passenger, PASSENGERS, idFounded) != FALSE)
					{
						if(modifyPassenger(passenger, PASSENGERS, idFounded) != FALSE)
						{
							puts("---------------------------------");
							puts("�Pasajero modificado con �xito!");
							puts("---------------------------------");
						}
						else
						{
							puts("---------------------------------");
							puts("Error. �Algo sali� mal!");
							puts("---------------------------------");
						}
					}
					else
					{
						puts("---------------------------------");
						puts("Error. �Pasajero no encontrado!");
						puts("---------------------------------");
					}
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. �No existen pasajeros. Debe existir al menos un pasajero para usar esta opci�n!");
				puts("---------------------------------");
			}


			break;
		case 3:
			if(contPassengers > 0)
			{
				if(printEmployees(passenger, PASSENGERS) != FALSE)
				{

					idFounded = ingresoInt("Ingrese el n�mero de ID del pasajero a eliminar: ", "Error. Ingrese un n�mero valido: ");
					if(findPassengerById(passenger, PASSENGERS, idFounded) != FALSE)
					{
						if(removePassenger(passenger, PASSENGERS, idFounded) != FALSE)
						{
							contPassengers--;
							puts("---------------------------------");
							puts("Error. �Pasajero eliminado con �xito!");
							puts("---------------------------------");
						}
						else
						{
							puts("---------------------------------");
							puts("Error. �Algo sali� mal!");
							puts("---------------------------------");
						}
					}
					else
					{
						puts("---------------------------------");
						puts("Error. �Empleado no encontrado!");
						puts("---------------------------------");
					}
				}
			}
			else
			{
				puts("---------------------------------");
				puts("Error. �No existen pasajeros. Debe existir al menos un pasajero para usar esta opci�n!");
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
				ingresoIntMinMax(&order, "", "Error. Ingrese un n�mero v�lido: ", 1, 2);

				if(sortPassengers(passenger, PASSENGERS, order) != FALSE)
				{
					if(printPassengers(passenger, PASSENGERS) == FALSE)
					{
						puts("---------------------------------");
						puts("Error. �Algo sali� mal!");
						puts("---------------------------------");
					}
					else
					{
						puts("�Fin de la impresi�n!");
						puts("---------------------------------");
					}


				if(promedioEmployees(passenger, PASSENGERS) == FALSE)
				{
						puts("---------------------------------");
						puts("Error. �Algo sali� mal!");
						puts("---------------------------------");
					}
					else
					{
						puts("�Fin de la impresi�n!");
						puts("---------------------------------");
					}
				}
				else{
					puts("---------------------------------");
					puts("Error. �Algo sali� mal!");
					puts("---------------------------------");
				}
			}
			if( sortPassengersByCode(passenger, PASSENGERS, order)!= FALSE)
			{
				if(printPassengers(passenger, PASSENGERS) == FALSE)
				{
					puts("---------------------------------");
					puts("Error. �Algo sali� mal!");
					puts("---------------------------------");
					}
				else
				{
					puts("�Fin de la impresi�n!");
					puts("---------------------------------");
					}
				}
			else
			{
				puts("---------------------------------");
				puts("Error. �No existen pasajeros. Debe existir al menos un pasajero para usar esta opci�n!");
				puts("---------------------------------");
			}

			break;
		case 5:
			puts("---------------------------------");
			puts("�Aplicaci�n cerrada con �xito!");
			puts("---------------------------------");
			break;
		}


	}while(option != 5);

}
