/*
 * funciones.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Ailén
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define funciones.c


///@brief pide un numero entre el 1 al 5 y lo retoma
///@param ingresa un entero
///@return el numero ingresado
int SeleccionarNumero();


/// @brief pide un numero (puede ser flotante o no) y lo retoma
/// @param ingresa un numero
/// @return el numero ingresado
float  IngresarNumero();

/// @brief pide un numero (puede ser flotante o no) y lo retoma
/// @param ingresa un numero
/// @return el numero ingresado
float IngresarPrecioAerolineas();

/// @brief pide un numero (puede ser flotante o no) y lo retoma
/// @param ingresa un numero
/// @return el numero ingresado
float IngresarPrecioLatam();

/// @brief realiza el descuento del 10% por abonar con debito
/// @param el precio ingresado
/// @return el precio final
float CalcularPreciodebito(float numeroIngresado);

/// @brief realiza el aumento del 25% por abonar con credito
/// @param  el precio ingresado
/// @return  el precio final
float CalcularPrecioCredito(float numeroIngresado);

/// @brief realiza la conversion de pesos a moneda bitcoin
/// @param el precio ingresado
/// @return el precio en moneda bitcoin
float CalcularPrecioBitcoin(float numeroIngresado);

/// @brief realiza el precio del km
/// @param los kms ingresados
/// @param el precio ingresado
/// @return el precio por km
float CalcularPrecioUnitario(float kmIngresado, float precioIngresado);

/// @brief realiza la diferencia entre los precios de las 2 aerolineas
/// @param precio de una empresa
/// @param precio de otra empresa
/// @return la diferencia
float CalcularDiferenciaDePrecio(float numeroIngresadoA, float numeroIngresadoB);







#endif /* FUNCIONES_H_ */
