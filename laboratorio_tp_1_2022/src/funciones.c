/*
 * funciones.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Ailén
 */

#define funciones.h

int SeleccionarNumero(){
	int opcionMenuElegida;
	printf("Elija una opcion: ");
	scanf("%d", &opcionMenuElegida);
	while(opcionMenuElegida<1||opcionMenuElegida>5){
	printf("ERROR! Elija una opcion entre las que figuran en el menu: ");
	scanf("%d", &opcionMenuElegida);
	}
	return opcionMenuElegida;
}

float IngresarNumero(){
	float numeroIngresado;
	printf("usted eligió la opción 1.\n");
	printf("ingrese el la cantidad de kilometros:\n");
	scanf("%f", &numeroIngresado);
	while(numeroIngresado<0){
		printf("por favor, solo ingrese numeros positivos:");
		scanf("%f", &numeroIngresado);
	}
	return numeroIngresado;
}
float IngresarPrecioAerolineas(){
	float numeroIngresado;
	printf("Precio Aerolineas:\n");
	scanf("%f", &numeroIngresado);
	while(numeroIngresado<0){
		printf("por favor, solo ingrese numeros positivos:");
		scanf("%f", &numeroIngresado);
		}
	return numeroIngresado;
}

float IngresarPrecioLatam(){
	float numeroIngresado;
	printf("Precio Latam:\n");
	scanf("%f", &numeroIngresado);
	while(numeroIngresado<0){
	   printf("por favor, solo ingrese numeros positivos:");
	   scanf("%f", &numeroIngresado);
		}
	return numeroIngresado;
}

float CalcularPreciodebito(float numeroIngresado){
    float descuento;
    float precioFinal;
    descuento= numeroIngresado * (10 / 100);
    precioFinal = numeroIngresado - descuento;
    return precioFinal ;
}
float CalcularPrecioCredito(float numeroIngresado){
    float aumento;
    float precioFinal;
    aumento = numeroIngresado * (25 / 100);
    precioFinal = numeroIngresado + aumento;
    return precioFinal;
}
float CalcularPrecioBitcoin(float numeroIngresado){
    float precioFinal;
    float btc;
    btc=4606954.55;
    precioFinal=numeroIngresado/4606954.55;
    return precioFinal;
}
float CalcularPrecioUnitario(float kmIngresado, float precioIngresado){
    float precioFinal;
    precioFinal= precioIngresado/kmIngresado;
    return precioFinal;
}
float CalcularDiferenciaDePrecio(float numeroIngresadoA, float numeroIngresadoB){
    float precioFinal;
    if (numeroIngresadoA >numeroIngresadoB){
        precioFinal=numeroIngresadoA-numeroIngresadoB;
    }
    else{
        precioFinal=numeroIngresadoB-numeroIngresadoA;
    }
    return precioFinal;
}
