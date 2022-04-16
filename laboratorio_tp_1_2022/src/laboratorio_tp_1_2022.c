/*
 ============================================================================
 Name        : laboratorio_tp_1_2022.c
 Author      : Benitez, Ailen Rocio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(void)
{
    setbuf(stdout, NULL);
    int opcionMenuElegida;
    float kmIngresados;
    int opcionMenuDos;
    int flagKm=0;
    int flagPrecioAerolineas=0;
    int flagPrecioLatam=0;
    float precioDebitoAerolineas;
    float precioDebitoLatam;
    float precioCreditoAerolineas;
    float precioCreditoLatam;
    float precioBitcoinAerolineas;
    float precioBitcoinLatam;
    float precioUnitarioAerolineas;
    float precioUnitarioLatam;
    float diferenciaDePrecio;
    float precioAerolineas=0;
    float precioLatam=0;
    int cargaForzadaAerolineas=162965;
    int cargaForzadaLatam=159339;

    do
		{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("    Calculo de costos: vuelos de Latam y Aerolíneas Argentinas\n");
		printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
		printf("1. Ingresar Kilómetros: ( km=%d)\n",kmIngresados);
        printf("2. Ingresar Precio de Vuelos: (Aerolíneas=%d, Latam=%d)\n", precioAerolineas, precioLatam);
    	printf("3. Calcular todos los costos\n");
	    printf("4. Informar Resultados\n");
    	printf("5. Carga forzada de datos\n");
    	printf("6. Salir\n");
    	printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
		opcionMenuElegida=SeleccionarNumero();
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

			switch (opcionMenuElegida)
			{
				case 1:
					kmIngresados=IngresarNumero();
					flagKm=1;
					break;
				case 2:
					do{
					  printf("1. Precio vuelo Aerolíneas:\n" );
					  printf("2. Precio vuelo Latam:\n");
					  printf("3. Volver al menu principal.\n" );
					 opcionMenuDos=SeleccionarNumero();
					 switch(opcionMenuDos){
					     case 1:
					    precioAerolineas=IngresarPrecioAerolineas();
					    flagPrecioAerolineas=1;
					    break;
					    case 2:
					   precioLatam=IngresarPrecioLatam();
					    flagPrecioLatam=1;
					    break;
					 }
					}
					while(opcionMenuDos!=0||opcionMenuDos >=3);

					break;
				case 3:
				if(flagPrecioLatam==1 && flagPrecioAerolineas==1){
				    printf("calculando los siguientes puntos para Aerolineas y Latam\n");
			    	printf("a) Tarjeta de débito (descuento 10%)\n");
			        precioDebitoAerolineas=CalcularPreciodebito(precioAerolineas);
			        precioDebitoLatam=CalcularPreciodebito(precioLatam);
				    printf("b) Tarjeta de crédito (interés 25%)\n");
			    	precioCreditoAerolineas=CalcularPrecioCredito(precioAerolineas);
			    	precioCreditoLatam=CalcularPrecioCredito(precioLatam);
			    	printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
			    	precioBitcoinAerolineas= CalcularPrecioBitcoin(precioAerolineas);
			    	precioBitcoinLatam= CalcularPrecioBitcoin(precioLatam);
			    	if(flagKm==1){
			    	  printf("d) Mostrar precio por km (precio unitario)\n");
			    	  precioUnitarioAerolineas= CalcularPrecioUnitario(precioAerolineas);
			    	  precioUnitarioLatam= CalcularPrecioUnitario(precioLatam);
			    	}
			    	else{
			    	   printf("para realizar este calculo, primero ingrese los kms");
			    	}
			    	printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
					diferenciaDePrecio=CalcularDiferenciaDePrecio(precioLatam, precioAerolineas);
				}
				else{
				    printf("Por favor ingrese los precios antes de querer realizar los calculos");
				}
					break;

				case 4:
				if(flagPrecioLatam==1 && flagPrecioAerolineas==1){
				    printf("KMs Integrados: %f \n",kmIngresados);
				   	printf("Latam:%f\n",precioLatam);
					printf("    a) Precio con tarjeta de débito:%f \n",precioDebitoLatam);
					printf("	b) Precio con tarjeta de crédito:%f \n",precioCreditoLatam);
					printf("    c) Precio pagando con bitcoin :%f \n",precioBitcoinLatam);
					printf("    d) Precio unitario:%f \n",precioUnitarioLatam);
				    printf("Aerolíneas:%f\n",precioAerolineas);
					printf("    a) Precio con tarjeta de débito:%f \n",precioDebitoAerolineas);
					printf("	b) Precio con tarjeta de crédito:%f \n",precioCreditoAerolineas);
					printf("   c) Precio pagando con bitcoin :%f \n",precioBitcoinAerolineas);
				    printf("    d) Precio unitario:%f \n",precioUnitarioAerolineas);
					printf("   La diferencia de precio es:%f \n",diferenciaDePrecio);
				}
				else{
				    printf("Por favor ingrese los precios antes de querer realizar los calculos");
				}
					break;

				case 5:
				    printf("KMs Integrados:7090 \n");
				   	printf("Latam:%d \n",cargaForzadaLatam);
				    precioDebitoLatam=CalcularPreciodebito(cargaForzadaLatam);
					printf("    a) Precio con tarjeta de débito:%f \n",precioDebitoLatam);
				    precioCreditoLatam=CalcularPrecioCredito(cargaForzadaLatam);
					printf("	b) Precio con tarjeta de crédito:%f \n",precioCreditoLatam);
					precioBitcoinLatam= CalcularPrecioBitcoin(cargaForzadaLatam);
					printf("   c) Precio pagando con bitcoin:%f \n",precioBitcoinLatam);
					precioUnitarioLatam= CalcularPrecioUnitario(precioBitcoinLatam);
					printf("    d) Precio unitario:%f \n",precioUnitarioLatam);
				    printf("Aerolíneas:%d \n",cargaForzadaAerolineas);
                    precioDebitoAerolineas=CalcularPreciodebito(cargaForzadaAerolineas);
					printf("    a) Precio con tarjeta de débito: %f\n",precioDebitoAerolineas);
					precioCreditoAerolineas=CalcularPrecioCredito(cargaForzadaAerolineas);
    				printf("	b) Precio con tarjeta de crédito:%f \n",precioCreditoAerolineas);
					precioBitcoinAerolineas= CalcularPrecioBitcoin(cargaForzadaAerolineas);
					printf("   c) Precio pagando con bitcoin:%f \n",precioBitcoinAerolineas);
					precioUnitarioAerolineas= CalcularPrecioUnitario(cargaForzadaAerolineas);
				    printf("    d) Precio unitario:%f \n",precioUnitarioAerolineas);
				    diferenciaDePrecio=CalcularDiferenciaDePrecio(cargaForzadaAerolineas);
					printf("   La diferencia de precio es:%f \n",diferenciaDePrecio);
				break;

			}
		} while (opcionMenuElegida!=6);

	return EXIT_SUCCESS;
}



